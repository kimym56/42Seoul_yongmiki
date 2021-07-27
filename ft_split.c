/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:12:43 by yongmiki          #+#    #+#             */
/*   Updated: 2021/07/25 15:16:37 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_malloc_error(char **array)
{
	unsigned int		i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static unsigned int	ft_split_count_word(char const *s, char c)
{
	unsigned int		i;
	unsigned int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] != c && s[i] != '\0')
			i++;
		count++;
	}
	return (count);
}

static char	*ft_str_n_duplicate(char *str, int n, char **a, unsigned int i)
{
	char				*duplicate;

	duplicate = (char *)malloc((n + 1) * sizeof(char));
	if (!duplicate)
		return (NULL);
	ft_strlcpy(duplicate, str, n + 1);
	a[i] = duplicate;
	return (duplicate);
}

int	norm_malloc(void *target, int size)
{
	void	**pt;

	pt = (void **)target;
	*pt = malloc(size);
	if (*pt == NULL)
		return (0);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	unsigned int		index;
	unsigned int		words;
	char				*start;
	char				**array;

	if (!s)
		return (0);
	index = -1;
	words = ft_split_count_word(s, c);
	if (!norm_malloc(&array, (words + 1) * sizeof(char *)))
		return (NULL);
	while (++index < words)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		start = (char *)s;
		while (*s != c && *s != '\0')
			s++;
		if (!ft_str_n_duplicate(start, s - start, array, index))
			return (ft_malloc_error(array));
	}
	array[index] = 0;
	return (array);
}
