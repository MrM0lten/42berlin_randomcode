SRCDIRS := ./srcs/gnl ./srcs/printf ./srcs/stdlib ./srcs/array_utils ./srcs/mlx
INCLDIR := ./includes/
BUILDDIR := obj

SRC := $(foreach D,$(SRCDIRS),$(wildcard $(D)/*.c))
OBJS := $(addprefix $(BUILDDIR)/, $(SRC:.c=.o))

HEADERS = libft.h ft_printf.h get_next_line.h array_utils.h mlx_utils.h

LIB = libft.a

CC = cc
AR = ar -rcs
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

#color formatting for echo
#https://stackoverflow.com/questions/5947742/how-to-change-the-output-color-of-echo-in-linux
CCRED =\033[0;31m
CCGREEN =\033[0;32m
CCWHITE =\033[1;37m

#defines a function "color" which takes a color param and text param, sets color back to default
define color
      @echo -n "$1"
      @echo $2
      @tput sgr0
endef

all : $(LIB)

$(LIB) : $(OBJS)
	@mkdir -p $(BUILDDIR)
	@$(AR) $(LIB) $(OBJS)
	@echo "$(CCGREEN)created libft$(CCWHITE)"

$(BUILDDIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) -c $(CFLAGS) $^ -o $@

clean :
	$(call color,$(CCRED),"removing object directory")
	@rm -r $(BUILDDIR)

fclean : clean
	$(call color,$(CCRED),"removing all .o files")
	@$(RM) $(LIB)

re : fclean all

.PHONY: all clean fclean re
