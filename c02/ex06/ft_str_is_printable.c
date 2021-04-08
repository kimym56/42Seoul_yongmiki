/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 01:11:16 by yongmiki          #+#    #+#             */
/*   Updated: 2021/04/08 04:45:06 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (*str >= 32 && *str <= 126)
		{
			str++;
			continue;
		}
		else
			return (0);
	}
	return (1);
}
