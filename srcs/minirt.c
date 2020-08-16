/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 23:34:57 by lniehues          #+#    #+#             */
/*   Updated: 2020/08/16 16:20:41 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char** av)
{
	int fd;
	int status;
	char **line;

	line = malloc(sizeof(char*) * 2);

	if (ac == 1)
		write(1, "Error\n", 6);
	if (ac == 2) {
		if ((fd = open(av[1], 0)) == -1) {
			write(1, "Error while opening file\n", 24);
			return (0);
		}
		while ((status = get_next_line(fd, line)))
		{
			printf("%s\n", *line);
		}
	}

	free(line);
	return (0);
}
