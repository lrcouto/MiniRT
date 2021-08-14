/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <gsenra-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:04:48 by lcouto            #+#    #+#             */
/*   Updated: 2021/04/09 15:53:40 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** I mangled this itoa_base with the sole purpose of printing a pointer
** address. It is ugly but it works for now.
*/

#include "libft.h"
#include <inttypes.h>

static int	get_return_len(uintptr_t n, unsigned int base)
{
	unsigned int	len;

	len = 0;
	while (n >= base)
	{
		n /= base;
		++len;
	}
	return (len + 1);
}

char	*ft_itoa_ptr(uintptr_t n, unsigned int base)
{
	char			*str;
	uintptr_t		nb;
	unsigned int	i;
	unsigned int	len;
	unsigned char	c;

	nb = n;
	len = get_return_len(nb, base);
	i = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	i = len - 1;
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		if (nb % base < 10)
			c = nb % base + 48;
		else
			c = nb % base + 87;
		str[i--] = c;
		nb = nb / base;
	}
	str[len] = '\0';
	return (str);
}
