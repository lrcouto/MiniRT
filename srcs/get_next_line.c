/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:41:49 by lcouto            #+#    #+#             */
/*   Updated: 2020/08/17 19:30:34 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static size_t	ft_strlen_gnl(const char *str)
{
	size_t counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}

static char	*ft_strdup_gnl(const char *s1)
{
	char			*copy;
	unsigned	int	i;
	unsigned	int	s1_len;

	i = 0;
	s1_len = ft_strlen_gnl(s1);
	copy = (char *)malloc((s1_len + 1) * sizeof(*copy));
	if (copy == 0)
		return (0);
	while (s1[i] != '\0')
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	unsigned	int	i;
	char			*str;
	size_t			s1_len;
	size_t			s2_len;

	i = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	s1_len = ft_strlen_gnl(s1);
	s2_len = ft_strlen_gnl(s2);
	str = (char *)malloc((s1_len + s2_len + 1) * sizeof(*str));
	if (str == 0)
		return (0);
	while (i < s1_len)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < s1_len + s2_len)
	{
		str[i] = s2[i - s1_len];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_strchr_gnl(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			return ((char*)&str[i]);
		}
		i++;
	}
	if (c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

static char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned	int	i;
	size_t			s_len;

	i = 0;
	if (s == 0)
		return (0);
	s_len = ft_strlen_gnl(s);
	if (start > s_len)
		return (ft_strdup_gnl(""));
	sub = (char *)malloc((len + 1) * sizeof(*s));
	if (sub == 0)
		return (0);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

int		ft_line_add(char **str, char **line)
{
	char	*temp;
	size_t	i;

	i = 0;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	if ((*str)[i] == '\n')
	{
		*line = ft_substr_gnl(*str, 0, i);
		temp = ft_strdup_gnl(&((*str)[i + 1]));
		free(*str);
		*str = temp;
		if ((*str)[0] == '\0')
			ft_strdel(str);
	}
	else
	{
		*line = ft_strdup_gnl(*str);
		ft_strdel(str);
		return (0);
	}
	return (1);
}

int		ft_return(char **str, char **line, int n, int fd)
{
	if (n < 0)
		return (-1);
	else if (n == 0 && str[fd] == NULL)
	{
		*line = ft_strnew(0);
		return (0);
	}
	return (ft_line_add(&str[fd], line));
}

int				get_next_line(int fd, char **line)
{
	static char	*str[200];
	char		*buffer;
	char		*temp;
	int			n;

	if (!(buffer = (char *)malloc(sizeof(char) * (200 + 1))))
		return (0);
	if (fd < 0 || line == 0 || 200 < 1)
		return (-1);
	while ((n = read(fd, buffer, 200)) > 0)
	{
		buffer[n] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup_gnl(buffer);
		else
		{
			temp = ft_strjoin_gnl(str[fd], buffer);
			free(str[fd]);
			str[fd] = temp;
		}
		if (ft_strchr_gnl(str[fd], '\n'))
			break ;
	}
	ft_strdel(&buffer);
	return (ft_return(str, line, n, fd));
}
