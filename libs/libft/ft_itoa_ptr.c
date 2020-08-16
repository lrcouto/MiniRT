/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:04:48 by lcouto            #+#    #+#             */
/*   Updated: 2020/05/20 17:09:24 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** I mangled this itoa_base with the sole purpose of printing a pointer
** address. It is ugly but it works for now.
*/

#include "libft.h"
#include <inttypes.h>

static int		get_return_len(uintptr_t n, unsigned int base)
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

char			*ft_itoa_ptr(uintptr_t n, unsigned int base)
{
	char			*str;
	uintptr_t		nb;
	unsigned int	i;
	unsigned int	len;
	unsigned char	c;

	nb = n;
	len = get_return_len(nb, base);
	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = len - 1;
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		c = (nb % base < 10 ? nb % base + 48 : nb % base + 87);
		str[i--] = c;
		nb = nb / base;
	}
	str[len] = '\0';
	return (str);
}
