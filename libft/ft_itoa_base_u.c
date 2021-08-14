/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <gsenra-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:06:58 by lcouto            #+#    #+#             */
/*   Updated: 2021/04/09 14:40:29 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <inttypes.h>

static int	get_return_len(unsigned int n, unsigned int base)
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

char	*ft_itoa_base_u(unsigned int n, unsigned int base)
{
	char			*str;
	unsigned int	nb;
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
