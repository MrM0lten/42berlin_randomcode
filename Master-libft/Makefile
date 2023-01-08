SRCDIRS = ./srcs/gnl ./srcs/printf ./srcs/stdlib ./srcs/array_utils ./srcs/mlx
INCLDIR = ./includes/  

SRC = $(foreach D,$(SRCDIRS),$(wildcard $(D)/*.c))

OBJS = ${SRC:.c=.o}
HEADERS = libft.h ft_printf.h get_next_line.h array_utils.h mlx_utils.h

LIB = libft.a

CC = cc
AR = ar -rcs
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

#color formatting for echo
#https://stackoverflow.com/questions/5947742/how-to-change-the-output-color-of-echo-in-linux
CCRED ="\033[0;31m"
CCGREEN ="\033[0;32m"
CCWHITE ="\033[1;37"

all : $(LIB)

$(LIB) : $(OBJS)
	@$(AR) $(LIB) $(OBJS)
	@echo $(CCGREEN)"created libft"$(CCWHITE)

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

main: $(LIB)
	${CC} ${CFLAGS} main.c $(LIB) -lm

clean :
	@$(RM) $(OBJS)

fclean : clean
	@echo $(CCRED)"removing all .o files"$(CCWHITE)
	$(RM) $(LIB)

re : fclean all

.PHONY: all clean fclean re
