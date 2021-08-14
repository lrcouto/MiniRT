/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <gsenra-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:59:21 by lcouto            #+#    #+#             */
/*   Updated: 2021/04/09 16:28:49 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	substr = ft_calloc(len + 1, sizeof(char));
	if (s == NULL || substr == NULL)
		return (NULL);
	while (s[i] && i < len && (start + i < ft_strlen(s)))
	{
		substr[i] = s[start + i];
		i++;
	}
	return (substr);
}
