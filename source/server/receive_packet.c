/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_packet.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 06:04:38 by yongmiki          #+#    #+#             */
/*   Updated: 2022/02/16 22:14:56 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/server.h"

static void	send_ack(t_server_vars *vars, int send_signal)
{
	if (kill(vars->pid_client_bits, send_signal) == -1)
		exit_server(vars, "ERROR: Fail to send Packet !!", false);
}

static void	receive_bit_pid_client(t_server_vars *vars, int signal)
{
	vars->pid_client_bits <<= 1;
	if (signal == SIGUSR1)
		vars->pid_client_bits++;
	vars->pid_client_bit_count++;
}

static void	receive_bit_message(t_server_vars *vars, int signal)
{
	vars->message_bits <<= 1;
	if (signal == SIGUSR1)
		vars->message_bits++;
	vars->message_bit_count++;
	if (vars->message_bit_count == MSG_BIT_COUNT)
	{
		if (vars->message_bits == ASCII_EOT)
		{
			print_receive_message(vars);
			free_receive_message(vars);
			send_ack(vars, signal);
			init_server_vars(vars);
		}
		else
		{
			append_receive_message(vars);
			send_ack(vars, signal);
			init_server_vars_message_bits(vars);
		}
	}
	else
		send_ack(vars, signal);
}

void	receive_bit(t_server_vars *vars, int signal)
{
	if (vars->pid_client_bit_count < PID_BIT_COUNT)
	{
		receive_bit_pid_client(vars, signal);
		if (vars->pid_client_bit_count == PID_BIT_COUNT)
			send_ack(vars, SIGUSR1);
	}
	else
	{
		receive_bit_message(vars, signal);
	}
	g_receive_signal = 0;
}
