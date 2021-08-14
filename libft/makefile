# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/24 20:37:04 by lcouto            #+#    #+#              #
#    Updated: 2021/06/09 02:51:29 by lcouto           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcpy.c ft_memmove.c ft_memset.c \
		ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
		ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_isalpha.c ft_memcmp.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_strmapi.c

BONUSSRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

ADDISRCS = ft_strnew.c ft_strdel.c ft_itoa_base.c ft_itoa_u.c ft_itoa_ptr.c ft_itoa_base_u.c \
			get_next_line.c ft_strjoin_gnl.c ft_strdup_gnl.c ft_substr_gnl.c ft_atof.c ft_atoll.c

OBJECTS = ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isascii.o ft_isdigit.o \
		ft_isprint.o ft_memccpy.o ft_memchr.o ft_memcpy.o ft_memmove.o ft_memset.o \
		ft_strchr.o ft_strdup.o ft_strlcat.o ft_strlcpy.o ft_strlen.o ft_strncmp.o \
		ft_strnstr.o ft_strrchr.o ft_tolower.o ft_toupper.o ft_isalpha.o ft_memcmp.o \
		ft_substr.o ft_strjoin.o ft_strtrim.o ft_itoa.o ft_putchar_fd.o ft_putstr_fd.o \
		ft_putendl_fd.o ft_putnbr_fd.o ft_split.o ft_strmapi.o

BONUSOBJS = ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o ft_lstadd_back.o \
			ft_lstdelone.o ft_lstclear.o ft_lstiter.o ft_lstmap.o

ADDIOBJS = ft_strnew.o ft_strdel.o ft_itoa_base.o ft_itoa_u.o ft_itoa_ptr.o ft_itoa_base_u.o \
		get_next_line.o ft_strjoin_gnl.o ft_strdup_gnl.o ft_substr_gnl.o ft_atof.o ft_atoll.o

INCLUDES = ./

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -I$(INCLUDES) -c $(SRCS) $(BONUSSRCS) $(ADDISRCS) libft.h
	ar -rc $(NAME) $(OBJECTS) $(BONUSOBJS) $(ADDIOBJS)
	ranlib $(NAME)

bonus: $(NAME)
	gcc -Wall -Wextra -Werror -I$(INCLUDES) -c $(SRCS) $(BONUSSRCS) libft.h
	ar -rc $(NAME) $(OBJECTS) $(BONUSOBJS)
	ranlib $(NAME)

adds: $(NAME)
	gcc -Wall -Wextra -Werror -I$(INCLUDES) -c $(SRCS) $(ADDISRCS) libft.h
	ar -rc $(NAME) $(OBJECTS) $(ADDIOBJS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJECTS) $(BONUSOBJS) $(ADDIOBJS) $(NAME)

fclean: clean
	/bin/rm -f $(NAME) $(OBJECTS) $(BONUSOBJS) $(ADDIOBJS) $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus adds
