/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 16:07:19 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/27 19:30:22 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void		errormsg(int errornum)
{
	char	*filename;
	char	*errstring;
	int		fd;
	int		i;

	filename = "srcs/main/error.txt";
	fd = open(filename, O_RDONLY);
	i = 0;
	while ((get_next_line(fd, &errstring) == 1))
	{
		if (i == errornum)
			break ;
		free(errstring);
		i++;
	}
	if (errstring)
		ft_putstr_fd(errstring, 1);
	else
		ft_putstr_fd("ERROR: Error file not found", 1);
	write(1, "\n", 1);
	close(fd);
	exit(0);
}

void		*ec_malloc(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		errormsg(31);
	return (ptr);
}
