/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 23:52:05 by yongmiki          #+#    #+#             */
/*   Updated: 2021/04/08 01:00:47 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>
char *ft_strcpy(char *dest, char *src);
int	main()
{
	char d[20];
	char *s = "asd";
	char* r;
//	printf("%s %s %s\n", d , s , strcpy(d, s));
	r=ft_strcpy(d,s);
	printf("%s",d);
	printf("\n%s",r);
}

