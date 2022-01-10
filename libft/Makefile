SRCDIR = src/
OBJDIR = bin/
######################################################################
MANDIR = mandatory/
BONDIR = bonus/
EXTDIR = extra/
######################################################################
INCDIR = include/
######################################################################
EXTFILES = get_next_line_bonus.c\
			ft_printf.c\
			write_buf.c\
			parse_flags.c\
			print_s.c\
			print_c.c\
			print_u.c\
			print_di.c\
			print_p.c\
			print_xX.c\
			print_percent.c

MANFILES = ft_isalpha.c\
			ft_isdigit.c\
			ft_isalnum.c\
			ft_isascii.c\
			ft_isprint.c\
			ft_strlen.c\
			ft_memset.c\
			ft_bzero.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_strlcpy.c\
			ft_strlcat.c\
			ft_toupper.c\
			ft_tolower.c\
			ft_strchr.c\
			ft_strrchr.c\
			ft_strncmp.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_strnstr.c\
			ft_atoi.c\
			ft_calloc.c\
			ft_strdup.c\
			ft_substr.c\
			ft_strjoin.c\
			ft_strtrim.c\
			ft_split.c\
			ft_itoa.c\
			ft_strmapi.c\
			ft_striteri.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c

BONFILES = ft_lstnew.c\
			ft_lstadd_front.c\
			ft_lstsize.c\
			ft_lstlast.c\
			ft_lstadd_back.c\
			ft_lstdelone.c\
			ft_lstclear.c\
			ft_lstiter.c\
			ft_lstmap.c
######################################################################
BONOBJ = $(addprefix $(OBJDIR), $(addprefix $(BONDIR), $(BONFILES:.c=.o)))
MANOBJ = $(addprefix $(OBJDIR), $(addprefix $(MANDIR), $(MANFILES:.c=.o)))
EXTOBJ = $(addprefix $(OBJDIR), $(addprefix $(EXTDIR), $(EXTFILES:.c=.o)))
######################################################################
BONSRC = $(addprefix $(SRCDIR), $(addprefix $(BONDIR), $(BONFILES)))
MANSRC = $(addprefix $(SRCDIR), $(addprefix $(MANDIR), $(MANFILES)))
EXTSRC = $(addprefix $(SRCDIR), $(addprefix $(EXTDIR), $(EXTFILES)))
######################################################################
AR = ar -rc
CC = clang
CFLAGS = -Wall -Wextra -Werror
INCPATH = -I$(INCDIR)

define cc-command
	$(CC) -c $(CFLAGS) $(INCPATH) $< -o $@
endef
######################################################################
NAME = libft.a

INCPATH = -I$(INCDIR)

all: $(NAME)

$(NAME): $(MANOBJ) $(BONOBJ) $(EXTOBJ)
	$(AR) $(NAME) $(MANOBJ) $(BONOBJ) $(EXTOBJ)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(cc-command)

clean:
	rm -rf $(MANOBJ)
	rm -rf $(BONOBJ)
	rm -rf $(EXTOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all libft clean fclean re
