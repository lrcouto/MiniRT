/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:14:45 by lcouto            #+#    #+#             */
/*   Updated: 2020/01/27 11:15:01 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void	*ft_bzero(void *b, size_t n)
{
	unsigned char *temp;

	temp = (unsigned char*)b;
	while (n > 0)
	{
		*(temp++) = '\0';
		n--;
	}
	return (b);
}
