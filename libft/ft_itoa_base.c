/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <gsenra-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:55:20 by lcouto            #+#    #+#             */
/*   Updated: 2021/04/09 16:02:04 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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

static char	*itoa_base_loop(unsigned int nb, unsigned int base, char *str,
unsigned int len)
{
	unsigned char	c;
	int				i;

	i = len - 1;
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

char	*ft_itoa_base(int n, unsigned int base)
{
	char			*str;
	unsigned int	nb;
	unsigned int	len;

	if (n < 0)
		nb = (unsigned int)(n * -1);
	else
		nb = (unsigned int)n;
	len = (unsigned int)get_return_len(nb, base);
	if (n < 0)
		str = (char *)malloc(sizeof(char) * (len + 1 + 1));
	else
		str = (char *)malloc(sizeof(char) * (len + 1));
	if (n < 0)
	{
		str[0] = '-';
		len++;
	}
	return (itoa_base_loop(nb, base, str, len));
}
