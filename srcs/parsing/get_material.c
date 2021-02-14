/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_material.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:52:39 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/12 21:58:02 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int	ft_get_reflect(char *line, int check, int i, t_phong *phong)
{
	double reflect;

	while (line[i] != ' ' && line[i] != '\0')
	{
		if ((line[i] == '1' || line[i] == '0') && check == 2)
		{
			reflect = get_coord(line, i);
			i = get_index(line, i);
			check++;
		}
	}
	if (reflect > 1 || reflect < 0)
		errormsg(42);
	phong->reflect = reflect;
	return (check);
}

static int	ft_get_shininess(char *line, int check, int i, t_phong *phong)
{
	double shininess;

	while (line[i] != ' ' && line[i] != '\0')
	{
		if ((line[i] >= '0' || line[i] <= '9') && check == 1)
		{
			shininess = get_coord(line, i);
			i = get_index(line, i);
			check++;
		}
		i++;
	}
	if (shininess > 500 || shininess < 0)
		errormsg(41);
	phong->shininess = shininess;
	return (check);
}

static int	ft_get_specular(char *line, int check, int i, t_phong *phong)
{
	double specular;

	while (line[i] != ' ' && line[i] != '\0')
	{
		if ((line[i] == '1' || line[i] == '0') && check == 0)
		{
			specular = get_coord(line, i);
			i = get_index(line, i);
			check++;
		}
		i++;
	}
	if (specular > 1 || specular < 0)
		errormsg(40);
	phong->specular = specular;
	return (check);
}

static int	material_values(char *line, int i, int *chkptr, t_phong *phong)
{
	if (*chkptr == 0)
	{
		*chkptr = ft_get_specular(line, *chkptr, i, phong);
		i = get_index(line, i);
	}
	else if (*chkptr == 1)
	{
		*chkptr = ft_get_shininess(line, *chkptr, i, phong);
		i = get_index(line, i);
	}
	else if (*chkptr == 2)
	{
		*chkptr = ft_get_reflect(line, *chkptr, i, phong);
		i = get_index(line, i);
	}
	if (*chkptr == 3 && line[i] != '\0')
		errormsg(44);
	return (i);
}

void		get_material(t_phong *phong, char *line, int i)
{
	int	check;
	int *chkptr;

	check = 0;
	chkptr = &check;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			i++;
		else if (line[i] >= '0' && line[i] <= '9')
			i = material_values(line, i, chkptr, phong);
		else if ((!(line[i] >= '0' && line[i] <= '9')) || (!(line[i] == ' ')))
			errormsg(5);
	}
}
