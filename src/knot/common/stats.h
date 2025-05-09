/*  Copyright (C) 2020 CZ.NIC, z.s.p.o. <knot-dns@labs.nic.cz>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

/*!
 * \brief Server statistics general API.
 */

#pragma once

#include "knot/server/server.h"

typedef uint64_t (*stats_val_f)(server_t *server);

/*!
 * \brief Statistics metrics item.
 */
typedef struct {
	const char *name; /*!< Metrics name. */
	stats_val_f val;  /*!< Metrics value getter. */
} stats_item_t;

/*!
 * \brief Basic server metrics.
 */
extern const stats_item_t server_stats[];

/*!
 * \brief Statistics metrics item.
 */
typedef enum {
    server_stats_udp_received,
    server_stats_udp_async_done,
    server_stats_udp_no_req_obj,
    server_stats_udp_req_batch_limited,
    server_stats_tcp_accept,
    server_stats_tcp_received,
    server_stats_tcp_async_done,
    server_stats_tcp_no_req_obj,
    server_stats_tcp_multiple_req,
    server_stats_max,
} server_stats_counter_t;

/*!
 * \brief Increment the server stats.
 */
void server_stats_increment_counter(server_stats_counter_t counter, uint64_t value);

/*!
 * \brief Read out value of single counter summed across threads.
 */
uint64_t stats_get_counter(uint64_t **stats_vals, uint32_t offset, unsigned threads);

/*!
 * \brief Reconfigures the statistics facility.
 */
void stats_reconfigure(conf_t *conf, server_t *server);

/*!
 * \brief Deinitializes the statistics facility.
 */
void stats_deinit(void);
