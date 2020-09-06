/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <gsenra-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 19:16:02 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/05 21:31:27 bygsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static void		push_camera(t_cam head, t_cam new_cam)
{
	t_cam *current;

	current = &head;
	while (current->next != NULL)
		current = current->next;
	current->next = (t_cam *) malloc(sizeof(t_cam));
	current->next = &new_cam;
}

static int		get_index_nocomma(char *line, int i)
{
	int j;

	j = i;
	while ((line[j] >= '0' && line[j] <= '9') ||
			line[j] == '.' || line[j] == '-')
		j++;
	return (j);
}

static int		get_index(char *line, int i)
{
	int j;

	j = i;
	while ((line[j] >= '0' && line[j] <= '9') ||
			line[j] == '.' || line[j] == ',' || line[j] == '-')
		j++;
	if (line[j] != ' ' && line[j] != '\0')
		errormsg(5);
	return (j);
}

static t_coord			fill_coord(double x, double y, double z)
{
	t_coord	fill;

	fill.x = x;
	fill.y = y;
	fill.z = z;
	return (fill);
}

static int		get_view(char *line, int check, int i, t_cam *cam)
{
	double	x;
	double	y;
	double	z;

	while (line[i] != ' ' && line[i] != '\0')
	{
		if (((line[i] >= '0' && line[i] <= '9') ||
			line[i] == '-') && check == 0)
		{
			x = get_coord(line, i);
			i = get_index_nocomma(line, i);
			check++;
		}
		else if (((line[i] >= '0' && line[i] <= '9') ||
				line[i] == '-') && check == 1)
		{
			y = get_coord(line, i);
			i = get_index_nocomma(line, i);
			check++;
		}
		else if (((line[i] >= '0' && line[i] <= '9') ||
				line[i] == '-') && check == 2)
		{
			z = get_coord(line, i);
			i = get_index_nocomma(line, i);
			check++;
		}
		i++;
	}
	if (check != 3)
		errormsg(12);
	cam->view = fill_coord(x, y, z);
	return (check);
}

static int		get_pos(char *line, int check, int i,t_cam *cam)
{
	double	x;
	double	y;
	double	z;

	while (line[i] != ' ' && line[i] != '\0')
	{
		if ((line[i] == '1' || line[i] == '0') && check == 3)
		{
			x = get_coord(line, i);
			i = get_index_nocomma(line, i);
			check++;
		}
		else if ((line[i] == '1' || line[i] == '0') && check == 4)
		{
			y = get_coord(line, i);
			i = get_index_nocomma(line, i);
			check++;
		}
		else if ((line[i] == '1' || line[i] == '0') && check == 5)
		{
			z = get_coord(line, i);
			i = get_index_nocomma(line, i);
			check++;
		}
		i++;
	}
	if ((x > 1 || x < -1) || (y > 1 || y < -1) || (z > 1 || z < -1))
		errormsg(13);
	if (check != 6)
		errormsg(13);
	cam->pos = fill_coord(x, y, z);
	return (check);
}

static int		get_fov(char *line, int check, int i,t_cam *cam)
{
	char	*temp;
	int		j;

	j = i;
	while (line[j] != '\0')
	{
		if (line[j] < '0' || line[j] > '9')
			errormsg(11);
		j++;
	}
	temp = ft_substr(line, i, j);
	cam->fov = ft_atoi(temp);
	if (cam->fov < 0 || cam->fov > 180)
		errormsg(11);
	check++;
	free(temp);
	return (check);
}

void			get_camera(char *line, t_rt *rt)
{
	int		i;
	int		check;
	t_cam	cam;

	check = 0;
	i = 1;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			i++;
		else if ((line[i] >= '0' && line[i] <= '9') || line[i] == '-')
		{
			if (check == 0)
			{
				check = get_view(line, check, i, &cam);
				i = get_index(line, i);
			}
			else if (check == 3)
			{
				check = get_pos(line, check, i, &cam);
				i = get_index(line, i);
			}
			else if (check == 6)
			{
				check = get_fov(line, check, i, &cam);
				i = get_index(line, i);
			}
		}
		else if ((!(line[i] >= '0' && line[i] <= '9')) || (!(line[i] == ' ')))
			errormsg(5);
	}
	push_camera(rt->cam, &cam);
}
