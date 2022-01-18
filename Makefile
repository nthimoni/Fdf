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
	   error.c\
	   bresenham.c\
	   utils.c\
	   transfo.c\
	   set_colors.c\
	   isoview.c\
	   fill_point.c
OBJS = $(addprefix $(OBJDIR),$(SRCS:.c=.o))
#####################################################################
#map = M_42
map = FR_S
######################################################################
CC = clang -O3 -Ofast
CFLAGS = -Wall -Wextra -Werror -D$(map)
LINK = -lmlx -lft -lm -lXext -lX11
INCPATH = -I$(INCDIR) -I$(FTINC) -I$(MLXPATH)
LIBPATH = -L$(FTPATH) -L$(MLXPATH)
NAME = fdf
VAL = valgrind --leak-check=full ./fdf maps/42.fdf
RUN = ./fdf maps/42.fdf
######################################################################
all: $(NAME)
	$(RUN)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBPATH) $(LINK) -o $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) -c $(CFLAGS) $(INCPATH) $< -o $@

$(LIBFT):
	make -C $(FTPATH)

$(MLX):
	make -C $(MLXPATH)

run:
	$(RUN)

val:
	$(VAL)

clean:
	rm -rf $(OBJS)

fclean: clean
	#make fclean -C $(FTPATH)
	#make clean -C $(MLXPATH)
	rm -f $(NAME)

re: fclean $(NAME) run

.PHONY: all libft clean fclean re
