#ifndef CAPABILITIES_H_
#define CAPABILITIES_H_
#include "serial.h"
#include "FreeRTOSConfig.h"

//Hardware capabilities for RCP MK2

#define TICK_RATE_HZ			configTICK_RATE_HZ
#define MS_PER_TICK 1

//configuration
#define MAX_TRACKS				240
#define MAX_SECTORS				20
#define MAX_VIRTUAL_CHANNELS	30

#define LUA_MEM_MAX (1024 * 50)
#define LOGGER_MESSAGE_BUFFER_SIZE	10

/* LUA Configuration */
/*
 * What is the maximum length of the script that can be provided?
 *
 * In MK2 this is simply a 16K flash block.  If smaller, then
 * value % 256 must be 0.
 */
#define SCRIPT_MEMORY_LENGTH	(1024 * 16)

/*
 * Defines the memory ceiling for LUA.  In other words, how much RAM can
 * LUA allocate before we say no.  This keeps LUA from crashing the system
 * when a memory hog LUA script is running.  Set to 0 for no limit.
 *
 * 50 K seems to be solid from testing.
 */
#define LUA_MEM_MAX (1024 * 50)

/*
 * These values dictate how the LUA garbage collector will behave.
 * Tweaking these is necessary in low memory environments to ensure
 * that LUA's memory footprint does not exceed what can be spared.
 * A value of 0 means that you want to use the default.  For more info
 * see http://www.lua.org/manual/5.1/manual.html#2.10
 */
#define LUA_GC_PAUSE_PCT	0
#define LUA_GC_STEP_MULT_PCT	0


//Input / output Channels
#define ANALOG_CHANNELS 		8
#define IMU_CHANNELS			7
#define	GPIO_CHANNELS			3
#define TIMER_CHANNELS			3
#define PWM_CHANNELS			4
#define CAN_CHANNELS			2
#define CONNECTIVITY_CHANNELS	2

//sample rates
#define MAX_SENSOR_SAMPLE_RATE	1000
#define MAX_GPS_SAMPLE_RATE		50
#define MAX_OBD2_SAMPLE_RATE	1000

//logging
#define LOG_BUFFER_SIZE			8192

//system info
#define DEVICE_NAME    "RCP_MK2"
#define FRIENDLY_DEVICE_NAME "RaceCapture/Pro MK2"
#define COMMAND_PROMPT "RaceCapture/Pro MK2"
#define VERSION_STR MAJOR_REV_STR "." MINOR_REV_STR "." BUGFIX_REV_STR
#define WELCOME_MSG "Welcome to RaceCapture/Pro MK2 : Firmware Version " VERSION_STR

//initialize main tasks in temporary FreeRTOS task
#define TASK_TASK_INIT 1
#endif /* CAPABILITIES_H_ */
