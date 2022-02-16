/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 22:21:53 by yongmiki          #+#    #+#             */
/*   Updated: 2022/02/16 22:14:34 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/server.h"

void	print_receive_message(t_server_vars *vars)
{
	ft_putstr_fd("[ CLIENT ProcessID: ", STDOUT_FILENO);
	ft_putnbr_fd(vars->pid_client_bits, STDOUT_FILENO);
	ft_putstr_fd(" ]", STDOUT_FILENO);
	ft_putendl_fd(vars->message, STDOUT_FILENO);
}
