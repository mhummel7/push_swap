# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 10:05:10 by mhummel           #+#    #+#              #
#    Updated: 2024/07/03 09:56:24 by mhummel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := push_swap
CFLAGS      := -Wextra -Wall -Werror
LIBFT       := ./libft

HEADERS     := -I ./include -I $(LIBFT)
LIBS        := $(LIBFT)/libft.a
SRCS        := $(shell find ./src -iname "*.c")
OBJS        := ${SRCS:.c=.o}

all: libft $(NAME)

libft:
	@make -C $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
	@echo "\033[32m" Compiled "$<""\033[0m"

$(NAME): libft $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT) clean
	@echo "\033[38;5;214m" Cleaned "\033[0m"

fclean:
	@rm -f $(NAME)
	@rm -f $(OBJS)
	@make -C $(LIBFT) fclean
	@echo "\033[38;5;214m" Fcleaned $(NAME)"\033[0m"

re: fclean all

.PHONY: all clean fclean re libft