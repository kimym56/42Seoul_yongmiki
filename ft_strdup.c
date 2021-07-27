/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 07:53:05 by yongmiki          #+#    #+#             */
/*   Updated: 2021/07/09 17:08:01 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*result;
	int		i;

	result = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (result == NULL)
		return (NULL);
	i = -1;
	while (src[++i])
		result[i] = src[i];
	result[i] = '\0';
	return (result);
}
