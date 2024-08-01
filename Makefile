# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/31 12:49:05 by mhummel           #+#    #+#              #
#    Updated: 2024/07/31 14:58:48 by mhummel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap
CFLAGS		:= -Wextra -Wall -Werror
LIBFT		:= ./libft

HEADERS		:= -I ./include -I $(LIBFT)
LIBS		:= $(LIBFT)/libft/libft.a
SRCS		:= src/stack_ops/op_utils.c \
				src/stack_ops/push.c \
				src/stack_ops/reverse_rotate.c \
				src/stack_ops/rotate.c \
				src/stack_ops/swap.c \
				src/main.c \
				src/input.c \
				src/stack_init.c \
				src/stack_utils.c \
				src/sort_utils.c \
				src/sort.c
OBJS		:= ${SRCS:.c=.o}

all: libft $(NAME)
	@echo " "
	@echo "\033[38;5;214m"Do ./push_swap number1 number2 ... or ./push_swap number1 number2 ..."\033[0m"

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
	@echo "\033[38;5;214m" Cleaned so_long"\033[0m"

fclean:
	@rm -f $(NAME)
	@rm -f $(OBJS)
	@make -C $(LIBFT) fclean
	@echo "\033[38;5;214m" Fcleaned $(NAME)"\033[0m"

re: fclean all

.PHONY: all clean fclean re libft
