/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:14:26 by lcouto            #+#    #+#             */
/*   Updated: 2020/01/27 11:14:35 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char *temp;

	temp = (unsigned char*)b;
	while (n > 0)
	{
		*(temp++) = (unsigned char)c;
		n--;
	}
	return (b);
}
