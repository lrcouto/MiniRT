/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <gsenra-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 22:01:08 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/12 18:58:40 bygsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

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
				errormsg (30);
		}			
		i++;
	}
	errormsg(30);
}

int			main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_rt	rt;

	init_rt(&rt);
	int test;
	test = double_equal(1.00001, 1.00002);
	printf("** TESTE FDP **: %d\n", test);
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
	rt_window(&rt);
	return (0);
}
