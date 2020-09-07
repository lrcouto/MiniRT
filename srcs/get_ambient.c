/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 21:59:23 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/06 21:59:26 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static int		validation_ok(int i, int check, char *line, t_rt *rt)
{
	int j;

	j = 0;
	while (line[i + j] >= '0' && line[i + j] <= '9')
		j++;
	if (j > 0 && (check > 0 && check < 4))
	{
		ambi_rgb_values(i, check, line, rt);
		check--;
	}
	return (check);
}

static int		ambi_get_index(int i, int j, char *line)
{
	if (line[i + j] >= '0' && line[i + j] <= '9')
	{
		while (line[i + j] >= '0' && line[i + j] <= '9')
			j++;
		i = i + j;
	}
	return (i);
}

static void		validate_ambi(int i, int check, char *line, t_rt *rt)
{
	int		j;

	j = 0;
	if (check == 4)
	{
		i = 1;
		while (line[i] != '\0')
		{
			if ((line[i] == '0' || line[i] == '1') && (line[i + 1] == '.') &&
			(line[i + 2] >= '0' && line[i + 2] <= '9') &&
			(line[i + 3] == ' ' && check == 4))
			{
				i = i + 3;
				check--;
			}
			check = validation_ok(i, check, line, rt);
			i = ambi_get_index(i, j, line);
			i = (line[i] == '\0') ? i : i + 1;
		}
	}
	else
		errormsg(7);
}

static int		get_light(char *line, int check, int i, t_rt *rt)
{
	char	*temp;

	if ((line[i] == '0' || line[i] == '1') && (line[i + 1] == '.') &&
		(line[i + 2] >= '0' && line[i + 2] <= '9') && (line[i + 3] == ' ' &&
		check == 0))
	{
		temp = ft_substr(line, i, i + 2);
		rt->ambi.light = ft_atof(temp);
		check++;
		free(temp);
		return (check);
	}
	else
		errormsg(6);
	return (0);
}

void			get_ambient(char *line, t_rt *rt)
{
	int		i;
	int		check;

	check = 0;
	i = 1;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			i++;
		else if ((line[i] >= '0' && line[i] <= '9'))
		{
			if (check == 0)
				check = get_light(line, check, i, rt);
			else
				check++;
			while ((line[i] >= '0' && line[i] <= '9') || line[i] == '.')
				i++;
		}
		else if ((!(line[i] >= '0' && line[i] <= '9')) || (!(line[i] == ' ')))
			errormsg(5);
	}
	validate_ambi(i, check, line, rt);
}
