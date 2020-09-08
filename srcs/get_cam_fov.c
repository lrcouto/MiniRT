/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cam_fov.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 21:59:34 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/08 18:13:20 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int		get_cam_fov(char *line, int check, int i, t_cam *cam)
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
