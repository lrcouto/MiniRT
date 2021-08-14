/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <gsenra-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 00:07:24 by gsenra-a          #+#    #+#             */
/*   Updated: 2021/04/09 16:03:27 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include "libft.h"

static int	ft_isspace(char c)
{
	if ((c == '\t') || (c == '\v') || (c == '\f')
		|| (c == '\r') || (c == '\n') || (c == ' '))
		return (1);
	else
		return (0);
}

static int	handle_whitespaces(char *s, int i)
{
	while (ft_isspace(s[i]) == 1)
		i++;
	return (i);
}

static int	handle_sign(char *s, int i)
{
	int	sign;

	if (s[i] == '-')
		sign = -1;
	else
		sign = 1;
	return (sign);
}

double	ft_atof(char *s)
{
	double		val;
	double		power;
	int			i;
	int			sign;

	val = 0.0;
	power = 1.0;
	i = handle_whitespaces(s, 0);
	sign = handle_sign(s, i);
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (ft_isalnum((int)s[i]) == 1)
	{
		val = 10.0 * val + (s[i] - '0');
		i++;
	}
	if (s[i] == '.')
		i++;
	while (ft_isalnum((int)s[i]) == 1)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
		i++;
	}
	return (sign * val / power);
}
