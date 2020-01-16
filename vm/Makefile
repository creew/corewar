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
		check_op_types.c \
		control.c \
		create_dump.c \
		dl_list.c \
		errors.c \
		exec_process.c \
		init_vm.c \
		parse_arg.c \
		process_cycle.c \
		read_be.c \
		read_champ.c \
		read_options.c \
		vm.c \
		commands/get_command_arg.c \
		commands/process_add_run.c \
		commands/process_aff_run.c \
		commands/process_and_run.c \
		commands/process_fork_run.c\
		commands/process_ld_run.c \
		commands/process_ldi_run.c \
		commands/process_lfork_run.c \
		commands/process_live_run.c \
		commands/process_lld_run.c \
		commands/process_lldi_run.c \
		commands/process_or_run.c \
		commands/process_st_run.c \
		commands/process_sti_run.c \
        commands/process_sub_run.c \
        commands/process_xor_run.c \
        commands/process_zjmp_run.c \
		visu/deinit.c \
		visu/draw_all.c \
		visu/draw_carriages.c \
		visu/draw_info.c \
		visu/get_color.c \
		visu/init.c \
		visu/print.c \
		visu/process.c \
		visu/reload_carriages.c \
		visu/reload_fonts.c \

SRCDIR = ./srcs
OBJDIR = ./objs

LIBFT_DIR = ./../libft

LIBFTPRINTF_DIR = ./../ft_printf

ALL_OBJ = $(ALL_C:%.c=%.o)

OBJS = $(addprefix $(OBJDIR)/, $(ALL_OBJ))

COMMON_OBJS = $(addprefix $(OBJDIR)/, common/op.o)

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

FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(LIBFT_DIR)/libft.a $(LIBFTPRINTF_DIR)/libftprintf.a $(OBJS) $(COMMON_OBJS)
	gcc $(FLAGS) $(OBJS) $(COMMON_OBJS) $(LIB_DIR_FLAG) $(LIBS_FLAG) -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJDIR)/visu
	mkdir -p $(OBJDIR)/commands
	mkdir -p $(OBJDIR)/common

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADER_FILES) | $(OBJDIR)
	gcc $(FLAGS) $(INCS) -c $< -o $@

$(COMMON_OBJS): ./../common_resources/op.c $(HEADER_FILES)
	gcc $(FLAGS) $(INCS) -c $< -o $@

$(LIBFT_DIR)/libft.a: libft

libft:
	$(COMP_LIBFT)

$(LIBFTPRINTF_DIR)/libftprintf.a: ft_printf

ft_printf:
	$(COMP_LIBFTPRINTF)

clean:
	rm -rf $(OBJDIR)
	$(COMP_LIBFT) clean
	$(COMP_LIBFTPRINTF) clean

fclean: clean
	rm -rf $(NAME)
	$(COMP_LIBFT) fclean
	$(COMP_LIBFTPRINTF) fclean

re: fclean all

.PHONY: lib clean fclean all re
