SRCDIR = src/
OBJDIR = bin/
INCDIR = include/
INCLIB = libft/include/
FTPATH = libft/
LIBFT = $(FTPATH)libft.a
######################################################################
SRCS = main.c\
	   parse.c
OBJS = $(addprefix $(OBJDIR),$(SRCS:.c=.o))
######################################################################
CC = clang
CFLAGS = -Wall -Wextra -Werror
LINK = -lft -lm
INCPATH = -I$(INCDIR) -I$(INCLIB)
LIBPATH = -L$(FTPATH)
NAME = fdf
######################################################################
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBPATH) $(LINK) -o $(NAME)

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
