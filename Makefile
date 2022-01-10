SRCDIR = src/
OBJDIR = bin/
INCDIR = include/
INCLIB = libft/include/
FTPATH = libft/
LIBFT = $(FTPATH)libft.a
######################################################################
SRCS = parse.c
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

$(NAME): $(LIBFT) $(addprefix $(OBJDIR),$(OBJS))
	$(CC) $(addprefix $(OBJDIR),$(SRCS)) $(LIBPATH) $(LINK) -o $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) -c $(CFLAGS) $(INCPATH) $< -o $@

$(LIBFT):
	make -C $(FTPATH)

clean:
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(FTPATH)
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all libft clean fclean re
