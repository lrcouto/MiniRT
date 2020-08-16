/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:15:10 by lcouto            #+#    #+#             */
/*   Updated: 2020/01/28 14:45:07 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*copydest;
	char	*copysrc;

	i = 0;
	copydest = (char*)dest;
	copysrc = (char*)src;
	if ((!(dest) && !(src)) && (n > 0))
		return (NULL);
	while (i < n)
	{
		copydest[i] = copysrc[i];
		i++;
	}
	return (copydest);
}
