/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_server_vars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 23:24:32 by yongmiki          #+#    #+#             */
/*   Updated: 2022/02/16 22:13:50 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/server.h"

void	init_server_vars(t_server_vars *vars)
{
	vars->pid_client_bits = 0;
	vars->pid_client_bit_count = 0;
	vars->message_bits = 0;
	vars->message_bit_count = 0;
	vars->message = NULL;
	vars->message_count = 0;
}

void	init_server_vars_message_bits(t_server_vars *vars)
{
	vars->message_bits = 0;
	vars->message_bit_count = 0;
}
