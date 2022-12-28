SRC = main.c
OBJS = ${SRC:.c=.o}

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
AR = ar -rcs

NAME = test
LIBNAME = libft.a
DIRLIB = ../Master-libft/
LIBFT = $(DIRLIB)$(LIBNAME)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	${CC} $(SRC) -L. ${LIBFT} -o $(NAME)
	@$(RM) $(OBJS)

$(LIBFT):
	@$(MAKE) -C $(DIRLIB)

clean:
	@$(MAKE) clean -C $(DIRLIB)
	@$(RM) $(OBJS)
	@$(RM) $(OBJSBONUS)

fclean: clean
	@$(MAKE) fclean -C $(DIRLIB)
	$(RM) $(NAME)
	$(RM) $(BONNAME)

re: fclean clean all 

.PHONY: all clean fclean re $(NAME)
