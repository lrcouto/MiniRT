/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <gsenra-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:26:29 by lcouto            #+#    #+#             */
/*   Updated: 2021/04/09 15:54:31 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	get_return_len(unsigned int n)
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

char	*ft_itoa_u(unsigned int n)
{
	char			*str;
	unsigned int	nb;
	unsigned int	i;
	unsigned int	len;

	nb = n;
	len = (unsigned int)get_return_len(nb);
	i = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
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
