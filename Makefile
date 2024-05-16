# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 10:05:10 by mhummel           #+#    #+#              #
#    Updated: 2024/05/16 10:06:52 by mhummel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a

all: $(NAME)

$(NAME): libft printf
	@echo "\033[32m" Compiled"\033[0m"

$(NAME):  $(LIBFT) $(PRINTF) $(NAME)
	@$(CC) $(CFLAGS)  $(LIBFT) $(PRINTF) -o $(NAME)


libft:
	@make -C libft

printf:
	@make -C ft_printf

clean:
	rm -f $(NAME)
	@make -C libft clean
	@make -C ft_printf clean
	@echo "Cleaned"

fclean: clean
	rm -f $(LIBFT) $(PRINTF)
	@echo "Fcleaned"

re: fclean all

.PHONY: all clean fclean re libft printf