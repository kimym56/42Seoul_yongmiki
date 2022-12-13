/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:32:39 by yongmiki          #+#    #+#             */
/*   Updated: 2022/04/03 18:32:47 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	ft_count(int *i, int *neg, const char *str)
{
	*i = 0;
	*neg = 1;
	while (str[*i] == 32 || (str[*i] >= 9 && str[*i] <= 13))
		*i += 1;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*neg *= -1;
		*i += 1;
	}
	while (str[*i] >= '0' && str[*i] <= '9')
		*i += 1;
}

long	ft_atoi(const char *str)
{
	int		i;
	long	multiplicator;
	long	num;
	int		neg;

	multiplicator = 1;
	num = 0;
	ft_count(&i, &neg, str);
	while (i > 0 && str[i - 1] >= '0' && str[i - 1] <= '9')
	{
		num += (str[i - 1] - '0') * multiplicator;
		multiplicator *= 10;
		i--;
	}
	return (num * neg);
}

int	ft_exit(char *error)
{
	write(2, error, ft_strclen(error, '\0'));
	write(2, "\n", 1);
	return (EXIT_FAILURE);
}

bool	ft_isnum(int size, char **s)
{
	int	i;

	while (size > 0)
	{
		i = 0;
		while (s[size][i] >= '0' && s[size][i] <= '9')
			i++;
		if (s[size][i] != '\0')
			return (false);
		size--;
	}
	return (true);
}

size_t	ft_strclen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] == '\0' && c != '\0')
		i = -1;
	return (i);
}
