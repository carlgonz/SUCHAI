/**
 * @file  osSemphr.h
 * @author Carlos Gonzalez Cortes
 * @author Ignacio Ibanez Aliaga
 * @date 2020
 * @copyright GNU Public License.
 */

#ifndef _OS_SEMPHR_H_
#define _OS_SEMPHR_H_

#include "os/os.h"
#include "suchai/config.h"

#ifdef FREERTOS
	#include "FreeRTOS.h"
	#include "queue.h"
	#include "semphr.h"
	typedef xSemaphoreHandle osSemaphore;

	#define OS_SEMAPHORE_OK 	pdPASS
    #define OS_SEMAPHORE_ERROR	pdFAIL
    #define OS_MUTEX_OK 		OS_SEMAPHORE_OK
    #define OS_MUTEX_ERROR		OS_SEMAPHORE_ERROR
#else
    #include <pthread.h>
    #include <stdint.h>
    typedef pthread_mutex_t osSemaphore;

    #define OS_SEMAPHORE_OK     1
    #define OS_SEMAPHORE_ERROR  2
    #define OS_MUTEX_OK 		OS_SEMAPHORE_OK
    #define OS_MUTEX_ERROR		OS_SEMAPHORE_ERROR
#endif

int osSemaphoreCreate(osSemaphore* mutex);
int osSemaphoreTake(osSemaphore* mutex, uint32_t timeout);
int osSemaphoreGiven(osSemaphore* mutex);

#endif