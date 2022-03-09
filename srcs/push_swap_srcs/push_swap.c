/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:22:56 by yongmiki          #+#    #+#             */
/*   Updated: 2022/03/09 21:57:40 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int			count;
	t_list		*stack_a;
	t_list		*stack_b;
	t_global	global;

	stack_a = NULL;
	stack_b = NULL;
	count = countnum(av);
	if (count == -1 || ac == 1 || check_args(av, &stack_a) == -1)
		errors(1, &stack_a, &stack_b);
	global.stack_a = stack_a;
	global.stack_b = stack_b;
	global.size = ft_lstsize(global.stack_a);
	if (ft_verif(global.stack_a, NULL))
		;
	else if (global.size <= 5)
		sort_five(&global);
	else
		main_algo(&global);
	ft_lstclear(&global.stack_a, lstdel);
	ft_lstclear(&global.stack_b, lstdel);
	return (0);
}
