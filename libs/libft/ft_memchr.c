/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:17:19 by lcouto            #+#    #+#             */
/*   Updated: 2020/01/27 14:01:50 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	*ft_memchr(const void *arr, int c, size_t n)
{
	const unsigned char *p;

	if (n)
	{
		p = arr;
		while (n)
		{
			if (*p++ == (unsigned char)c)
			{
				return ((void *)(p - 1));
			}
			n--;
		}
	}
	return (NULL);
}
