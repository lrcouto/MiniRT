/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ambi_rgb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 15:30:17 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/13 21:14:01 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int		get_r_ambi(char *line, int check, int *idx, int *rgb)
{
	rgb[0] = get_color(line, *idx);
	*idx = get_index_nocomma(line, *idx);
	check++;
	return (check);
}

static int		get_g_ambi(char *line, int check, int *idx, int *rgb)
{
	rgb[1] = get_color(line, *idx);
	*idx = get_index_nocomma(line, *idx);
	check++;
	return (check);
}

static int		get_b_ambi(char *line, int check, int *idx, int *rgb)
{
	rgb[2] = get_color(line, *idx);
	*idx = get_index(line, *idx);
	check++;
	return (check);
}

int				get_ambi_rgb(char *line, int check, int i, t_ambi *ambi)
{
	int		*rgb;
	int		*idx;

	idx = &i;
	rgb = (int *)ec_malloc((sizeof(int) * 3));
	comma_check(line, *idx, 7);
	while (line[i] != ' ' && line[i] != '\0')
	{
		if ((line[*idx] >= '0' && line[*idx] <= '9') || line[*idx] == '-')
		{
			if (check == 1)
				check = get_r_ambi(line, check, idx, rgb);
			else if (check == 2)
				check = get_g_ambi(line, check, idx, rgb);
			else if (check == 3)
				check = get_b_ambi(line, check, idx, rgb);
		}
		*idx = (line[*idx]) == '\0' ? *idx : *idx + 1;
	}
	if (check != 4)
		errormsg(7);
	ambi->color = fill_color(rgb[0], rgb[1], rgb[2]);
	free(rgb);
	return (check);
}
