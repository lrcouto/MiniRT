/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 22:01:08 by lcouto            #+#    #+#             */
/*   Updated: 2021/01/01 18:41:20 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

/*
** TO DO:
** - Salvar arquivo em .bmp
** - Guardar imagens de múltiplas câmeras
** - Formas adicionais
** - Sombras
** 
** WISHLIST:
** - Associar o material ao arquivo .rt
** - Cubos
** - Reflexão/Refração
** - Barrinha de loading do render
*/

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
** Test functions need to be removed before final push.
*/

int			main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_rt	rt;

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
	free(line);
	canvas(&rt);
	return (0);
}
