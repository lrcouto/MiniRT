/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 20:44:57 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/03 21:39:29 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

/*
** There is a printf in this function. It's there just to see if the parameters
** are being transfered correctly. Don't forget to remove it.
*/

static void		get_rgb_values(int i, int check, char *line, t_rt *rt)
{
	char	*temp;
	int		j;

	j = 0;
	while (line[i + j] >= '0' && line[i + j] <= '9')
		j++;
	if (line[i + j] == '.')
		errormsg(8);
	temp = ft_substr(line, i, j);
	if (check == 3)
		rt->ambi.red = ft_atoi(temp);
	else if (check == 2)
		rt->ambi.gre = ft_atoi(temp);
	else if (check == 1)
		rt->ambi.blu = ft_atoi(temp);
	free(temp);
	if ((rt->ambi.red < 0 || rt->ambi.red > 255) || (rt->ambi.gre < 0 ||
	rt->ambi.gre > 255) || (rt->ambi.blu < 0 || rt->ambi.blu > 255))
		errormsg(8);
	printf("LIGHT: %f R: %d G: %d B: %d\n", rt->ambi.light, rt->ambi.red,
	rt->ambi.gre, rt->ambi.blu);
}

static int		validation_ok(int i, int check, char *line, t_rt *rt)
{
	int j;

	j = 0;
	if ((line[i] == '0' || line[i] == '1') && (line[i + 1] == '.') &&
	(line[i + 2] >= '0' && line[i + 2] <= '9') &&
	(line[i + 3] == ' ' && check == 4))
	{
		i = i + 3;
		check--;
		return (check);
	}
	while (line[i + j] >= '0' && line[i + j] <= '9')
		j++;
	if (j > 0 && (check > 0 && check < 4))
	{
		get_rgb_values(i, check, line, rt);
		check--;
	}
	return (check);
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
			if (line[i + j] >= '0' && line[i + j] <= '9')
			{
				while (line[i + j] >= '0' && line[i + j] <= '9')
					j++;
				i = i + j;
				j = 0;
			}
			i++;
		}
	}
	else
		errormsg(7);
}

/*
** This function is using an AtoF from stdlib.h that is forbidden. Do not
** forget to write your own AtoF.
*/

static int		get_light(char *line, int check, int i, t_rt *rt)
{
	char	*temp;

	if ((line[i] == '0' || line[i] == '1') && (line[i + 1] == '.') &&
		(line[i + 2] >= '0' && line[i + 2] <= '9') && (line[i + 3] == ' ' &&
		check == 0))
	{
		temp = ft_substr(line, i, i + 2);
		rt->ambi.light = atof(temp);
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
