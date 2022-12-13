/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:28:42 by yongmiki          #+#    #+#             */
/*   Updated: 2022/02/16 21:55:53 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/client.h"

int		g_receive_signal;

void	exit_client(char *message, bool success)
{
	if (success)
	{
		print_success_message(message);
		exit(EXIT_SUCCESS);
	}
	else
	{
		print_failure_message(message);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	int32_t		pid_server;
	int32_t		pid_client;

	check_argument(argc, argv);
	g_receive_signal = 0;
	set_signal();
	pid_server = ft_atoi(argv[1]);
	pid_client = getpid();
	print_pid("CLIENT", pid_client);
	send_bits_pid_client(pid_server, pid_client);
	send_bits_message(pid_server, argv[2]);
	return (EXIT_SUCCESS);
}
