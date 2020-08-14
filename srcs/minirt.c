/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 16:26:27 by lcouto            #+#    #+#             */
/*   Updated: 2020/08/14 20:09:13 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 1)
		printf("You need to use a file as an argument for this program\n");
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else if (argc > 2)
		printf("One argument only, please.\n");
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl_fd(line, 1);
		rt_identify(line);
		free(line);
	}
	return (0);
}
