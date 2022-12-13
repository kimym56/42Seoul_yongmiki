/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:07:17 by yongmiki          #+#    #+#             */
/*   Updated: 2021/07/09 17:11:58 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Locates the first occurrence of the null-terminated string 'needle'
** in the string 'haystack', where not more than 'len' characters are searched.
** If 'needle' is an empty string, 'haystack' is	returned;
** if 'needle' occurs nowhere in 'haystack', NULL is	returned;
** otherwise a pointer to the first character of the first occurrence of
** 'needle' is returned.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*a;
	char	*b;
	size_t	len_needle;

	if (!*needle)
		return ((char *)haystack);
	len_needle = ft_strlen(needle);
	if (!ft_strlen(haystack) || len < len_needle)
		return (0);
	len -= --len_needle;
	while (len-- && *haystack)
	{
		a = (char *)haystack;
		b = (char *)needle;
		while (*b && *a == *b)
		{
			++a;
			++b;
		}
		if (*b == 0)
			return ((char *)haystack);
		++haystack;
	}
	return (0);
}
