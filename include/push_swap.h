/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:50:43 by mhummel           #+#    #+#             */
/*   Updated: 2024/07/26 11:56:19 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line.c"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

typedef struct s_stack
{
	t_list			*top;
	int				size;
}					t_stack;

// Stack operations
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

// Utility functions
t_stack	*create_stack(void);
void	push(t_stack *stack, int data);
int		pop(t_stack *stack);
void	free_stack(t_stack *stack);
int		is_sorted(t_stack *stack);

// Input processing
t_stack	*process_input(int argc, char **argv);

// Sorting algorithm
void sort_stack(t_stack *stack_a, t_stack *stack_b);

#endif
