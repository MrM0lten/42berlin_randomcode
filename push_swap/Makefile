SRC = main.c debug_utils.c instructions.c algorithm.c program_utils.c errors.c \
	insert_algo.c
OBJS = ${SRC:.c=.o}
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
AR = ar -rcs

NAME = push_swap
LIBNAME = libft.a
DIRLIB = ./libft/
LIBFT = $(DIRLIB)$(LIBNAME)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	${CC} $(SRC) -L. ${LIBFT} -o $(NAME)
	@$(RM) $(OBJS)

$(LIBFT):
	@$(MAKE) -C ./libft 

clean:
	@$(MAKE) clean -C ./libft 
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C ./libft 
	$(RM) $(NAME)

re: fclean all re clean

.PHONY: all clean fclean re $(NAME)
