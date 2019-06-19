/*
 * Race Capture Firmware
 *
 * Copyright (C) 2016 Autosport Labs
 *
 * This file is part of the Race Capture firmware suite
 *
 * This is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the GNU General Public License for more details. You should
 * have received a copy of the GNU General Public License along with
 * this code. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CONNECTIVITY_TASK_H_
#define CONNECTIVITY_TASK_H_

#include "FreeRTOS.h"
#include "cpp_guard.h"
#include "devices_common.h"
#include "queue.h"
#include "sampleRecord.h"
#include "serial.h"
#include "task.h"
#include "dateTime.h"
#include <stdint.h>
#include <stdbool.h>

CPP_GUARD_BEGIN

typedef struct _ConnParams {
        bool always_streaming;
        char * connectionName;
        int (*disconnect)(DeviceConfig *config);
        int (*init_connection)(DeviceConfig *config, millis_t * connected_at, bool hard_init);
        int (*check_connection_status)(DeviceConfig *config);
        serial_id_t serial;
        size_t periodicMeta;
        uint32_t connection_timeout;
        xQueueHandle sampleQueue;
        int max_sample_rate;
        enum led activity_led;
} ConnParams;

typedef struct _TelemetryConnParams {
        bool always_streaming;
        char * connectionName;
        int (*disconnect)(DeviceConfig *config);
        int (*init_connection)(DeviceConfig *config, millis_t * connected_at, bool hard_init);
        int (*check_connection_status)(DeviceConfig *config);
        bool (*tx_socket)(DeviceConfig *config, int socket_id, char * buffer);
        serial_id_t serial;
        uint32_t connection_timeout;
        xQueueHandle sampleQueue;
        int max_sample_rate;
        enum led activity_led;
} TelemetryConnParams;

typedef struct _BufferingTaskParams {
        bool always_streaming;
        char * connectionName;
        size_t periodicMeta;
        xQueueHandle sampleQueue;
        xQueueHandle buffer_queue;
        int max_sample_rate;
} BufferingTaskParams;

typedef struct _BufferedTelemetryMessage {
        enum LoggerMessageType type;
        size_t ticks;
        struct sample *sample;
} BufferedTelemetryMessage;

typedef struct _StringSerialParams {
        struct Serial * serial;
        char * buffer;
        size_t buffer_len;
} StringSerialParams;

void queueTelemetryRecord(const LoggerMessage *msg);

void startConnectivityTask(int16_t priority);

void connectivityTask(void *params);

void cellular_connectivity_task(void *params);

void cellular_buffering_task(void *params);

void string_serial_task(void *params);

CPP_GUARD_END

#endif /* CONNECTIVITY_TASK_H_ */
