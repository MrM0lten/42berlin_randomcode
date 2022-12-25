SRC = push_swap.c debug_utils.c instructions.c algorithm.c program_utils.c errors.c \
	insert_algo.c general_utils.c lis_utils.c array_utils.c
OBJS = ${SRC:.c=.o}

SRCBONUS = bonus.c debug_utils.c instructions.c algorithm.c program_utils.c errors.c \
	insert_algo.c general_utils.c lis_utils.c array_utils.c

OBJSBONUS = ${SRCBONUS:.c=.o}
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
AR = ar -rcs

NAME = push_swap
BONNAME= checker
LIBNAME = libft.a
DIRLIB = ./libft/
LIBFT = $(DIRLIB)$(LIBNAME)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	${CC} $(SRC) -L. ${LIBFT} -o $(NAME)
	@$(RM) $(OBJS)

$(LIBFT):
	@$(MAKE) -C ./libft 

bonus: $(OBJS) $(LIBFT)
	${CC} $(SRCBONUS) -L. ${LIBFT} -o $(BONNAME)
	@$(RM) $(OBJSBONUS)

clean:
	@$(MAKE) clean -C ./libft 
	@$(RM) $(OBJS)
	@$(RM) $(OBJSBONUS)

fclean: clean
	@$(MAKE) fclean -C ./libft 
	$(RM) $(NAME)
	$(RM) $(BONNAME)

re: fclean all re clean

.PHONY: all clean fclean re $(NAME)
