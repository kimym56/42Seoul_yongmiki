/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_packet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 00:10:19 by yongmiki          #+#    #+#             */
/*   Updated: 2022/02/16 22:23:31 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/client.h"

static void	wait_receive_ack_pid(void)
{
	if (g_receive_signal == SIGUSR1)
		print_success_message("SUCCESS: Done to send CLIENT ProcessID !!");
	else
		exit_client("ERROR: Fail to send CLIENT ProcessID !!", false);
	g_receive_signal = 0;
}

static void	wait_receive_ack_message(int send_signal)
{
	int		timeout_count;

	timeout_count = TIMEOUT_COUNT;
	while (g_receive_signal == 0)
	{
		if (timeout_count == 0)
			exit_client("ERROR: Timeout !!", false);
		usleep(10);
		timeout_count--;
	}
	if (g_receive_signal != send_signal)
		exit_client("ERROR: Fail to send Message !!", false);
	g_receive_signal = 0;
}

static void	send_bits(int32_t pid_server, int32_t send_bits,
											int send_bit_count, bool ack_mode)
{
	int		current_bit;
	int		send_signal;

	while (0 <= --send_bit_count)
	{
		current_bit = (send_bits >> send_bit_count) & 0x1;
		if (current_bit == 0)
			send_signal = SIGUSR2;
		else
			send_signal = SIGUSR1;
		if (kill(pid_server, send_signal) == -1)
			exit_client("ERROR: Fail to send Signal !!", false);
		if (ack_mode)
		{
			wait_receive_ack_message(send_signal);
			usleep(50);
		}
		else
			usleep(1000);
	}
}

void	send_bits_pid_client(int32_t pid_server, int32_t send_pid_client)
{
	send_bits(pid_server, send_pid_client, PID_BIT_COUNT, false);
	wait_receive_ack_pid();
}

void	send_bits_message(int32_t pid_server, char *send_message)
{
	while (*send_message)
	{
		send_bits(pid_server, (int32_t)(*send_message), MSG_BIT_COUNT, true);
		send_message++;
	}
	send_bits(pid_server, (int32_t)ASCII_EOT, MSG_BIT_COUNT, true);
	print_success_message("SUCCESS: Done to send Message !!");
}
