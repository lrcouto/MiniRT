/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 22:01:08 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/06 21:54:17 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

/*
** TO DO:
** - Guardar imagens de múltiplas câmeras
** - Lembrar de deixar todos os parametros
**   no modo "básico" para a entrega.
**
** WISHLIST:
** - Associar o material ao arquivo .rt
** - Associais limitador da recursão ao arquivo .rt
** - Reorganizar código pra fazer sentido.
** - Soft shadows
** - Cubos
** - Refração/Fresnel
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

static void	check_savefile(t_rt *rt, char *arg)
{
	if (arg && (ft_strncmp(arg, "--save", 7) == 0))
		rt->savefile = 1;
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
	else if (argc == 2 || (argc == 3 &&
	(ft_strncmp(argv[2], "--save", 7) == 0)))
	{
		check_savefile(&rt, argv[2]);
		valid_rtfile(argv[1]);
		fd = open(argv[1], O_RDONLY);
	}
	else
		errormsg(1);
	while (get_next_line(fd, &line) == 1)
	{
		rt_identify(line, &rt);
		free(line);
	}
	rt_identify(line, &rt);
	free(line);
	canvas(&rt);
	return (0);
}
