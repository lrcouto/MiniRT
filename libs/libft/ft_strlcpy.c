/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:18:48 by lcouto            #+#    #+#             */
/*   Updated: 2020/01/27 19:26:45 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t len;

	len = 0;
	if (!dest || !src)
		return (0);
	while (src[len] != '\0')
		++len;
	if (len + 1 < size)
		ft_memcpy(dest, (char *)src, len + 1);
	else if (size != 0)
	{
		ft_memcpy(dest, (char *)src, size - 1);
		dest[size - 1] = '\0';
	}
	return (len);
}
