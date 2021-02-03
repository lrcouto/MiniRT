/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 21:08:34 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/02 21:47:011 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void		write_bitmap(t_rt *rt, t_mlx *mlx, int fd)
{
	int		y;

	y = rt->reso.height;
	while (--y >= 0)
		write(fd, &mlx->address[y * mlx->line_leng], mlx->line_leng);
}

static void		write_bmpheader(int fd, t_bmpheader header)
{
	write(fd, &header.type, 2);
	write(fd, &header.size, 4);
	write(fd, &header.reserved, 4);
	write(fd, &header.offset, 4);
	write(fd, &header.dib_header_size, 4);
	write(fd, &header.width_px, 4);
	write(fd, &header.height_px, 4);
	write(fd, &header.num_planes, 2);
	write(fd, &header.bpp, 2);
	write(fd, &header.compression, 4);
	write(fd, &header.img_size_bytes, 4);
	write(fd, &header.x_resolution_ppm, 4);
	write(fd, &header.y_resolution_ppm, 4);
	write(fd, &header.num_colors, 4);
	write(fd, &header.important_colors, 4);
}

static void	create_bmpheader(t_rt *rt, t_bmpheader *header)
{
	header->type = 0x4D42;
	header->size = ((rt->reso.width + rt->reso.height) * 4) + 54;
	header->reserved = 0x0;
	header->offset = 54;
	header->dib_header_size = 40;
	header->width_px = rt->reso.width;
	header->height_px = rt->reso.height;
	header->num_planes = 1;
	header->bpp = 32;
	header->compression = 0;
	header->img_size_bytes = ((rt->reso.width + rt->reso.height) * 4);
	header->x_resolution_ppm = 2000;
	header->y_resolution_ppm = 2000;
	header->num_colors = 0;
	header->important_colors = 0;
}

static int		create_file(char *name)
{
	int		fd;
	char	*filename;

	filename = ft_strjoin(name, ".bmp");
	if (!(fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC | S_IRUSR | S_IWUSR, 0777)))
		errormsg(38);
	free(filename);
	return (fd);
}

void	create_bmp(t_rt *rt, t_mlx *mlx)
{
	char 		*name;
	char		*number;
	t_bmpheader	header;
	int			fd;

	number = ft_itoa(rt->qts.cam);
	name = ft_strjoin("camera_", number);
	rt->qts.cam = rt->qts.cam - 1;
	fd = create_file(name);
	create_bmpheader(rt, &header);
	write_bmpheader(fd, header);
	write_bitmap(rt, mlx, fd);
	close(fd);
	free(number);
	free(name);
	exit(0);
}