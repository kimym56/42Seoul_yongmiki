/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message_common.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 22:21:53 by yongmiki          #+#    #+#             */
/*   Updated: 2022/02/16 22:32:36 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/server.h"

void	print_success_message(char *message)
{
	ft_putendl_fd(message, STDOUT_FILENO);
}

void	print_failure_message(char *message)
{
	ft_putendl_fd(message, STDOUT_FILENO);
}

void	print_pid(char *client_or_server, int32_t pid)
{
	ft_putstr_fd("[ ", STDOUT_FILENO);
	ft_putstr_fd(client_or_server, STDOUT_FILENO);
	ft_putstr_fd(" ProcessID: ", STDOUT_FILENO);
	ft_putnbr_fd((int)pid, STDOUT_FILENO);
	ft_putendl_fd(" ]", STDOUT_FILENO);
}
