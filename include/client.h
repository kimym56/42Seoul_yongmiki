/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:29:52 by yongmiki          #+#    #+#             */
/*   Updated: 2022/02/16 21:54:39 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

// ================================= const ================================== //

# define TIMEOUT_COUNT				100000

// ================================ library ================================= //

# include "common.h"

// ========================= prototype declaration ========================== //

void	exit_client(char *message, bool success);

void	check_argument(int argc, char **argv);

void	send_bits_pid_client(int32_t pid_server, int32_t send_pid_client);
void	send_bits_message(int32_t pid_server, char *send_message);

#endif
