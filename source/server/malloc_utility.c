/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:32:56 by yongmiki          #+#    #+#             */
/*   Updated: 2022/02/16 22:14:21 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/server.h"

void	append_receive_message(t_server_vars *vars)
{
	char	*new_message;

	new_message = (char *)malloc(sizeof(char) * (vars->message_count + 2));
	if (!new_message)
		exit_server(vars, "ERROR: Fail to Allocate Memory !!", false);
	ft_strlcpy(new_message, vars->message, vars->message_count + 2);
	new_message[vars->message_count] = vars->message_bits;
	new_message[vars->message_count + 1] = '\0';
	vars->message_count++;
	if (vars->message)
		free(vars->message);
	vars->message = new_message;
}

void	free_receive_message(t_server_vars *vars)
{
	if (vars->message)
		free(vars->message);
}
