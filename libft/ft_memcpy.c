/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <gsenra-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:15:10 by lcouto            #+#    #+#             */
/*   Updated: 2021/04/09 16:15:26 by gsenra-a         ###   ########.fr       */
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
	copydest = (char *)dest;
	copysrc = (char *)src;
	if ((!(dest) && !(src)) && (n > 0))
		return (NULL);
	while (i < n)
	{
		copydest[i] = copysrc[i];
		i++;
	}
	return (copydest);
}
