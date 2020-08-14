/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:21:42 by lcouto            #+#    #+#             */
/*   Updated: 2020/08/14 20:09:13 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	get_resolution(char *line)
{
	t_reso	reso;
	int		i;
	int		j;
	int		check;

	i = 1;
	j = 0;
	while (line)
	{
		if (line[i] == ' ')
			i++;
		else if (line[i] >= '0' && line[i] <= '9')
			check++;
			while (line[i] >= '0' && line[i] <= '9')
				i++;
		else
			printf("Error: invalid character.");
			exit(0);
	}
	if (check == 2)
	{
		i = 1;
		while (line)
		{
			//usar o parametro check pra verificar qual valor está sendo passado pra struct (x ou y).
		}
	}
	else
		printf(Error: "resolution parameter must contain two arguments");
		exit(0);
}
