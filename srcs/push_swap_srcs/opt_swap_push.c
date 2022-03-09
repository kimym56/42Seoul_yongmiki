/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_swap_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:12:35 by yongmiki          #+#    #+#             */
/*   Updated: 2022/03/09 21:08:56 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = NULL;
	if (!(*stack_a))
		return ;
	if (*stack_b)
		tmp = (*stack_b);
	ft_lstadd_front(stack_b, ft_lstnew((*stack_a)->content));
	(*stack_b)->next = tmp;
	tmp = (*stack_a)->next;
	ft_lstdelone(*stack_a, lstdel);
	*stack_a = tmp;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!(*stack_b))
		return ;
	tmp = NULL;
	if (*stack_a)
		tmp = (*stack_a);
	ft_lstadd_front(stack_a, ft_lstnew((*stack_b)->content));
	(*stack_a)->next = tmp;
	tmp = (*stack_b)->next;
	ft_lstdelone(*stack_b, lstdel);
	*stack_b = tmp;
}

void	sa(t_list **stack_a)
{
	t_list	*tmp;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	tmp = (*stack_a)->next;
	(*stack_a)->next = tmp->next;
	tmp->next = (*stack_a);
	(*stack_a) = tmp;
}

void	sb(t_list **stack_b)
{
	t_list	*tmp;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	tmp = (*stack_b)->next;
	(*stack_b)->next = tmp->next;
	tmp->next = (*stack_b);
	(*stack_b) = tmp;
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
