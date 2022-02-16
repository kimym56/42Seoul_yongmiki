/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signal_common.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 03:56:30 by yongmiki          #+#    #+#             */
/*   Updated: 2022/02/16 22:33:25 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/common.h"

static void	handle_signal(int signal)
{
	g_receive_signal = signal;
}

void	set_signal(void)
{
	if (signal(SIGUSR1, &handle_signal) == SIG_ERR
		|| signal(SIGUSR2, &handle_signal) == SIG_ERR)
	{
		print_failure_message("ERROR: Fail to set Signal !!");
		exit(EXIT_FAILURE);
	}
}
