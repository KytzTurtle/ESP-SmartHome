#ifndef TASK_HANDLER_H
#define TASK_HANDLER_H

#include "common.h"

#define LIGHT_MODULE ENABLED
#define TEMPERATURE_MODULE ENABLED
#define GENERIC_MODULE DISABLED

static QueueHandle_t light_sensor_queue = NULL;

uint8_t all_task_create(void);

#endif 