/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 15:03:05 by gsenra-a          #+#    #+#             */
/*   Updated: 2021/02/15 13:35:51 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int		get_r_cylinder(char *line, int check, int *idx, int *rgb)
{
	rgb[0] = get_color(line, *idx);
	*idx = get_index_nocomma(line, *idx);
	check++;
	return (check);
}

static int		get_g_cylinder(char *line, int check, int *idx, int *rgb)
{
	rgb[1] = get_color(line, *idx);
	*idx = get_index_nocomma(line, *idx);
	check++;
	return (check);
}

static int		get_b_cylinder(char *line, int check, int *idx, int *rgb)
{
	rgb[2] = get_color(line, *idx);
	*idx = get_index(line, *idx);
	check++;
	return (check);
}

static int		get_color_values(char *line, int check, int *idx, int *rgb)
{
	if (check == 8)
		check = get_r_cylinder(line, check, idx, rgb);
	else if (check == 9)
		check = get_g_cylinder(line, check, idx, rgb);
	else if (check == 10)
		check = get_b_cylinder(line, check, idx, rgb);
	return (check);
}

int				get_cylinder_color(char *line, int check, int i,
t_cylinder *cylinder)
{
	int		*rgb;
	int		*idx;

	idx = &i;
	rgb = (int *)ec_malloc((sizeof(int) * 3));
	comma_check(line, *idx, 26);
	while (line[i] != ' ' && line[i] != '\0')
	{
		if ((line[*idx] >= '0' && line[*idx] <= '9') || line[*idx] == '-')
			check = get_color_values(line, check, idx, rgb);
		*idx = (line[*idx]) == '\0' ? *idx : *idx + 1;
	}
	if (check != 11)
		errormsg(26);
	cylinder->color = fill_color(rgb[0], rgb[1], rgb[2]);
	cylinder->phong = default_phong();
	cylinder->phong.color = normalize_color(rgb[0], rgb[1], rgb[2]);
	free(rgb);
	return (check);
}
