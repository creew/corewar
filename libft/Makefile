SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_isspace.c ft_itoa.c ft_lstadd.c \
		ft_lstaddblank.c ft_lstdel.c ft_lstdelone.c ft_lstfind.c ft_lstiter.c \
		ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memdel.c	ft_memmove.c ft_memndup.c \
		ft_memrealloc.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c \
		ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
		ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c \
		ft_strdup.c	ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
		ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c \
		ft_strncmp.c ft_strncpy.c ft_strndup.c ft_strnequ.c ft_strnew.c \
		ft_strnstr.c ft_strrchr.c ft_strrev.c ft_strsplit.c ft_strstr.c \
		ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_intmove.c \
		ft_getc.c ft_lstaddsorted.c ft_lstnewblank.c ft_lstsize.c ft_lstget.c \
		get_next_line.c ft_stack_init.c ft_stack_push.c ft_stack_pop.c \
		ft_stack_delall.c ft_stack_size.c ft_queue_add.c ft_queue_poll.c \
		ft_lstaddrevsorted.c ft_strtol.c ft_abs.c ft_min.c ft_max.c \
		ft_bubble_sort.c ft_calloc.c ft_strlcpy.c ft_safe_atoi.c \
		ft_strpbrk.c ft_trim_spaces.c ft_array_add.c ft_array_foreach.c \
		ft_array_get.c ft_array_init.c ft_array_remove.c ft_array_remove_all.c \
		ft_array_size.c ft_lstadd_back.c ft_voidcpy.c ft_array_new.c \
		ft_array_delete_all.c ft_array_insert.c

NAME	= libft.a

FLAGS	= -Wall -Wextra -Werror -g

INCLUDES = ./includes/libft.h ./includes/get_next_line.h

SRCDIR	= ./srcs
OBJDIR	= ./objs

ALL_OBJ	= $(SRC:%.c=%.o)
OBJS	= $(addprefix $(OBJDIR)/, $(ALL_OBJ))

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCLUDES) | $(OBJDIR)
	gcc $(FLAGS) -I./includes -c $< -o $@

clean:
	/bin/rm -rf $(OBJDIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
