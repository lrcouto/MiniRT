/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:26:57 by lcouto            #+#    #+#             */
/*   Updated: 2020/01/30 13:24:13 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_split_counter(char const *s, char c)
{
	size_t	splits;
	int		i;

	splits = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		splits++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (splits);
}

static void		*ft_free_strings(char **strings)
{
	if (strings == NULL)
		return (NULL);
	while (*strings != NULL)
		free(*strings++);
	free(strings);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	a;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	a = ft_split_counter(s, c);
	if ((strs = (char**)malloc(sizeof(char*) * (a + 1))) == NULL)
		return (NULL);
	a = 0;
	j = -1;
	while (s[++j])
	{
		if (s[j] == c)
			continue ;
		i = 0;
		while (s[j + i] && s[j + i] != c)
			i++;
		if ((strs[a++] = ft_substr(s, j, i)) == NULL)
			return (ft_free_strings(strs));
		j += i - 1;
	}
	strs[a] = NULL;
	return (strs);
}
