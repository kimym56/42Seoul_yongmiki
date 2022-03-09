/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:29:36 by yongmiki          #+#    #+#             */
/*   Updated: 2022/03/09 21:12:54 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_same(t_list *lst, int val)
{
	if (!lst)
		return (0);
	while (lst)
	{
		if ((lst)->content == val)
			return (1);
		lst = (lst)->next;
	}
	return (0);
}

long long	get_lst_content(t_list *stack, int pos)
{
	int	i;

	i = 0;
	while (i < pos && stack)
	{
		i++;
		stack = stack->next;
	}
	if (i == pos)
		return (stack->content);
	return (-2147483649);
}

int	ft_verif(t_list *lst, t_list *lst2)
{
	long long	tmp;

	tmp = -2147483649;
	if (!lst || lst2)
		return (0);
	while (lst)
	{
		if (lst->content < tmp && tmp != -2147483649)
		{
			return (0);
		}
		tmp = lst->content;
		lst = (lst)->next;
	}
	return (1);
}

void	lstdel(int content)
{
	content = 0;
}
