# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynenakho <ynenakho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/19 18:23:28 by ynenakho          #+#    #+#              #
#    Updated: 2019/03/23 00:03:55 by ynenakho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_minishell
CC = gcc
FLAGS = -Wall -Wextra -Werror -g
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

DEPS = minishell.h
LIBS = ./libft/libft.a

all: libftcreate $(NAME)

%.o: %.c $(DEPS)
	@echo "\033[1;32m\c"
	$(CC) -c -o $@ $< $(FLAGS)
	@echo "\033[0m\c"

$(NAME): $(OBJ)
	@echo "\033[0;32m\c"
	$(CC) -o $@ $^ $(FLAGS) $(LIBS)
	@echo "\033[0m\c"

libftcreate:
	@echo "\033[1;32m\c"
	@$(MAKE) -C ./libft
	@echo "\033[0m\c"

clean:
	@$(MAKE) clean -C ./libft
	@/bin/rm -f $(OBJ)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@/bin/rm -f $(NAME)

re: fclean all
