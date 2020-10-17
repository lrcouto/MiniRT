/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 22:01:08 by lcouto            #+#    #+#             */
/*   Updated: 2020/10/17 17:39:39 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void	valid_rtfile(char *filename)
{
	int i;

	i = 0;
	while (filename[i])
	{
		if (filename[i] == '.')
		{
			if (filename[i + 1] == 'r' && filename[i + 2] == 't'
				&& filename[i + 3] == '\0')
				return ;
			else
				errormsg(30);
		}
		i++;
	}
	errormsg(30);
}

/*
** Function projectile_test() is not actually part of the project
** and simply prints a pretty rainbow for MiniLibX vector-to-canvas tests.
*/

int			main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_rt	rt;

	//test_translation(5, -3, 2, -3, 4, 5);
	//test_scaling(2, 3, 4, -4, 6, 8);
	//test_rotation();
	//test_shearing();
	//test_chain_transform();
	//matrix_test(4, 4);
	//projectile_test("12");
	init_rt(&rt);
	if (argc == 1)
		errormsg(0);
	else if (argc == 2)
	{
		valid_rtfile(argv[1]);
		fd = open(argv[1], O_RDONLY);
	}
	else if (argc > 2)
		errormsg(1);
	while (get_next_line(fd, &line) == 1)
	{
		rt_identify(line, &rt);
		free(line);
	}
	test_clock(&rt);
	return (0);
}
