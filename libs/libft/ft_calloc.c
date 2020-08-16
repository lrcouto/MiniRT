/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:13:17 by lcouto            #+#    #+#             */
/*   Updated: 2020/01/27 17:11:36 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void	*ft_calloc(size_t n, size_t size)
{
	size_t	total;
	size_t	*ptr;

	total = n * size;
	if (!(ptr = malloc(total)))
		return (NULL);
	ft_memset(ptr, 0, total);
	return ((void *)ptr);
}
