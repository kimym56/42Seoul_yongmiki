/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:59:59 by yongmiki          #+#    #+#             */
/*   Updated: 2021/03/31 17:11:07 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void ft_rev_int_tab(int *tab, int size);
int main(){
	int a = 1, b=2, c=3;
	int t[3] = {1,2,3};
	ft_rev_int_tab(t,3);	
	printf("%d", t[0]);
}