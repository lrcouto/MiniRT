/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:39:34 by gsenra-a          #+#    #+#             */
/*   Updated: 2021/02/15 13:09:36 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int		get_r_plane(char *line, int check, int *idx, int *rgb)
{
	rgb[0] = get_color(line, *idx);
	*idx = get_index_nocomma(line, *idx);
	check++;
	return (check);
}

static int		get_g_plane(char *line, int check, int *idx, int *rgb)
{
	rgb[1] = get_color(line, *idx);
	*idx = get_index_nocomma(line, *idx);
	check++;
	return (check);
}

static int		get_b_plane(char *line, int check, int *idx, int *rgb)
{
	rgb[2] = get_color(line, *idx);
	*idx = get_index(line, *idx);
	check++;
	return (check);
}

static int		get_color_values(char *line, int check, int *idx, int *rgb)
{
	if (check == 6)
		check = get_r_plane(line, check, idx, rgb);
	else if (check == 7)
		check = get_g_plane(line, check, idx, rgb);
	else if (check == 8)
		check = get_b_plane(line, check, idx, rgb);
	return (check);
}

int				get_plane_color(char *line, int check, int i, t_plane *plane)
{
	int		*rgb;
	int		*idx;

	idx = &i;
	comma_check(line, *idx, 20);
	rgb = (int *)ec_malloc((sizeof(int) * 3));
	while (line[i] != ' ' && line[i] != '\0')
	{
		if ((line[*idx] >= '0' && line[*idx] <= '9') || line[*idx] == '-')
			check = get_color_values(line, check, idx, rgb);
		*idx = (line[*idx]) == '\0' ? *idx : *idx + 1;
	}
	if (check != 9)
		errormsg(20);
	plane->color = fill_color(rgb[0], rgb[1], rgb[2]);
	plane->phong = default_phong();
	plane->phong.color = normalize_color(rgb[0], rgb[1], rgb[2]);
	free(rgb);
	return (check);
}
