/**
 * @file  SUCHAI_config.h
 * @author Carlos Gonzalez C
 * @author Tomas Opazo T
 * @autor Ignacio Ibanez A
 * @date 2017
 * @copyright GNU Public License.
 *
 * This header contains system wide settings to customize different submodules
 */

#ifndef SUCHAI_CONFIG_H
#define	SUCHAI_CONFIG_H

/* General includes */
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

/* Select one operating system */
#define {{OS}}                                      ///< LINUX | FREERTOS
/* Select the correct architecture */
#ifdef FREERTOS
    #define {{ARCH}}                                ///< ESP32 | AVR32 | NANOMIND
#endif

/* System debug configurations */
#define LOG_LEVEL               {{LOG_LVL}}        ///<  LOG_LVL_INFO |  LOG_LVL_DEBUG

/* General system settings */
#define SCH_BUFF_MAX_LEN        (256)              ///< General buffers max length (bytes)
#define SCH_COMM_ENABLE         {{SCH_EN_COMM}}    ///< TaskCommunications enabled (0 | 1)
#define SCH_FP_ENABLED          {{SCH_EN_FP}}      ///< TaskFlightPlan enabled (0 | 1)
#define SCH_HK_ENABLED          {{SCH_EN_HK}}      ///< TaskHousekeeping enabled (0 | 1)
#define SCH_TEST_ENABLED        {{SCH_EN_TEST}}    ///< Set to run tests (0 | 1)
#define SCH_MAX_WDT_TIMER       10                 ///< Seconds to send wdt_reset command
#define SCH_MAX_GND_WDT_TIMER   (3600*48)          ///< Seconds to reset the OBC if the ground watchdog was not clear

/* Communications system settings */
#define SCH_COMM_ADDRESS        {{SCH_COMM_NODE}}  ///< Node address
#define SCH_TRX_PORT_TM         (9)                ///< Telemetry port
#define SCH_TRX_PORT_TC         (10)               ///< Telecommands port
#define SCH_TRX_PORT_RPT        (11)               ///< Digirepeater port (resend packets)
#define SCH_TRX_PORT_CMD        (12)               ///< Commads port (execute console commands)
#define SCH_COMM_ZMQ_OUT        "{{SCH_ZMQ_OUT}}"    ///< Out socket URI
#define SCH_COMM_ZMQ_IN         "{{SCH_ZMQ_IN}}"     ///< In socket URI

/* Data repository settings */
#define SCH_STORAGE_MODE        {{SCH_STORAGE}}    ///< Status repository location. (0) RAM, (1) Single external.
#define SCH_STORAGE_FILE        "/tmp/suchai.db"

#endif	/* SUCHAI_CONFIG_H */