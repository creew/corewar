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
SRC 	=	src/adding.o \
			src/adding2.o \
			src/assembler.o \
			src/awm.o \
			src/clears.o \
			src/convertation.o \
			src/delete_comments.o \
			src/fill_instr.o \
			src/ft_exit.o \
			src/init_awm.o \
			src/main.o \
			src/my_librires_functions.o \
			src/valid_args.o \
			src/exit2.o \
			src/valid_args_commands.o \
			src/valid_args_commands2.o \
 			src/valid_args_commands3.o \
			src/valid_commands.o \
			src/valid_commands2.o \
			src/valid_commands3.o \
			src/valid_names.o \
			src/what_is_it.o \
			src/what_is_it2.o

COMMON_SRC = ../common_resources/op.c
COMMON_OBJ = ./src/op.o

INCLUDES = 	$(LIBDIR)includes \
			$(PRINTF_DIR)includes\
			./includes \
			../common_resources

INC_FLAG = $(addprefix -I, $(INCLUDES))

SRCDIR	= 	$(addprefix ./, $(SRC))
LIBDIR	=	./../libft/
PRINTF_DIR = ./../ft_printf/

#						*****	COLLORS			*****
GREEN 		=	\033[0;32m
RED 		=	\033[0;31m 
YELLOW		=	\033[0;33m 
RESET 		= 	\033[0m


CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g

all: $(NAME)

%.o: %.c
				@echo "$(GREEN)asm:$(RESET) [Compilation:$(YELLOW) $@$(RESET)]"
				$(CC) -o $@ -c $< $(INC_FLAG) #$(CFLAGS)

$(COMMON_OBJ): $(COMMON_SRC) ../common_resources/op.h
				@echo "$(GREEN)asm:$(RESET) [Compilation:$(YELLOW) $@$(RESET)]"
				$(CC) -o $@ -c $< $(INC_FLAG) #$(CFLAGS)

$(NAME): $(LIBDIR)libft.a $(PRINTF_DIR)libftprintf.a $(SRCDIR) $(COMMON_OBJ)
				@echo "$(NAME): creating $(NAME)...$(GREEN) OK!$(RESET)"
				$(CC) $(CFLAGS) $(SRCDIR) $(COMMON_OBJ) -o $(NAME) -L $(LIBDIR) -lft -L $(PRINTF_DIR) -lftprintf

$(PRINTF_DIR)libftprintf.a: ft_printf

ft_printf:
				@echo "$(NAME): creating FT_PRINTF_LIB...$(GREEN)OK!$(RESET)"
				@make -C $(PRINTF_DIR)

$(LIBDIR)libft.a: libft

libft:
				@echo "$(NAME): creating LIBFT...$(GREEN)OK!$(RESET)"
				@make -C $(LIBDIR)

clean:
				@make -C $(PRINTF_DIR) clean
				@make -C $(LIBDIR) clean
				@rm -rf $(SRCDIR)
				@rm -rf $(COMMON_OBJ)

fclean:
				@echo "$(NAME): delete all files...$(GREEN) OK!$(RESET)"
				@make -C $(PRINTF_DIR) fclean
				@make -C $(LIBDIR) fclean
				@make clean
				@rm -rf ./asm

re: fclean all

.PHONY: re clean fclean all libft ft_printf
