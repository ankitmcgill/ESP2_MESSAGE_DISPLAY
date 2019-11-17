///////////////////////////////////////////////////////////////
//ESP32 MESSAGE DISPLAY
//
//INTERNAL - WEBSERVER
//

//NOVEMBER 4 2019
///////////////////////////////////////////////////////////////

#include "esp_system.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_http_server.h"
#include "sys/param.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"

#include "internal_webserver.h"
#include "internal_spiffs.h"
#include "internal_mdns.h"
#include "global.h"

//Internal Variables
static httpd_handle_t s_internal_webserver_handle;

//Internal Functions
static httpd_handle_t s_internal_webserver_start(void);
static esp_err_t s_internal_webserver_handler_get(httpd_req_t* req);
static esp_err_t s_internal_webserver_handler_post(httpd_req_t* req);

void INTERNAL_WEBSERVER_Init(void)
{
    //Initialize INTERNAL WEBSERVER

    s_internal_webserver_handle = s_internal_webserver_start();
    
    if(s_internal_webserver_handle == NULL)
    {
        ESP_LOGE(INTERNAL_WEBSERVER_TAG, "cannot start webserver");
        return;
    }

    INTERNAL_MDNS_Init();

    ESP_LOGD(INTERNAL_WEBSERVER_TAG, "%s OK", __FUNCTION__);
}

static httpd_handle_t s_internal_webserver_start(void)
{
    //Start Webserver And Return Handle

    httpd_handle_t server = NULL;
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();

    ESP_LOGD(INTERNAL_WEBSERVER_TAG, "tying to start webserver on port %u", config.server_port);

    if(httpd_start(&server, &config) == ESP_OK)
    {
        //Register GET And POST URI Handlers

        static httpd_uri_t s_internal_webserver_uri_get = {
                                                            .uri = "/",
                                                            .method = HTTP_GET,
                                                            .handler = s_internal_webserver_handler_get,
                                                            .user_ctx = NULL
                                                            };

        static httpd_uri_t s_internal_webserver_uri_post = {
                                                    .uri = "/?",
                                                    .method = HTTP_POST,
                                                    .handler = s_internal_webserver_handler_post,
                                                    .user_ctx = NULL
                                                    };

        httpd_register_uri_handler(server, &s_internal_webserver_uri_get);
        httpd_register_uri_handler(server, &s_internal_webserver_uri_post);

        return server;
    }
    return NULL;
}

static esp_err_t s_internal_webserver_handler_get(httpd_req_t* req)
{
    //Webserver GET Request Handler For HTML Page

    char buffer[64];
    uint8_t chunk_size = 0;

    FILE* html_handle = INTERNAL_SPIFFS_FileOpen("/media/blank.html");
    while(INTERNAL_SPIFFS_FileGetNextByte(html_handle, &buffer[chunk_size++]))
    {
        if(chunk_size == 64)
        {
            //Chunk Full. Send It
            httpd_resp_send_chunk(req, buffer, chunk_size);
            chunk_size = 0;
        }        
    }

    //Data Finished
    httpd_resp_send_chunk(req, buffer, chunk_size);
    httpd_resp_send_chunk(req, buffer, 0);

    INTERNAL_SPIFFS_FileClose(html_handle);
    return ESP_OK;
}

static esp_err_t s_internal_webserver_handler_post(httpd_req_t* req)
{
    //Webserver Post Request Handler

    int ret;
    char content[250] = {0};

    //Truncate If Content Length Larger Than Buffer
    size_t recv_size = MIN(req->content_len, sizeof(content) - 1);

    ret = httpd_req_recv(req, content, recv_size);
    if(ret < 0)
    {
        if(ret == HTTPD_SOCK_ERR_TIMEOUT)
        {
            //Send Http Request Timeout Error Code (408)
            httpd_resp_send_408(req);
        }

        return ESP_FAIL;
    }

    ets_printf("post data received ...\n");
    ets_printf("%s\n", content);

    return ESP_OK;
}