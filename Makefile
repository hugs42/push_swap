# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/15 10:55:03 by hugsbord          #+#    #+#              #
#    Updated: 2021/10/27 17:07:50 by hugsbord         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

SRCS =	./srcs/main.c \
		./srcs/parser.c \
		./srcs/init.c \
		./srcs/check.c \
		./srcs/op_swap.c \
		./srcs/op_push.c \
		./srcs/op_rotate.c \
		./srcs/op_reverse.c

INC = -I ./includes

FLAGS = -Wall -Wextra -Werror

LIBS = -L ./libft
LIBFT = ./libft/libft.a

OBJ = $(SRCS:.c=.o)

%.o: %.c
	@clang $(INC) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[96m"
	@echo "                            :::      ::::::::"
	@echo "                          :+:      :+:    :+:"
	@echo "    42_cursus:          +:+ +:+         +:+"
	@echo "    PUSH_SWAP         +#+  +:+       +#+"
	@echo "                    +#+#+#+#+#+   +#+"
	@echo "                          #+#    #+#"
	@echo "                         ###   ########.fr\033[0m"
	@echo "\033[0m"
	@echo "\033[93m>> Libft compilation\033[0m"
	@make -C libft
	@echo "\033[93m>> Push_swap compilation\033[0m"
	@clang $(FLAGS) $(INC) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "\033[92mPush_swap correctly compilated\033[0m"

clean: $(OBJ)
	@echo "\033[93m>> Cleaning objects (.obj)\033[0m"
	@make $@ -C libft
	@rm -f $(OBJ)

fclean: clean
	@make $@ -C libft
	@rm -f $(NAME)

re:
	@make fclean
	@make all

bonus: $(NAME)

.PHONY: all, clean, fclean, re, bonus

