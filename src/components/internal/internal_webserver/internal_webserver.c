///////////////////////////////////////////////////////////////
//ESP32 MESSAGE DISPLAY
//
//INTERNAL - WEBSERVER
//
//RODA AWANA SDN BHD
//NOVEMBER 4 2019
///////////////////////////////////////////////////////////////

#include "esp_system.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_http_server.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"

#include "internal_webserver.h"
#include "global.h"
#include "bsp.h"

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
                                                    .uri = "/",
                                                    .method = HTTP_POST,
                                                    .handler = s_internal_webserver_handler_post,
                                                    .user_ctx = NULL
                                                    };

        httpd_register_uri_handler(server, &s_internal_webserver_uri_get);
        httpd_register_uri_handler(server, &s_internal_webserver_uri_post);

        return server;
    }

    ESP_LOGE(INTERNAL_WEBSERVER_TAG, "cannot start webserver");
    return NULL;
}

static esp_err_t s_internal_webserver_handler_get(httpd_req_t* req)
{
    //Webserver GET Request Handler

    httpd_resp_send(req, "HELLO ANKIT", strlen("HELLO ANKIT"));
    return ESP_OK;
}

static esp_err_t s_internal_webserver_handler_post(httpd_req_t* req)
{
    //Webserver Post Request Handler

    return ESP_OK;
}