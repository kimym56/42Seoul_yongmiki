/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 00:10:19 by yongmiki          #+#    #+#             */
/*   Updated: 2022/02/16 21:55:39 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/client.h"

static bool	check_pid_server_is_digit(char *pid_server)
{
	size_t	len;

	len = ft_strlen(pid_server);
	while (len--)
	{
		if (!ft_isdigit(pid_server[len]))
			return (false);
	}
	return (true);
}

static bool	check_pid_server_is_in_range(int32_t pid_server)
{
	if (pid_server <= MIN_PID || MAX_PID < pid_server)
		return (false);
	return (true);
}

static bool	check_message_is_string(char *send_message)
{
	if (!send_message)
		return (false);
	if (!(*send_message))
		return (false);
	return (true);
}

void	check_argument(int argc, char **argv)
{
	if (argc != 3)
		exit_client("USAGE: ./client [SERVER PID] [SEND MESSAGE]", false);
	if (!check_pid_server_is_digit(argv[1]))
		exit_client("ERROR: SERVER ProcessID must be number !!", false);
	if (!check_pid_server_is_in_range(ft_atoi(argv[1])))
		exit_client("ERROR: SERVER ProcessID is not in PID range !!", false);
	if (!check_message_is_string(argv[2]))
		exit_client("ERROR: SEND MESSAGE is INVALID !!", false);
}
