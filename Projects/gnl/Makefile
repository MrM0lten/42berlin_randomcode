SRC = get_next_line_utils.c get_next_line.c main.c
OBJS = ${SRC:.c=.o}


CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
AR = ar -rcs

NAME = test
LIBNAME = libft.a
DIRLIB = ./libft/
LIBFT = $(DIRLIB)$(LIBNAME)

all: $(NAME)

$(NAME): $(OBJS)
	${CC} ${CFLAGS} $(SRC) 

clean:
	@$(RM) $(OBJS)


fclean: clean
	$(RM) $(NAME)

re: fclean all re clean

.PHONY: all clean fclean re $(NAME)
