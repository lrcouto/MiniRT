/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genra-a <gsecora-a@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 16:26:27 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/06 01:05:49 by gsecora-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static void printList(t_cam *cam)
{
    while (cam != NULL) {
        printf("CAMERA - VIEW X %lf VIEW Y %lf VIEW Z %lf \nCAMERA - POS X %lf VIEW Y %lf VIEW Z %lf \nCAMERA - FOV %d \n",
				cam->view.x, cam->view.y, cam->view.z, cam->pos.x, cam->pos.y, cam->pos.z, cam->fov);
        cam = cam->next;
    }
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_rt	rt;

	init_rt(&rt);
	if (argc == 1)
		errormsg(0);
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else if (argc > 2)
		errormsg(1);
	while (get_next_line(fd, &line) == 1)
	{
		rt_identify(line, &rt);
		free(line);
	}
	printList(rt.cam);
	rt_window(&rt);
	return (0);
}
