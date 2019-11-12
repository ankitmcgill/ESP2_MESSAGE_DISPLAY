///////////////////////////////////////////////////////////////
//ELTS - ESP32 LASER TAG SYSTEM
//
//DRIVER - SPIFFS
//

//OCTOBER 2 2019
///////////////////////////////////////////////////////////////

#include "esp_log.h"
#include "esp_err.h"
#include "esp_spiffs.h"

#include "internal_spiffs.h"

//Internal Variables

//Internal Functions

void INTERNAL_SPIFFS_Init(void)
{
    //Initialize DRIVER_SPIFFS
    esp_err_t ret;
    esp_vfs_spiffs_conf_t conf;
    size_t total = 0, used = 0;
    
    conf.base_path = "/media";
    conf.partition_label = NULL;
    conf.max_files = 5;
    conf.format_if_mount_failed = false;

    //Initialize And Mount SPIFFS File System
    ret = esp_vfs_spiffs_register(&conf);

    if(ret != ESP_OK)
    {
        switch(ret)
        {
            case ESP_FAIL:
                ESP_LOGE(DRIVER_SPIFFS_TAG, "Failed to mount or format filesystem");
                break;
            
            case ESP_ERR_NOT_FOUND:
                ESP_LOGE(DRIVER_SPIFFS_TAG, "Failed to find SPIFFS partition");
                break;
            
            default:
                ESP_LOGE(DRIVER_SPIFFS_TAG, "Failed to initialize SPIFFS (%s)", esp_err_to_name(ret));
                break;
        }
    }

    ret = esp_spiffs_info(NULL, &total, &used);

    if(ret != ESP_OK)
    {
        ESP_LOGE(DRIVER_SPIFFS_TAG, "Failed to get SPIFFS partition information (%s)", esp_err_to_name(ret));
    }
    else
    {
        ESP_LOGD(DRIVER_SPIFFS_TAG, "Partition size: total: %d, used: %d", total, used);
    }

    ESP_LOGD(DRIVER_SPIFFS_TAG, "%s - OK", __FUNCTION__);
}

bool INTERNAL_SPIFFS_CheckFileExists(char* filename)
{
    //Check If Specified File Exists in Spiffs Partition
    
    FILE* fd = fopen(filename, "r");

    if(fd == NULL)
    {
        return false;
    }

    fclose(fd);
    return true;
}

FILE* INTERNAL_SPIFFS_FileOpen(char* filename)
{
    //Open File And Return Handle

    FILE* fd = fopen(filename, "r");
    return fd;
}

bool INTERNAL_SPIFFS_FileGetNextByte(FILE* handle, char* byte)
{
    //Return Next Read Byte From Specified File Handle

    int result = fgetc(handle);

    if(result == EOF)
    {
        return false;
    }

    *byte = result;
    return true;
}

void INTERNAL_SPIFFS_FileClose(FILE* handle)
{
    //Close File Handle

    fclose(handle);
}