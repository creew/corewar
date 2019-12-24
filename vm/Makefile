#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eklompus <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/24 15:35:42 by eklompus          #+#    #+#              #
#    Updated: 2019/12/24 15:35:43 by eklompus         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

ALL_C =	vm.c \
        read_be.c \
        read_champ.c \
        read_options.c \

SRCDIR = ./srcs
OBJDIR = ./objs

ALL_OBJ = $(ALL_C:%.c=%.o)

OBJS = $(addprefix $(OBJDIR)/, $(ALL_OBJ))

NAME = corewar

INCLUDES =	./includes \
			./../common_resources \
			$(LIBFT_DIR)/includes

INCS = $(addprefix -I, $(INCLUDES))

LIBFT_DIR = ./../libft

COMP_LIB = make -C $(LIBFT_DIR)

FLAGS = -Wall -Wextra -Werror

all: $(NAME) $(VIS_NAME)

$(NAME): $(LIBFT_DIR)/libft.a $(OBJS)
	gcc $(FLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $@

$(OBJDIR):
	/bin/mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCLUDES) | $(OBJDIR)
	gcc $(FLAGS) $(INCS) -c $< -o $@

$(LIBFT_DIR)/libft.a: lib

lib:
	$(COMP_LIB)

clean:
	/bin/rm -rf $(OBJDIR)
	$(COMP_LIB) clean

fclean: clean
	/bin/rm -rf $(NAME)
	$(COMP_LIB) fclean

re: fclean all

.PHONY: lib clean fclean all re
