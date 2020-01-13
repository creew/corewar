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

ALL_C =	check_arguments.c \
		control.c \
		create_dump.c \
		dl_list.c \
		errors.c \
		game_field.c \
		parse_arg.c \
		processes.c \
		read_be.c \
		read_champ.c \
		read_options.c \
		run_commands.c \
		vm.c \
		visu/deinit.c \
		visu/draw_all.c \
		visu/draw_info.c \
		visu/get_color.c \
		visu/init.c \
		visu/print.c \
		visu/process.c \
		visu/reload_fonts.c \

SRCDIR = ./srcs
OBJDIR = ./objs

LIBFT_DIR = ./../libft

LIBFTPRINTF_DIR = ./../ft_printf

ALL_OBJ = $(ALL_C:%.c=%.o)

OBJS = $(addprefix $(OBJDIR)/, $(ALL_OBJ))

COMMON_OBJS = ./../common_resources/op.o

NAME = corewar

INCLUDES =	./includes \
			./../common_resources \
			$(LIBFT_DIR)/includes \
			$(LIBFTPRINTF_DIR)/includes

HEADER_FILES = ./includes/errors.h \
			./includes/visu.h \
			./includes/vm.h \
			./../common_resources/op.h

INCS = $(addprefix -I, $(INCLUDES)) `sdl2-config --cflags`

LIB_DIR =	$(LIBFT_DIR) \
			$(LIBFTPRINTF_DIR) \

LIB_DIR_FLAG = $(addprefix -L,$(LIB_DIR))

LIBS = 		ft \
			ftprintf \
			SDL2 \
			SDL2_ttf \
			SDL2_gfx \
			m

LIBS_FLAG = $(addprefix -l,$(LIBS)) `sdl2-config --libs`

COMP_LIBFT = make -C $(LIBFT_DIR)

COMP_LIBFTPRINTF = make -C $(LIBFTPRINTF_DIR)

FLAGS = -Wall -Wextra -O3 -g

all: $(NAME)

$(NAME): $(LIBFT_DIR)/libft.a $(LIBFTPRINTF_DIR)/libftprintf.a $(OBJS) $(COMMON_OBJS)
	gcc $(FLAGS) $(OBJS) $(COMMON_OBJS) $(LIB_DIR_FLAG) $(LIBS_FLAG) -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJDIR)/visu

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADER_FILES) | $(OBJDIR)
	gcc $(FLAGS) $(INCS) -c $< -o $@

$(COMMON_OBJS): ./../common_resources/op.c $(HEADER_FILES)
	gcc $(FLAGS) $(INCS) -c $< -o $@

$(LIBFT_DIR)/libft.a:
	$(COMP_LIBFT)

$(LIBFTPRINTF_DIR)/libftprintf.a:
	$(COMP_LIBFTPRINTF)

clean:
	rm -rf $(OBJDIR)
	rm -rf ./../common_resources/op.o
	$(COMP_LIBFT) clean
	$(COMP_LIBFTPRINTF) clean

fclean: clean
	rm -rf $(NAME)
	$(COMP_LIBFT) fclean
	$(COMP_LIBFTPRINTF) fclean

re: fclean all

.PHONY: lib clean fclean all re
