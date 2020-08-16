/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:13:36 by lcouto            #+#    #+#             */
/*   Updated: 2020/01/27 17:36:26 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	int		i;
	char	*ptr;
	char	mystring;

	i = 0;
	mystring = ft_strlen((char *)str);
	if (!(ptr = malloc(sizeof(char) * (mystring + 1))))
		return (NULL);
	while (str[i] != '\0')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
