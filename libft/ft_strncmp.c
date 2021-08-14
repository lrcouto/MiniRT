/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <gsenra-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:23:17 by lcouto            #+#    #+#             */
/*   Updated: 2021/04/09 16:24:02 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				ret;
	unsigned char	*a1;
	unsigned char	*a2;

	ret = 0;
	a1 = (unsigned char *)s1;
	a2 = (unsigned char *)s2;
	while ((n != '\0') && (*a1 != '\0') && (*a1 == *a2))
	{
		a1++;
		a2++;
		n--;
	}
	if (n != 0)
	{
		ret = (*a1 - *a2);
	}
	return (ret);
}
