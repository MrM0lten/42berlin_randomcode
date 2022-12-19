SRC = main.c
OBJS = ${SRC:.c=.o}
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
AR = ar -rcs

NAME = push_swap
DIRLIB		= ./libft/
NAMELFT		= libft.a
LIBFT = $(DIRLIB)$(NAMELFT)

$(NAME) :	$(OBJS) $(LIBFT)
	${CC} $(SRC) -L. ${LIBFT} -o $(NAME)
	

$(LIBFT):
	cd $(DIRLIB) && $(MAKE)

all: $(NAME)

clean:
	@cd $(DIRLIB) && $(MAKE) clean
	@$(RM) $(OBJS)

fclean: clean
	@cd $(DIRLIB) && $(MAKE) fclean
	@$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re $(NAME)
