/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 02:53:14 by yongmiki          #+#    #+#             */
/*   Updated: 2021/04/08 04:21:26 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *g_hex = "0123456789abcdef";
char g_str[16];

void	print_addr(long long addr, int cnt)
{
	if (!addr)
	{
		while (cnt++ < 16)
			write(1, &"0", 1);
		return ;
	}
	print_addr(addr >> 4, cnt + 1);
	write(1, &g_hex[addr % 16], 1);
}

void	print_hex(unsigned char *ptr, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (i % 2 == 0)
			write(1, &" ", 1);
		g_str[i] = (32 <= ptr[i] && ptr[i] <= 126) ? ptr[i] : '.';
		write(1, &g_hex[(int)ptr[i] / 16], 1);
		write(1, &g_hex[(int)ptr[i] % 16], 1);
		i++;
	}
	while (i < 16)
	{
		if (i % 2 == 0)
			write(1, &" ", 1);
		write(1, &"  ", 2);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*ptr;
	int				len;

	i = 0;
	while (size)
	{
		len = (size >= 16) ? 16 : size;
		ptr = (unsigned char*)addr + i;
		print_addr((long long)ptr, 0);
		write(1, &":", 1);
		print_hex(ptr, len);
		write(1, &" ", 1);
		write(1, g_str, len);
		write(1, &"\n", 1);
		size -= len;
		i += 16;
	}
	return (addr);
}
