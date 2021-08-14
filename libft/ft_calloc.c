/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <gsenra-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:13:17 by lcouto            #+#    #+#             */
/*   Updated: 2021/04/09 14:34:43 by gsenra-a         ###   ########.fr       */
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
	ptr = malloc(total);
	ft_memset(ptr, 0, total);
	return ((void *)ptr);
}
