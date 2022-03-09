/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:42:32 by yongmiki          #+#    #+#             */
/*   Updated: 2022/03/09 21:13:22 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_table(char **str, int j)
{
	while (str[j])
		free(str[j++]);
	free(str);
	return (-1);
}

int	free_str(char **str, int j)
{
	while (str[j])
	{
		free(str[j]);
	}
	free(str);
	return (-1);
}

int	check_args(char **av, t_list **stack_a)
{
	int		i;
	int		j;
	int		save;
	char	**str;
	int		max;

	i = 0;
	while (av[++i])
	{
		j = -1;
		str = ft_split(av[i], ' ');
		while (str[++j])
		{
			max = 0;
			save = ft_atoi_modif(str[j], &max);
			free(str[j]);
			if (max == 1 || is_same(*stack_a, save))
				return (free_str(str, j + 1));
			ft_lstadd_back(stack_a, ft_lstnew(save));
		}
		free(str);
	}
	return (1);
}

int	check_signe(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if ((str[i] == '-' || str[i] == '+') && (i != 0 || !str[i + 1]))
			return (0);
	}
	return (1);
}

int	countnum(char **av)
{
	int		i;
	int		j;
	char	**str;
	int		count;

	count = 0;
	i = 0;
	while (av[++i])
	{
		j = -1;
		str = ft_split(av[i], ' ');
		while (str[++j])
			if (!is_integers(str[j]) || !check_signe(str[j]))
				return (free_table(str, j));
		else
			free(str[j]);
		count += j;
		free(str);
	}
	return (count);
}
