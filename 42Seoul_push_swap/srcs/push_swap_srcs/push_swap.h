/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:23:41 by yongmiki          #+#    #+#             */
/*   Updated: 2022/03/09 21:09:23 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_global
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		range;
	int		size;
}			t_global;

/*
**	Checks Errors Arguments
*/

int			is_same(t_list *lst, int val);
int			is_integers(char *str);
int			free_table(char **str, int j);
int			check_args(char **av, t_list **stack_a);
int			countnum(char **av);

/*
**	Opperator
*/
void		do_opt(char *opt, t_list **stack,
				void (*f)(t_list **stack));
void		do_push(char *opt, t_global *global,
				void (*f)(t_list **stack_a, t_list **stack_b));
void		pa(t_list **stack_a, t_list **stack_b);
void		pb(t_list **stack_a, t_list **stack_b);
void		ss(t_list **stack_a, t_list **stack_b);
void		sa(t_list **stack_a);
void		sb(t_list **stack_b);
void		rb(t_list **stack_b);
void		ra(t_list **stack_a);
void		rrb(t_list **stack_b);
void		rra(t_list **stack_a);
void		rr_rrr(t_list **stack_a, t_list **stack_b, int type);
/*
**		Algos
*/

void		sort_three(t_global *global);
void		algo_three(t_global *global, int one, int two, int three);
void		sort_five(t_global *global);
void		main_algo(t_global *global);
void		sort_stacks(t_global *global, int *tab);
void		ft_sort_int_tab(int *tab, int size);
int			*fill_tab(t_list *lst, int *tab, int size);
int			get_max_pos(t_list *lst);
int			found_range(int size);
void		put_max_top(int pos, t_global *global);

/*
**	Utils
*/

void		errors(int type, t_list **stack_a, t_list **stack_b);
void		lstdel(int content);
int			ft_atoi_modif(const char *str, int *max);
int			ft_verif(t_list *lst, t_list *lst2);
long long	get_lst_content(t_list *stack, int pos);

#endif