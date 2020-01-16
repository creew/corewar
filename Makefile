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

COREWAR 	=	corewar
ASM			=	asm

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
				@make -C $(VM_DIR)
				cp $(VM_DIR)corewar corewar
				@make -C $(ASM_DIR)
				cp $(ASM_DIR)asm asm

clean:
				@make -C $(ASM_DIR) clean
				@make -C $(VM_DIR) clean

fclean: clean
				@echo "$(NAME): delete all files...$(GREEN) OK!$(RESET)"
				@make -C $(ASM_DIR) fclean
				@make -C $(VM_DIR) fclean

				@rm -rf ./asm
				@rm -rf ./corewar

re: fclean all

.PHONY: re clean fclean all
