/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 21:08:34 by lcouto            #+#    #+#             */
/*   Updated: 2021/01/31 15:29:02 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int		create_file(char *name)
{
	int	fd;

	fd = open(name, O_CREAT | O_WRONLY | O_TRUNC | S_IRUSR | S_IWUSR);
	write(fd, "This is a test file.\n", ft_strlen("This is a test file.\n"));
	return (fd);
}