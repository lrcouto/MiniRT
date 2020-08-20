/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 16:54:59 by lcouto            #+#    #+#             */
/*   Updated: 2020/08/20 19:48:29 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static void		get_rgb_values(int i, int check, char *line, t_rt *rt)
{
	char	*temp;
	int		j;

	j = 0;
	while (line[i + j] >= '0' && line[i + j] <= '9')
		j++;
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
	{
		ft_putstr_fd("Error: RGB values must be between 0 and 255\n", 1);
		exit(0);
	}
	printf("LIGHT: %f R: %d G: %d B: %d\n", rt->ambi.light, rt->ambi.red,
	rt->ambi.gre, rt->ambi.blu);
}

static void		validate_ambi(int i, int check, char *line, t_rt *rt)
{
	int j;

	j = 0;
	if (check == 4)
	{
		i = 1;
		while (line[i] != '\0')
		{
			if ((line[i] == '0' || line[i] == '1') && (line[i + 1] == '.') &&
			(line[i + 2] >= '0' && line[i + 2] <= '9') && (line[i + 3] == ' ' &&
			check == 4))
			{
				i = i + 3;
				check--;
			}
			while (line[i + j] >= '0' && line[i + j] <= '9')
				j++;
			if (j > 0 && (check > 0 && check < 4))
			{
				get_rgb_values(i, check, line, rt);
				i = i + j;
				j = 0;
				check--;
			}
			i++;
		}
	}
	else
	{
		ft_putstr_fd("Error: resolution must receive two parameters.\n", 1);
		exit(0);
	}
}

/*
** This function is using an AtoF from stdlib.h that is forbidden. Do not
** forget to write your own AtoF.
*/

static int		get_light(char *line, int check, int i, t_rt *rt)
{
	char *temp;

	if ((line[i] == '0' || line[i] == '1') && (line[i + 1] == '.') &&
		(line[i + 2] >= '0' && line[i + 2] <= '9') && (line[i + 3] == ' ' &&
		check == 0))
	{
		temp = ft_substr(line, i, i + 2);
		rt->ambi.light = atof(temp);
		free(temp);
		return (check + 1);
	}
	else
	{
		ft_putstr_fd("Error: ambient light intensity must be between 0.0 and 1.0\n", 1);
		exit(0);
	}
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
		else if ((line[i] >= '0' && line[i] <= '9') &&
		check == 0)
		{
			check = get_light(line, check, i, rt);
			i = i + 3;
		}
		else if (line[i] >= '0' && line[i] <= '9')
		{
			check++;
			while (line[i] >= '0' && line[i] <= '9')
				i++;
		}
		else if ((!(line[i] >= '0' && line[i] <= '9')) || (!(line[i] == ' ')))
		{
			ft_putstr_fd("Error: invalid character.\n", 1);
			exit(0);
		}
	}
	validate_ambi(i, check, line, rt);
}
