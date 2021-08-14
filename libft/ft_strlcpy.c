/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <gsenra-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:18:48 by lcouto            #+#    #+#             */
/*   Updated: 2021/04/09 16:22:52 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;

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
