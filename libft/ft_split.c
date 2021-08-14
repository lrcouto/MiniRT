/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <gsenra-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:17:44 by gsenra-a          #+#    #+#             */
/*   Updated: 2021/04/09 16:19:40 by gsenra-a         ###   ########.fr       */
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

static void	*ft_free_strings(char **strings)
{
	if (strings == NULL)
		return (NULL);
	while (*strings != NULL)
		free(*strings++);
	free(strings);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	a;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	a = ft_split_counter(s, c);
	strs = (char **)malloc(sizeof(char *) * (a + 1));
	a = 0;
	j = -1;
	while (s[++j])
	{
		if (s[j] == c)
			continue ;
		i = 0;
		while (s[j + i] && s[j + i] != c)
			i++;
		strs[a++] = ft_substr(s, j, i);
		if (strs == NULL)
			return (ft_free_strings(strs));
		j += i - 1;
	}
	strs[a] = NULL;
	return (strs);
}
