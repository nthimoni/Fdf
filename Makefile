SRCDIR = src/
OBJDIR = bin/
INCDIR = include/
INCLIB = libft/include/
FTPATH = libft/
######################################################################
SRCS = main.c
OBJS = $(SRCS:.c=.o)
######################################################################
CC = clang
CFLAGS = -Wall -Wextra -Werror
LINK = -lft -lm
INCPATH = -I$(INCDIR) -I$(INCLIB)
LIBPATH = -L$(FTPATH)
NAME = fdf
######################################################################
all: $(NAME)

$(NAME): mklib $(OBJS)
	$(CC) $(addprefix $(OBJDIR),$(SRCS)) $(LIBPATH) $(LINK) -o $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) -c $(CFLAGS) $(INCPATH) $< -o $@

mklib:
	make -C libft/

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all libft clean fclean re
