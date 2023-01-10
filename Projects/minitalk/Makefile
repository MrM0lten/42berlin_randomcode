SRC_SERVER := server.c
SRC_CLIENT := client.c
BUILDDIR := obj

OBJS_SERVER := $(addprefix $(BUILDDIR)/,${SRC_SERVER:.c=.o})
OBJS_CLIENT := $(addprefix $(BUILDDIR)/,${SRC_CLIENT:.c=.o})

CC = cc
CFLAGS = -Wall -Werror -Wextra

SERVER = server
CLIENT = client

LIBNAME = libft.a
DIRLIB = ./libft/
LIBFT = $(DIRLIB)$(LIBNAME)

all: $(SERVER) $(CLIENT)	

$(SERVER): $(LIBNAME) $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) -o $(SERVER)

$(CLIENT): $(LIBNAME) $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(CLIENT)

$(LIBNAME):
	@$(MAKE) -C $(DIRLIB)

$(BUILDDIR)/%.o: %.c
	mkdir -p $(BUILDDIR)
	$(CC) -c $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	$(MAKE) fclean -C $(DIRLIB)

re: fclean all