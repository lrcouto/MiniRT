/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <gsenra-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 16:42:25 by gsenra-a          #+#    #+#             */
/*   Updated: 2020/09/04 17:18:35 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "../include/minirt.h"

static int		ft_isspace(char c)
{
	if ((c == '\t') || (c == '\v') || (c == '\f') ||
	(c == '\r') || (c == '\n') || (c == ' '))
		return (1);
	else
		return (0);
}

static int		handle_whitespaces(char *s, int i)
{
	while (ft_isspace(s[i]) == 1)
		i++;
	return (i);
}

static int		handle_sign(char *s, int i)
{
	int sign;

	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	sign = sign + i;
	return (sign);
}

double			ft_atof(char s[])
{
	double		val;
	double		power;
	int			i;
	int			sign;

	i = 0;
	val = 0.0;
	power = 1.0;
	i = handle_whitespaces(s, i);
	sign = handle_sign(s, i);
	i = (sign < 0) ? (sign * -1) : sign;
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
