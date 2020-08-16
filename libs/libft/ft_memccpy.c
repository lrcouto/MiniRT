/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:15:45 by lcouto            #+#    #+#             */
/*   Updated: 2020/01/27 11:16:01 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void	*ft_memccpy(void *str_dest, const void *str_src, int c, size_t n)
{
	char			*dest;
	char			*src;
	char			*ptr;
	unsigned int	i;

	dest = (char*)str_dest;
	src = (char*)str_src;
	i = 0;
	ptr = 0;
	while (i < n && ptr == 0)
	{
		dest[i] = src[i];
		if (src[i] == ((char)c))
			ptr = dest + i + 1;
		i++;
	}
	return (ptr);
}
