/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_gnl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 16:14:49 by lcouto            #+#    #+#             */
/*   Updated: 2020/08/19 18:27:40 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This is a slight variation of ft_strdup that works better with get_next_line.
** Libft memory allocations are commonly "protected" with a condition to return
** null if the allocation fails. This sometimes causes get_next_line to crash.
*/

char	*ft_strdup_gnl(const char *s1)
{
	char			*copy;
	unsigned int	i;
	unsigned int	s1_len;

	i = 0;
	s1_len = ft_strlen(s1);
	copy = (char *)malloc((s1_len + 1) * sizeof(*copy));
	if (copy == 0)
		return (0);
	while (s1[i] != '\0')
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
