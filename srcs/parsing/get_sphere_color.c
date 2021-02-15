/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 17:47:22 by gsenra-a          #+#    #+#             */
/*   Updated: 2021/02/15 13:53:47 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int		get_r_sphere(char *line, int check, int *idx, int *rgb)
{
	rgb[0] = get_color(line, *idx);
	*idx = get_index_nocomma(line, *idx);
	check++;
	return (check);
}

static int		get_g_sphere(char *line, int check, int *idx, int *rgb)
{
	rgb[1] = get_color(line, *idx);
	*idx = get_index_nocomma(line, *idx);
	check++;
	return (check);
}

static int		get_b_sphere(char *line, int check, int *idx, int *rgb)
{
	rgb[2] = get_color(line, *idx);
	*idx = get_index(line, *idx);
	check++;
	return (check);
}

static int		get_color_values(char *line, int check, int *idx, int *rgb)
{
	if (check == 4)
		check = get_r_sphere(line, check, idx, rgb);
	else if (check == 5)
		check = get_g_sphere(line, check, idx, rgb);
	else if (check == 6)
		check = get_b_sphere(line, check, idx, rgb);
	return (check);
}

int				get_sphere_color(char *line, int check, int i, t_sphere *sphere)
{
	int		*rgb;
	int		*idx;

	idx = &i;
	comma_check(line, *idx, 17);
	rgb = (int *)ec_malloc((sizeof(int) * 3));
	while (line[i] != ' ' && line[i] != '\0')
	{
		if ((line[*idx] >= '0' && line[*idx] <= '9') || line[*idx] == '-')
			check = get_color_values(line, check, idx, rgb);
		*idx = (line[*idx]) == '\0' ? *idx : *idx + 1;
	}
	if (check != 7)
		errormsg(17);
	sphere->color = fill_color(rgb[0], rgb[1], rgb[2]);
	sphere->phong = default_phong();
	sphere->phong.color = normalize_color(rgb[0], rgb[1], rgb[2]);
	free(rgb);
	return (check);
}
