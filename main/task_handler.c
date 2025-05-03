/*
 * SPDX-FileCopyrightText: 2020-2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "task_handler.h"
#include "esp_log.h"

static void light_sensor_task(void *arg)
{
    for (;;)
    {
        printf("light sensor task");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

static void light_control_task(void *arg)
{
    for (;;)
    {
        printf("light control task");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

static void temperature_sensor_task(void *arg)
{
    for (;;)
    {
        printf("temperature sensor task");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

static void temperature_control_task(void *arg)
{
    for (;;)
    {
        printf("temperature control task");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

static void generic_sensor_task(void *arg)
{
}

static void generic_control_task(void *arg)
{
}

uint8_t all_task_create(void)
{
#if (LIGHT_MODULE == ENABLED)
    xTaskCreate(light_sensor_task, "light_sensor_task", 2048, NULL, 10, NULL);
    xTaskCreate(light_control_task, "light_control_task", 2048, NULL, 10, NULL);
#endif

#if (TEMPERATURE_MODULE == ENABLED)
    xTaskCreate(temperature_sensor_task, "temperature_sensor_task", 2048, NULL, 10, NULL);
    xTaskCreate(temperature_control_task, "temperature_control_task", 2048, NULL, 10, NULL);

#endif

#if (GENERIC_MODULE == ENABLED)

    xTaskCreate(generic_sensor_task, "generic_sensor_task", 2048, NULL, 10, NULL);
    xTaskCreate(generic_control_task, "generic_control_task", 2048, NULL, 10, NULL);
#endif
return 0;
}
