/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 22:00:49 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/15 13:00:15 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void		get_reso_values(int i, int check, char *line, t_rt *rt)
{
	char	*temp;
	int		j;

	j = 0;
	while (line[i + j] >= '0' && line[i + j] <= '9')
		j++;
	temp = ft_substr(line, i, j);
	if (check == 2)
		rt->reso.width = ft_atoi(temp);
	else if (check == 1)
		rt->reso.height = ft_atoi(temp);
	free(temp);
}

static void		validate_reso(int i, int check, char *line, t_rt *rt)
{
	int j;

	j = 0;
	if (check == 2)
	{
		i = 1;
		while (line[i] != '\0')
		{
			while (line[i + j] >= '0' && line[i + j] <= '9')
				j++;
			if (j > 0 && check > 0)
			{
				get_reso_values(i, check, line, rt);
				i = i + j;
				j = 0;
				check--;
			}
			i = (line[i] == '\0') ? i : i + 1;
		}
	}
	else
		errormsg(4);
}

static void		check_reso_limits(t_rt *rt, t_mlx *mlx)
{
	int		max_x;
	int		max_y;

	mlx_get_screen_size(mlx->mlx, &max_x, &max_y);
	if (rt->reso.width > max_x)
		rt->reso.width = max_x;
	if (rt->reso.height > max_y)
		rt->reso.height = max_y;
	if (rt->reso.width < 1 || rt->reso.height < 1)
		errormsg(3);
}

void			get_resolution(char *line, t_rt *rt, t_mlx *mlx)
{
	int		i;
	int		check;

	check = 0;
	i = 1;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			i++;
		else if (line[i] >= '0' && line[i] <= '9')
		{
			check++;
			while (line[i] >= '0' && line[i] <= '9')
				i++;
		}
		else if ((!(line[i] >= '0' && line[i] <= '9')) || (!(line[i] == ' ')))
			errormsg(5);
	}
	validate_reso(i, check, line, rt);
	check_reso_limits(rt, mlx);
}
