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

static int		handle_sign(char *s, int i, )
{
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
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
	while (ft_isspace(s[i]) == 1)
		i++;
	i = handle_sign(s, i);
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
