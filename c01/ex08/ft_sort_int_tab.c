/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:16:28 by yongmiki          #+#    #+#             */
/*   Updated: 2021/03/31 17:49:57 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;
	int rem;

	i = 1;
	while (i < size)
	{
		j = i;
		rem = tab[j];
		while (--j >= 0 && rem < tab[j])
		{
			tab[j + 1] = tab[j];
			tab[j] = rem;
		}
		i++;
	}
}
