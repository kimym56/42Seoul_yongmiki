/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoslee <hyoslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:49:57 by hyoslee           #+#    #+#             */
/*   Updated: 2021/04/05 22:11:26 by hyoslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	*ft_print_memory(void *addr, unsigned int size);

int main()
{
	char str[100] = "Bonjour les aminches\3\3\3c est fou\5tout\10ce qu on peut faire avec...print_memory\1\1\1\1\1\1\1lol\5lol. .";
	int i;

	i = 0;
	while (str[i])
		i++;
	ft_print_memory(str, i);

}
