/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:12:43 by yongmiki          #+#    #+#             */
/*   Updated: 2022/03/09 21:04:57 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	freeall(char **res, int j)
{
	int	i;

	i = -1;
	while (++i <= j)
		free(res[i]);
	free(res);
}

static char	*wordcreate(char c, char const *s)
{
	int		i;
	char	*word;

	i = 0;
	while (s[i] && c != s[i])
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = -1;
	while (s[++i] && c != s[i])
		word[i] = s[i];
	word[i] = '\0';
	return (word);
}

static int	countword(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && c == s[i])
			i++;
		if (s[i] && c != s[i])
			count++;
		while (s[i] && c != s[i])
			i++;
	}
	return (count);
}

char	**extend(char **res, int j)
{
	if (res[j - 1] == NULL)
	{
		freeall(res, j - 1);
		return (NULL);
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**res;

	i = 0;
	j = 0;
	res = malloc(sizeof(char *) * (countword(s, c) + 1));
	if (!s || !res)
		return (NULL);
	while (s[i])
	{
		while (s[i] && c == s[i])
			i++;
		if (s[i] && c != s[i])
		{
			res[j++] = wordcreate(c, &s[i]);
			if (extend(res, j) == NULL)
				return (NULL);
			while (s[i] && c != s[i])
				i++;
		}
	}
	res[j] = 0;
	return (res);
}
