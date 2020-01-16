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

NAME 	=	corewar

ASM_DIR	=	./asemb/
VM_DIR	=	./vm/

#						*****	COLLORS			*****
GREEN 		=	\033[0;32m
RED 		=	\033[0;31m 
YELLOW		=	\033[0;33m 
RESET 		= 	\033[0m


CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g

all: 
				@make -C $(ASM_DIR)
				mv $(ASM_DIR)asm ./
#				@make -C $(VM_DIR)

clean:
				@make -C $(ASM_DIR) clean
#				@make -C $(VM_DIR) clean
#				@rm -rf $(SRCDIR)
#				@rm -rf $(COMMON_OBJ)

fclean:
#				@echo "$(NAME): delete all files...$(GREEN) OK!$(RESET)"
#				@make -C $(PRINTF_DIR) fclean
#				@make -C $(LIBDIR) fclean
#				@make clean
				@rm -rf ./asm

re: fclean all

.PHONY: re clean fclean all lib ft_printf
