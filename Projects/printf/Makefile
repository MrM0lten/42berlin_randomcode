SRC = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c \
	ft_put_unsigned_nbr.c ft_uitoa.c ft_put_hexnbr.c \
	ft_put_ptr.c
OBJS = ${SRC:.c=.o}
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
AR = ar -rcs

NAME = libftprintf.a
DIRLIB		= ./libft/
NAMELFT		= libft.a
LIBFT = $(DIRLIB)$(NAMELFT)

$(NAME) :	$(OBJS)
	cd $(DIRLIB) && $(MAKE)
	cp libft/libft.a $(NAME)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	cd $(DIRLIB) && $(MAKE) clean
	$(RM) $(OBJS)

main: $(NAME)
	${CC} main.c -L. ${NAME} 

fclean: clean
	$(MAKE) fclean -C ./libft
	cd $(DIRLIB) && $(MAKE) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re $(NAME)
