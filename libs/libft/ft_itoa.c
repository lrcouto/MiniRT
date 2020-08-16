/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:39:55 by lcouto            #+#    #+#             */
/*   Updated: 2020/01/29 18:41:07 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		get_return_len(unsigned int n)
{
	unsigned int	len;

	len = 0;
	while (n >= 10)
	{
		n /= 10;
		++len;
	}
	return (len + 1);
}

char			*ft_itoa(int n)
{
	char			*str;
	unsigned int	nb;
	unsigned int	i;
	unsigned int	len;

	if (n < 0)
		nb = (unsigned int)(n * -1);
	else
		nb = (unsigned int)n;
	len = (unsigned int)get_return_len(nb);
	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1 + (n < 0 ? 1 : 0)))))
		return (0);
	if (n < 0 && (str[i] = '-'))
		len++;
	i = len - 1;
	while (nb >= 10)
	{
		str[i--] = (char)(nb % 10 + 48);
		nb /= 10;
	}
	str[i] = (char)(nb % 10 + 48);
	str[len] = '\0';
	return (str);
}
