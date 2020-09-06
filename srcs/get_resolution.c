/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:21:42 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/06 19:46:30 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

/*
** There is a printf in this function. It's there just to see if the parameters
** are being transfered correctly. Don't forget to remove it.
*/

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
	printf("RESO WIDTH: %d RESO HEIGHT: %d\n", rt->reso.width, rt->reso.height);
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

void			get_resolution(char *line, t_rt *rt)
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
}
