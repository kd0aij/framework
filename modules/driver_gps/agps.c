/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "agps.h"
#include <common/ctor.h>
#include <ch.h>
#include <modules/worker_thread/worker_thread.h>

#ifndef STACK_MEASUREMENT_WORKER_THREAD
#error Please define STACK_MEASUREMENT_WORKER_THREAD in framework_conf.h.
#endif

#define WT STACK_MEASUREMENT_WORKER_THREAD
WORKER_THREAD_DECLARE_EXTERN(WT)

static struct worker_thread_timer_task_s send_gps_msg_task;
static void send_gps_msg_task_func(struct worker_thread_timer_task_s* task);

RUN_AFTER(WORKER_THREADS_INIT) {
    worker_thread_add_timer_task(&WT, &send_gps_msg_task, send_gps_msg_task_func, NULL, S2US(60), true);
}

extern uint8_t __process_stack_base__;
extern uint8_t __main_stack_base__;
