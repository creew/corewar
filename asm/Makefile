# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/29 09:12:50 by rmarni            #+#    #+#              #
#    Updated: 2019/12/26 16:43:23 by rmarni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	asm

#						*****	OBJECT FILES	******
SRC 	=	adding.o \
			adding2.o \
			assembler.o \
			awm.o \
			clears.o \
			convertation.o \
			delete_comments.o \
			fill_instr.o \
			ft_exit.o \
			init_awm.o \
			main.o \
			my_librires_functions.o \
			op.o \
			valid_args.o \
			exit2.o \
			valid_args_commands.o \
			valid_args_commands2.o \
 			valid_args_commands3.o \
			valid_commands.o \
			valid_commands2.o \
			valid_commands3.o \
			valid_names.o \
			what_is_it.o \
			what_is_it2.o

SRCDIR	= 	$(addprefix ./, $(SRC))
LIBDIR	=	./../libft/
PRINTF_DIR = ./../ft_printf/

#						*****	COLLORS			*****
GREEN 		=	\033[0;32m
RED 		=	\033[0;31m 
YELLOW		=	\033[0;33m 
RESET 		= 	\033[0m


CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
				@echo "$(GREEN)asm:$(RESET) [Compilation:$(YELLOW) $@$(RESET)]"
				$(CC) -o $@ -c $< -I$(LIBDIR)includes -I$(PRINTF_DIR)includes #$(CFLAGS)

$(NAME): lib $(PRINTF_DIR)libftprintf.a $(SRCDIR)
				@echo "$(NAME): creating $(NAME)...$(GREEN) OK!$(RESET)"
				@$(CC) $(CFLAGS) $(SRCDIR) -o $(NAME) -L $(LIBDIR) -lft -L $(PRINTF_DIR) -lftprintf

$(PRINTF_DIR)libftprintf.a:
				@echo "$(NAME): creating FT_PRINTF_LIB...$(GREEN)OK!$(RESET)"
				@make -C $(PRINTF_DIR)

lib:
				@echo "$(NAME): creating LIBFT...$(GREEN)OK!$(RESET)"
				@make -C $(LIBDIR)

clean:
				@make -C $(PRINTF_DIR) clean
				@make -C $(LIBDIR) clean
				@rm -rf $(SRCDIR)

fclean:
				@echo "$(NAME): delete all files...$(GREEN) OK!$(RESET)"
				@make -C ft_printf/ fclean
				@make -C libft/ fclean
				@make clean
				@rm -rf ./asm

re: fclean all

.PHONY: re clean fclean all lib ft_printf
