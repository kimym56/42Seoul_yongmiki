/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 20:28:10 by yongmiki          #+#    #+#             */
/*   Updated: 2021/03/29 20:52:22 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write(int a, int b)
{
	char a1;
	char a2;
	char b1;
	char b2;

	a1 = (a / 10) + '0';
	a2 = (a % 10) + '0';
	b1 = (b / 10) + '0';
	b2 = (b % 10) + '0';
	write(1, &a1, 1);
	write(1, &a2, 1);
	write(1, &" ", 1);
	write(1, &b1, 1);
	write(1, &b2, 1);
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_write(a, b);
			if (!(a == 98 && b == 99))
				write(1, &", ", 2);
			b++;
		}
		a++;
	}
}
