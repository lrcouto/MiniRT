/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:08:47 by lcouto            #+#    #+#             */
/*   Updated: 2021/06/09 02:53:42 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <limits.h>
# include <inttypes.h>
# include <stdio.h>

/*
** STRUCT FOR BONUS FUNCTIONS
*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*
** MANDATORY FUNCTIONS PART 1
*/

void				*ft_memset(void *b, int c, size_t len);

void				*ft_bzero(void *b, size_t n);

void				*ft_memcpy(void *dest, const void *src, size_t n);

void				*ft_memccpy(void *str_dest,
						const void *str_src, int c, size_t n);

void				*ft_memmove(void *dest, const void *src, size_t n);

void				*ft_memchr(const void *arr, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

size_t				ft_strlen(const char *str);

size_t				ft_strlcpy(char *dest, const char *src, size_t size);

size_t				ft_strlcat(char *dest, const char *src, size_t size);

char				*ft_strchr(const char *str, int c);

char				*ft_strrchr(const char *str, int c);

char				*ft_strnstr(const char *haystack,
						const char *needle, size_t len);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

int					ft_atoi(const char *str);

int					ft_isalpha(int c);

int					ft_isdigit(int c);

int					ft_isalnum(int c);

int					ft_isascii(int c);

int					ft_isprint(int c);

int					ft_toupper(int c);

int					ft_tolower(int c);

void				*ft_calloc(size_t n, size_t size);

char				*ft_strdup(const char *str);

/*
** MANDATORY FUNCTIONS PART 2
*/

char				*ft_substr(char const *s, unsigned int start, size_t len);

char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_strtrim(char const *s1, char const *set);

char				**ft_split(char const *s, char c);

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char				*ft_itoa(int n);

void				ft_putchar_fd(char c, int fd);

void				ft_putstr_fd(char *s, int fd);

void				ft_putendl_fd(char *s, int fd);

void				ft_putnbr_fd(int n, int fd);

/*
** BONUS FUNCTIONS
*/

t_list				*ft_lstnew(void *content);

void				ft_lstadd_front(t_list **lst, t_list *new);

int					ft_lstsize(t_list *lst);

t_list				*ft_lstlast(t_list *lst);

void				ft_lstadd_back(t_list **lst, t_list *new);

void				ft_lstdelone(t_list *lst, void (*del)(void*));

void				ft_lstclear(t_list **lst, void (*del)(void*));

void				ft_lstiter(t_list *lst, void (*f)(void *));

t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

/*
** ADDITIONAL FUNCTIONS, NOT ORIGINALLY PART OF THE LIBFT PROJECT
*/

char				*ft_strnew(size_t size);

void				ft_strdel(char **s);

char				*ft_itoa_base(int n, unsigned int base);

char				*ft_itoa_u(unsigned int n);

char				*ft_itoa_ptr(uintptr_t n, unsigned int base);

char				*ft_itoa_base_u(unsigned int n, unsigned int base);

int					get_next_line(int fd, char **line);

char				*ft_strdup_gnl(const char *s1);

char				*ft_strjoin_gnl(char const *s1, char const *s2);

char				*ft_substr_gnl(char const *s, unsigned int start,
						size_t len);

double				ft_atof(char *s);

long long int		ft_atoll(char *str);

#endif
