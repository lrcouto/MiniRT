/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 10:56:52 by lcouto            #+#    #+#             */
/*   Updated: 2020/02/03 16:18:28 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	sz;
	int		i;
	int		j;
	char	*joinedstr;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	sz = ft_strlen(s1) + ft_strlen(s2);
	if (!(joinedstr = malloc((sizeof(char) * sz) + 1)))
		return (NULL);
	while (s1[i] != '\0')
	{
		joinedstr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		joinedstr[i + j] = s2[j];
		j++;
	}
	joinedstr[i + j] = '\0';
	return (joinedstr);
}
