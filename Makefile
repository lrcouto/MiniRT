# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/13 14:59:28 by lcouto            #+#    #+#              #
#    Updated: 2020/09/13 15:09:20 by lcouto           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = MiniRT

HEADERS = include

DIR_SRCS = srcs

DIR_OBJS = objs

DIRS = main parsing operations
SOURCEDIRS = $(foreach dir, $(DIRS), $(addprefix $(DIR_SRCS)/, $(dir)))

SOURCES = $(foreach dir,$(SOURCEDIRS),$(wildcard $(dir)/*.c))

OBJS = $(subst $(DIR_SRCS),$(DIR_OBJS),$(SOURCES:.c=.o))

CC	= gcc -g

RM	= rm -rf

CFLAGS	= -Wall -Wextra -Werror -I $(HEADERS)

LIBFT = libft

LIBS = libs

FLAGS = -L $(LIBFT) -lft

MACOS_MACRO = -D MACOS

LINUX_MACRO = -D LINUX

MACOS_FLAGS	= -L $(LIBS)minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit

LINUX_FLAGS = -L $(LIBS)minilibx-linux -lmlx -lm -lX11 -lXext

UNAME := $(shell uname)

ifeq ($(UNAME),Darwin)
	NUM_THREADS = $(shell sysctl -n hw.ncpu)
	CFLAGS += $(MACOS_MACRO)
	FLAGS += $(MACOS_FLAGS)
endif
ifeq ($(UNAME),Linux)
	NUM_THREADS = $(shell nproc --all)
	CFLAGS += $(LINUX_MACRO)
	FLAGS += $(LINUX_FLAGS)
endif

ifeq ($(SANITIZE_A),true)
	CFLAGS += -fsanitize=address
endif

ifeq ($(SANITIZE_L),true)
	CFLAGS += -fsanitize=leak
endif

$(NAME): $(OBJS)
		make -C $(LIBFT)
		-$(CC) $(CFLAGS) $(OBJS) $(FLAGS) $(HEADER) -o $(NAME)

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
		mkdir -p objs
		mkdir -p objs/parsing
		mkdir -p objs/main
		mkdir -p objs/operations
		$(CC) $(CFLAGS) $(HEADER) -c $< -o $@
		@echo "Compiled "$<" successfully!"

all: $(NAME)

clean:
			make clean -C $(LIBFT)
			$(RM) $(OBJS)
			$(RM) $(DIR_OBJS)

fclean:		clean
			make fclean -C $(LIBFT)
			$(RM) $(NAME)
			$(RM) $(DIR_OBJS)

re:			fclean all

PHONY:		all clean fclean re
