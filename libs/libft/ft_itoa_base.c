/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:55:20 by lcouto            #+#    #+#             */
/*   Updated: 2020/03/04 17:19:17 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		get_return_len(unsigned int n, unsigned int base)
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

char			*ft_itoa_base(int n, unsigned int base)
{
	char			*str;
	unsigned int	nb;
	unsigned int	i;
	unsigned int	len;
	unsigned char	c;

	if (n < 0)
		nb = (unsigned int)(n * -1);
	else
		nb = (unsigned int)n;
	len = (unsigned int)get_return_len(nb, base);
	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1 + (n < 0 ? 1 : 0)))))
		return (0);
	if (n < 0 && (str[i] = '-'))
		len++;
	i = len - 1;
	while (nb > 0)
	{
		c = (nb % base < 10 ? nb % base + 48 : nb % base + 87);
		str[i--] = c;
		nb = nb / base;
	}
	str[len] = '\0';
	return (str);
}
