/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 23:41:38 by lniehues          #+#    #+#             */
/*   Updated: 2020/08/09 00:22:55 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include "minirt.h"

# ifndef OPEN_MAX
#  define OPEN_MAX 2048
# endif

/*
**	### gnl_init: initializes the stats of a file to default. Only happens the
**	first time you read the file, when your offset equals the bytes read
**	(limited by the EOF or BUFFER_SIZE) and when you reach the end of file.
**
**	### gnl_handle_desloc: handles the offset movement comparing it to the
**	BUFFER_SIZE and byte_read. If offset greater or equal to byte_read it means
**	it has reached the EOF or buffer limits. Than it triggers the
**	gnl_line_store.
**
**	### gnl_line_store: yes, it does one character each time, so it's slow,
**	but safer. it uses offset as first index and after it uses pos as the copy
**	(new) index. stored takes new each time around. It only returns new (adding
**	NULL-termination) when it finds '\n' or when validation is true (it means
**	offset is greater or equal to byte_read) and also reset the values of
**	stored and pos.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *ptr1;
	unsigned char *ptr2;

	ptr1 = (unsigned char*)dst;
	ptr2 = (unsigned char*)src;
	if (dst == src)
		return (dst);
	while (n > 0)
	{
		*(ptr1++) = *(ptr2++);
		n--;
	}
	return (dst);
}

static int				gnl_init(t_gnl_stats *stats, int validate,
						int return_value)
{
	if (!(!validate && (*stats).init == 1))
	{
		(*stats).init = 1;
		(*stats).reached = 0;
		(*stats).offset = BUFFER_SIZE;
		(*stats).stored = NULL;
		(*stats).pos = 0;
	}
	return (return_value);
}

static unsigned char	*gnl_line_store(t_gnl_stats *stat, int validation)
{
	unsigned char	*new;
	unsigned char	c;

	c = (*stat).buffer[(*stat).offset];
	(*stat).offset += 1;
	if (!(new = malloc(sizeof(char) * ((*stat).pos + 1))))
		return (NULL);
	if ((*stat).stored != NULL)
	{
		ft_memcpy(new, (*stat).stored, (*stat).pos);
		free((*stat).stored);
	}
	if (c == '\n' || validation)
	{
		new[(*stat).pos] = '\0';
		(*stat).stored = NULL;
		(*stat).pos = 0;
		return (new);
	}
	new[(*stat).pos] = c;
	(*stat).stored = new;
	(*stat).pos += 1;
	return (NULL);
}

static int				gnl_handle_desloc(t_gnl_stats *stat, char **return_line)
{
	unsigned char	*line;
	int				validation;

	while ((*stat).offset + 1 < BUFFER_SIZE + 1)
	{
		validation = (*stat).offset >= (*stat).byte_read;
		line = gnl_line_store(stat, validation);
		if (line != NULL)
		{
			if (validation)
				(*stat).reached = 1;
			*return_line = (char *)line;
			return (1);
		}
	}
	return (0);
}

int						get_next_line(int fd, char **line)
{
	static t_gnl_stats	stats[OPEN_MAX];
	t_gnl_stats			*stat;

	if (!line || BUFFER_SIZE == 0 || fd < 0)
		return (-1);
	*line = NULL;
	stat = &stats[fd];
	gnl_init(stat, 0, 1);
	while (1)
	{
		if ((*stat).offset == BUFFER_SIZE)
		{
			(*stat).byte_read = read(fd, (*stat).buffer, BUFFER_SIZE);
			(*stat).offset = 0;
		}
		if ((*stat).byte_read == (size_t)-1)
			return (-1);
		if (gnl_handle_desloc(stat, line))
		{
			if ((*stat).byte_read == 0 || (*stat).reached)
				return (gnl_init(stat, 1, 0));
			return (1);
		}
	}
}
