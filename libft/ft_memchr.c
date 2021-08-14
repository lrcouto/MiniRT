/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <gsenra-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:17:19 by lcouto            #+#    #+#             */
/*   Updated: 2021/04/09 16:14:31 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	*ft_memchr(const void *arr, int c, size_t n)
{
	const unsigned char	*p;

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
