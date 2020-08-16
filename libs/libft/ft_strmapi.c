/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:25:07 by lcouto            #+#    #+#             */
/*   Updated: 2020/01/30 14:07:56 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*retstr;
	unsigned int	i;
	int				j;

	if (!s || !f)
		return (NULL);
	i = 0;
	j = ft_strlen((char *)s);
	if (!(retstr = (char *)malloc(((sizeof(char) * j) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		retstr[i] = f(i, s[i]);
		i++;
	}
	retstr[i] = '\0';
	return (retstr);
}
