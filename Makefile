SRCDIR = src/
OBJDIR = bin/
INCDIR = include/
FTPATH = libft/
MLXPATH = minilibx-linux/
FTINC = $(FTPATH)include/
LIBFT = $(FTPATH)libft.a
MLX = $(MLXPATH)libmlx.a
######################################################################
SRCS = main.c\
	   parse.c\
	   colors.c\
	   quit.c\
	   key_pressed_hook.c\
	   draw.c\
	   img.c\
	   error.c
OBJS = $(addprefix $(OBJDIR),$(SRCS:.c=.o))
######################################################################
CC = clang -g3
CFLAGS = -Wall -Wextra -Werror
LINK = -lmlx -lft -lm -lXext -lX11
INCPATH = -I$(INCDIR) -I$(FTINC) -I$(MLXPATH)
LIBPATH = -L$(FTPATH) -L$(MLXPATH)
NAME = fdf
RUN = valgrind --leak-check=full ./fdf maps/test_maps/42.fdf
######################################################################
all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBPATH) $(LINK) -o $(NAME)
	$(RUN)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) -c $(CFLAGS) $(INCPATH) $< -o $@

$(LIBFT):
	make -C $(FTPATH)

$(MLX):
	make -C $(MLXPATH)

run:
	$(RUN)

clean:
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(FTPATH)
	make clean -C $(MLXPATH)
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all libft clean fclean re
