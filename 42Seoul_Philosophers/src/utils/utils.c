/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 00:14:11 by yongmiki          #+#    #+#             */
/*   Updated: 2022/04/03 18:32:32 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	print_help(void)
{
	return (ft_exit("wrong number of arguments!"));
}

void	msleep(long long time)
{
	long long	before;
	long long	now;

	before = get_time();
	now = before;
	while (now - before < time)
	{
		usleep(100);
		now = get_time();
	}
}

long long	get_time(void)
{
	struct timeval	time;
	long long		sec;

	if (gettimeofday(&time, NULL) == -1)
	{
		ft_exit("Error while reading the time");
		return (-1);
	}
	sec = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (sec);
}

void	ft_write_action(char *action, t_philo *philo)
{
	printf("%lld %d %s\n", get_time() - philo->start, philo->id, action);
}
