/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 16:26:27 by lcouto            #+#    #+#             */
/*   Updated: 2020/08/20 16:37:12 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_rt	rt;

	init_rt(&rt);
	if (argc == 1)
	{
		ft_putstr_fd("You need to use a file as an argument for this program\n"
		, 1);
		exit(0);
	}
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else if (argc > 2)
	{
		ft_putstr_fd("One argument only, please.\n", 1);
		exit(0);
	}
	while (get_next_line(fd, &line) == 1)
	{
		rt_identify(line, &rt);
		free(line);
	}
	rt_window(&rt);
	return (0);
}
