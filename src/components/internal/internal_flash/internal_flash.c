///////////////////////////////////////////////////////////////
//ESP32 MESSAGE DISPLAY
//
//INTERNAL - FLASH
//

//SEPTEMBER 13 2019
///////////////////////////////////////////////////////////////

#include "nvs.h"
#include "nvs_flash.h"
#include "esp_log.h"

#include "internal_flash.h"

#define INTERNAL_FLASH_NVS_NAMESPACE  "nvs"

//Internal Variables

//Internal Functions
static bool s_internal_flash_open_nvs(nvs_handle_t* nvs_handle);
static void s_internal_flash_close_nvs(nvs_handle_t nvs_handle);

bool INTERNAL_FLASH_Init(void)
{
    //Initialize INTERNAL_FLASH

    esp_err_t err;
    
    //Initialize NVS
    err = nvs_flash_init();
    if(err == ESP_ERR_NVS_NO_FREE_PAGES || 
            err == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        //Nvs Partition Was Truncated And Needs To Be Erased
        //Nvs Erase + Retry NVS Init
        
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init();

        if(err != ESP_OK)
        {
            return false;
        }
    }

    ESP_LOGD(INTERNAL_FLASH_TAG, "%s - OK", __FUNCTION__);

    return true;
}

bool INTERNAL_FLASH_DataReadUint32(char* key, void* retval)
{
    //Read Uint32 Data From Default NVS Namespace

    esp_err_t err;
    nvs_handle_t nvs_handle;

    if(!s_internal_flash_open_nvs(&nvs_handle))
    {
        return false;
    }

    err =  nvs_get_u32(nvs_handle,
                        key,
                        (uint32_t*)retval);
    
    s_internal_flash_close_nvs(nvs_handle);

    return (err == ESP_OK);
}

bool INTERNAL_FLASH_DataWriteUint32(char* key, void* data)
{
    //Write Uint32 Data From Default NVS Namespace

    esp_err_t err;
    nvs_handle_t nvs_handle;

    if(!s_internal_flash_open_nvs(&nvs_handle))
    {
        return false;
    }

    err =  nvs_set_u32(nvs_handle,
                        key,
                        *((uint32_t*)data));
    err = nvs_commit(nvs_handle);
    
    s_internal_flash_close_nvs(nvs_handle);

    return (err == ESP_OK);
}

bool INTERNAL_FLASH_DataReadString(char* key, void* retval, size_t* size)
{
    //Read String Data From Default NVS Namespace

    esp_err_t err;
    nvs_handle_t nvs_handle;

    if(!s_internal_flash_open_nvs(&nvs_handle))
    {
        return false;
    }

    err =  nvs_get_str(nvs_handle,
                        key,
                        (char*)retval,
                        size);
    
    s_internal_flash_close_nvs(nvs_handle);

    return (err == ESP_OK);
}

bool INTERNAL_FLASH_DataWriteString(char* key, void* data)
{
    //Write String Data From Default NVS Namespace

    esp_err_t err;
    nvs_handle_t nvs_handle;

    if(!s_internal_flash_open_nvs(&nvs_handle))
    {
        return false;
    }

    err =  nvs_set_str(nvs_handle,
                        key,
                        (char*)data);
    err = nvs_commit(nvs_handle);

    s_internal_flash_close_nvs(nvs_handle);

    return (err == ESP_OK);
}

bool INTERNAL_FLASH_DataReadBlob(char* key, void* retval, size_t* size)
{
    //Read Blob Data From Default NVS Namespace

    esp_err_t err;
    nvs_handle_t nvs_handle;

    if(!s_internal_flash_open_nvs(&nvs_handle))
    {
        return false;
    }

    err =  nvs_get_blob(nvs_handle,
                        key,
                        retval,
                        size);
    
    s_internal_flash_close_nvs(nvs_handle);

    return (err == ESP_OK);
}

bool INTERNAL_FLASH_DataWriteBlob(char* key, void* data, size_t size)
{
    //Write Blob Data From Default NVS Namespace

    esp_err_t err;
    nvs_handle_t nvs_handle;

    if(!s_internal_flash_open_nvs(&nvs_handle))
    {
        return false;
    }

    err =  nvs_set_blob(nvs_handle,
                        key,
                        data,
                        size);
    err = nvs_commit(nvs_handle);

    s_internal_flash_close_nvs(nvs_handle);

    return (err == ESP_OK);
}

static bool s_internal_flash_open_nvs(nvs_handle_t* nvs_handle)
{
    //Open NVS Namespace

    esp_err_t err;

    err = nvs_open(INTERNAL_FLASH_NVS_NAMESPACE, 
                    NVS_READWRITE,
                    nvs_handle);
    
    return (err == ESP_OK);
}

static void s_internal_flash_close_nvs(nvs_handle_t nvs_handle)
{
    //Close NVS Namespace

    nvs_close(nvs_handle);
}