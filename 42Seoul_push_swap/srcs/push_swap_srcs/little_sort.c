/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:00:40 by yongmiki          #+#    #+#             */
/*   Updated: 2022/03/09 21:08:14 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_three(t_global *global, int one, int two, int three)
{
	if (one < two && two < three)
		return ;
	else if (three < one && one < two)
		do_opt("rra", &global->stack_a, &rra);
	else if (two < three && three < one)
		do_opt("ra", &global->stack_a, &ra);
	else if (one < three && three < two)
	{
		do_opt("rra", &global->stack_a, &rra);
		do_opt("sa", &global->stack_a, &sa);
	}
	else if (three < two && two < one)
	{
		do_opt("sa", &global->stack_a, &sa);
		do_opt("rra", &global->stack_a, &rra);
	}
	else
		do_opt("sa", &global->stack_a, &sa);
}

void	sort_three(t_global *global)
{
	int	one;
	int	two;
	int	three;

	if (!global->stack_a)
		return ;
	one = global->stack_a->content;
	if (!(global->stack_a->next))
		return ;
	two = global->stack_a->next->content;
	if (!global->stack_a->next->next)
	{
		if (one > two)
			do_opt("sa", &global->stack_a, &sa);
		return ;
	}
	three = global->stack_a->next->next->content;
	algo_three(global, one, two, three);
}

void	put_min_top(int pos, t_global *global)
{
	int	size;

	size = ft_lstsize(global->stack_a);
	if (pos > size / 2)
	{
		pos = size - pos;
		while (pos-- != 0)
			do_opt("rra", &global->stack_a, &rra);
	}
	else if (pos <= size / 2)
	{
		while (pos-- != 0)
			do_opt("ra", &global->stack_a, &ra);
	}
}

int	get_min_pos(t_list *lst)
{
	int		i;
	int		save;
	int		min;
	t_list	*tmp;

	tmp = lst;
	i = 0;
	min = tmp->content;
	save = 0;
	while (tmp)
	{
		if (tmp->content <= min)
		{
			save = i;
			min = tmp->content;
		}
		tmp = tmp->next;
		i++;
	}
	ft_lstclear(&tmp, &lstdel);
	return (save);
}

void	sort_five(t_global *global)
{
	int	size;
	int	i;

	i = -1;
	size = ft_lstsize(global->stack_a);
	while (++i < (size - 3))
	{
		put_min_top(get_min_pos(global->stack_a), global);
		do_push("pb", global, &pb);
	}
	sort_three(global);
	while (ft_lstsize(global->stack_b))
		do_push("pa", global, &pa);
}
