/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 01:38:46 by yongmiki          #+#    #+#             */
/*   Updated: 2021/04/08 05:01:14 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_lowercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

int		is_uppercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

int		is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int s;

	i = 0;
	s = 1;
	while (str[i])
	{
		if (is_lowercase(str[i]) || is_uppercase(str[i]) || is_number(str[i]))
		{
			if (s == 1)
			{
				s = 0;
				if (is_lowercase(str[i]))
					str[i] -= 32;
			}
			else if (s == 0 && is_uppercase(str[i]))
				str[i] += 32;
		}
		else
			s = 1;
		i++;
	}
	return (str);
}
