NAME	= miniRT

HEADERS	= includes

SRCDIR	= srcs/

LIBS		= libs/

FILES	=	minirt.c \
				get_next_line.c \
				# get_resolution.c \
				# rt_identify.c \

SRCS	= $(addprefix $(SRCDIR), $(FILES))

OBJS	= ${SRCS:.c=.o}

CC		= gcc -g

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -I $(HEADERS)

FLAGS = -L $(LIBS)libft -lft

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
	# FLAGS += $(LINUX_FLAGS)
endif

${NAME}:	${OBJS}
			make -C $(LIBS)libft
			${CC} ${CFLAGS} $(OBJS) $(FLAGS) -o ${NAME}

all:		${NAME}

clean:
			make clean -C $(LIBS)libft
			${RM} ${OBJS}

fclean:		clean
			make fclean -C $(LIBS)libft
			${RM} ${NAME}

re:			fclean all

PHONY:		all clean fclean re