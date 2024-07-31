/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:35:39 by mhummel           #+#    #+#             */
/*   Updated: 2024/07/31 12:35:56 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>

# include "../libft/libft/libft.h"
# include "../libft/get_next_line/get_next_line.h"
# include "../libft/ft_printf/ft_printf.h"

typedef struct s_stack_node
{
	void					*nbr;
	int						index;
	int						push_cost;
	bool					above_median;
	bool					cheapest;
	struct s_stack_node		*target_node;
	struct s_stack_node		*next;
	struct s_stack_node		*prev;
}	t_stack_node;

// ------<>------ Error handling------<>------

// ------<>------  Stack initation ------<>------

// ------<>------ Nodes initation ------<>------

// ------<>------ Stack utils ------<>------

// ------<>------ Operations ------<>------

void	print_operation(const char *operation);

void	push(t_stack_node **dst, t_stack_node **src, char *operation);
void	pa(t_stack_node **a, t_stack_node **b);
void	pb(t_stack_node **a, t_stack_node **b);

void	swap(t_stack_node **stack, char *operation);
void	sa(t_stack_node **a);
void	sb(t_stack_node **b);
void	ss(t_stack_node **a, t_stack_node **b);

// ------<>------ Algorithms ------<>------

#endif