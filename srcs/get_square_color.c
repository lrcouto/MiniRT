/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_square_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:57:27 by gsenra-a          #+#    #+#             */
/*   Updated: 2020/09/11 15:44:47 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static int	get_r_square(char *line, int check, int *idx, int *rgb)
{
	rgb[0] = get_color(line, *idx);
	*idx = get_index_nocomma(line, *idx);
	check++;
	return (check);
}

static int	get_g_square(char *line, int check, int *idx, int *rgb)
{
	rgb[1] = get_color(line, *idx);
	*idx = get_index_nocomma(line, *idx);
	check++;
	return (check);
}

static int	get_b_square(char *line, int check, int *idx, int *rgb)
{
	rgb[2] = get_color(line, *idx);
	*idx = get_index(line, *idx);
	check++;
	return (check);
}

int			get_square_color(char *line, int check, int i, t_square *square)
{
	int		*rgb;
	int		*idx;

	idx = &i;
	rgb = (int *)malloc((sizeof(int) * 3));
	while (line[i] != ' ' && line[i] != '\0')
	{
		if ((line[*idx] >= '0' && line[*idx] <= '9') || line[*idx] == '-')
		{
			if (check == 5)
				check = get_r_square(line, check, idx, rgb);
			else if (check == 6)
				check = get_g_square(line, check, idx, rgb);
			else if (check == 7)
				check = get_b_square(line, check, idx, rgb);
		}
		*idx = (line[*idx]) == '\0' ? *idx : *idx + 1;
	}
	if (check != 8)
		errormsg(22);
	square->color = fill_color(rgb[0], rgb[1], rgb[2]);
	free(rgb);
	return (check);
}
