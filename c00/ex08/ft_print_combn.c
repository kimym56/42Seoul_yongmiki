/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 21:52:15 by yongmiki          #+#    #+#             */
/*   Updated: 2021/03/31 13:05:20 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		g_n;
int		g_cnt;
int		g_cnt_result;
int		g_ch[10];
int		g_dy[11][10];

void	ft_putint(int n)
{
	char c;

	c = n + '0';
	write(1, &c, 1);
}

int		comb(int n, int r)
{
	if (g_dy[n][r] != 0)
		return (g_dy[n][r]);
	if (n == r || r == 0)
		return (1);
	else
		return (g_dy[n][r] = (comb(n - 1, r - 1) + comb(n - 1, r)));
}

void	dfs(int l, int s)
{
	int i;

	if (l == g_n)
	{
		g_cnt++;
		i = 0;
		while (i < 10)
		{
			if (g_ch[i] == 1)
				ft_putint(i);
			i++;
		}
		if (g_cnt != g_cnt_result)
			write(1, &", ", 2);
		return ;
	}
	i = s + 1;
	while (i < 10)
	{
		g_ch[i] = 1;
		dfs(l + 1, i);
		g_ch[i] = 0;
		i++;
	}
}

void	ft_print_combn(int a)
{
	g_cnt_result = comb(10, a);
	g_n = a;
	dfs(0, -1);
}
