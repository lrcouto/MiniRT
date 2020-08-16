/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:06:58 by lcouto            #+#    #+#             */
/*   Updated: 2020/05/20 17:08:00 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <inttypes.h>

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

char			*ft_itoa_base_u(unsigned int n, unsigned int base)
{
	char			*str;
	unsigned int	nb;
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
