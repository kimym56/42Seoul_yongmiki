/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:00:46 by yongmiki          #+#    #+#             */
/*   Updated: 2022/03/09 21:08:36 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	found_instruction(int i, int j, t_global *global)
{
	if (i < ft_lstsize(global->stack_a) - j)
	{
		while (i)
		{
			do_opt("ra", &global->stack_a, &ra);
			i--;
		}
		do_push("pb", global, &pb);
	}
	else if (i >= ft_lstsize(global->stack_a) - j)
	{
		while (j < ft_lstsize(global->stack_a))
		{
			do_opt("rra", &global->stack_a, &rra);
			j++;
		}
		do_push("pb", global, &pb);
	}
}

long long	found_best(int min, int max, t_global *global, int *j)
{
	long long	best2;
	long long	content;

	*j = ft_lstsize(global->stack_a);
	best2 = -2147483649;
	while (--*j >= ft_lstsize(global->stack_a) / 2)
	{
		content = get_lst_content(global->stack_a, *j);
		if (content == -2147483649)
			break ;
		if (content && content >= min && content <= max)
		{
			best2 = content;
			break ;
		}
	}
	return (best2);
}

void	rotate_push(t_global *global, int min, int max)
{
	long long	best;
	long long	best2;
	int			i;
	int			j;
	t_list		*tmp;

	(best = 0 == 0) && (best2 = 0 == 0);
	while (best != -2147483649 || best2 != -2147483649)
	{
		tmp = global->stack_a;
		i = -1;
		best = -2147483649;
		while (++i < ft_lstsize(global->stack_a) / 2 && tmp)
		{
			if (tmp->content >= min && tmp->content <= max)
			{
				best = tmp->content;
				break ;
			}
			tmp = tmp->next;
		}
		best2 = found_best(min, max, global, &j);
		if (best != -2147483649 || best2 != -2147483649)
			found_instruction(i, j, global);
	}
}

void	put_max_top(int pos, t_global *global)
{
	int	size;

	size = ft_lstsize(global->stack_b);
	if (pos > size / 2)
	{
		pos = size - pos;
		while (pos-- != 0)
			do_opt("rrb", &global->stack_b, &rrb);
	}
	else if (pos <= size / 2)
	{
		while (pos-- != 0)
			do_opt("rb", &global->stack_b, &rb);
	}
}

void	main_algo(t_global *global)
{
	int	*tab;
	int	min;
	int	max;
	int	i;

	tab = NULL;
	tab = fill_tab(global->stack_a, tab, global->size);
	ft_sort_int_tab(tab, global->size);
	i = 0;
	global->range = found_range(global->size);
	while (i * global->range < global->size)
	{
		if ((i * global->range) >= global->size)
			min = tab[global->size - 1];
		else
			min = tab[i * global->range];
		if ((i * global->range + global->range) >= global->size)
			max = tab[global->size - 1];
		else
			max = tab[i * global->range + global->range - 1];
		ft_putstr_fd("", 1);
		rotate_push(global, min, max);
		i++;
	}
	sort_stacks(global, tab);
}
