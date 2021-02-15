# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/13 14:59:28 by lcouto            #+#    #+#              #
#    Updated: 2021/02/15 17:53:16 by lcouto           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

HEADERS = include

DIR_SRCS = srcs

DIR_OBJS = objs

DIRS = main parsing operations render

SOURCEDIRS = $(foreach dir, $(DIRS), $(addprefix $(DIR_SRCS)/, $(dir)))

# main:		error.c init_rt.c minirt.c
#
# parsing:	fill_collor.c get_ambi_rgb.c get_ambient.c /
#			get_cam_fov.c get_cam_pos.c get_cam_view get_camera.c /
#			get_color.c get_coord.c get_cylinder_color.c get_cylinder_doubles.c /
#			get_cylinder_pos.c get_cylinder.c get_index_nocomma.c get_get_index.c /
#			get_light_color.c get_light_pos.c get_light.c get_plane_color.c /
#			get_plane_pos.c get_plane.c get_resolution.c /
#			get_sphere_center.c get_sphere_color.c get_sphere.c /
#			get_square_center.c get_square_color.c get_square_side.c /
#			get_square.c get_triangle_color.c get_triangle_p1.c /
#			get_triangle_p2.c get_triangle_p3.c get_triangle.c /
#			rt_identify.c get_plane_norm.c get_square_norm.c get_cylinder_norm.c /
#			get_material.c
#						
# operations: utils.c vector_ops_1.c vector_ops_2.c color_ops_1.c color_ops_2.c /
#			matrix_ops_1.c matrix_ops_2.c matrix_ops_3.c matrix_ops_4.c /
#			ray_ops_1.c ray_ops_2.c ray_ops_3.c ray_ops_4.c intersect_sphere.c /
#			intersect_plane.c intersect_square.c intersect_cylinder.c /
#			intersect_triangle.c
#
# render:	canvas.c render_utils.c mlx_utils.c render_utils_2.c scene_render.c /
#			intersect_polys.c bitmap.c render_utils_3.c image.c

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
		@make -C $(LIBFT)
		-$(CC) $(CFLAGS) $(OBJS) $(FLAGS) $(HEADER) -o $(NAME)

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
		@mkdir -p objs
		@mkdir -p objs/parsing
		@mkdir -p objs/main
		@mkdir -p objs/operations
		@mkdir -p objs/render
		@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@
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
