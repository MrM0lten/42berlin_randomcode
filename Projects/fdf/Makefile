SRC = main.c drawing_utils.c point_utils.c utils_01.c utils_02.c input.c object.c project.c file_utils.c error.c
OBJS = ${SRC:.c=.o}

CC = cc
CFLAGS = #-Wall -Werror -Wextra
RM = rm -f
AR = ar -rcs

NAME = fdf

LIBNAME = libft.a
DIRLIB = ./libft/
LIBFT = $(DIRLIB)$(LIBNAME)

MLXLIBNAME = libmlx_Linux.a
MLXDIRLIB = ./minilibx-linux/
MLXLIB = $(MLXDIRLIB)$(MLXLIBNAME)

LFLAGS = -L. $(MLXLIB) $(LIBFT) -lXext -lX11 -lm
LIBS = libs

all: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	@$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)

$(LIBS):
	@$(MAKE) -C $(DIRLIB)
	@$(MAKE) -C $(MLXDIRLIB)

clean:
	@$(MAKE) clean -C $(DIRLIB)
	@$(RM) $(OBJS)


fclean: clean
	@$(MAKE) fclean -C $(DIRLIB)
	$(RM) $(NAME)


re: fclean clean all 

.PHONY: all clean fclean re $(NAME)
