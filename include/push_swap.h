/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:35:39 by mhummel           #+#    #+#             */
/*   Updated: 2024/08/01 11:28:19 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

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

typedef struct s_partition_info
{
	int			median;
	int			size;
	int			is_a;
}	t_partition_info;

// ------<>------ Error handling------<>------

int				error_handling_input(int argc, char **argv);
void			print_stack(t_stack_node *stack);

// ------<>------ Operations ------<>------

void			print_operation(char *operation);

void			push(t_stack_node **dst, t_stack_node **src, char *operation);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);

void			swap(t_stack_node **stack, char *operation);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);

void			rotate(t_stack_node **stack, char *operation);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);

void			reverse_rotate(t_stack_node **stack, char *operation);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

// ------<>------  Stack initation ------<>------

int				init_stack_a(t_stack_node **a, int argc, char **argv);
int				add_node(t_stack_node **stack, int value);

// ------<>------ Stack utils ------<>------

t_stack_node	*get_last_node(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
int				stack_sorted(t_stack_node *stack);
void			free_stack(t_stack_node **stack);

// ------<>------ Input------<>------

void			free_split(char **split);
int				validate_arg(char *argv);
int				check_overflow(char *argv);
int				handle_one_arg(char *argv);
int				handle_multiple_args(char **argv);

// ------<>------ Sort ------<>------

void			sort_stacks(t_stack_node **a, t_stack_node **b);
void			sort_three(t_stack_node **a);
void			sort_b(t_stack_node **a, t_stack_node **b);
void			sort_small_a(t_stack_node **a, int size);
void			sort_small_b(t_stack_node **a, t_stack_node **b, int size);
void			insertion_sort(t_stack_node **a);

// ------<>------ Sort Utils ------<>------

void			ft_sort_int_arr(int *arr, int size);
int				find_median(t_stack_node *stack, int size);
t_stack_node	*find_largest(t_stack_node *stack);
int				get_stack_position(t_stack_node *stack, t_stack_node *node);
void			merge_stacks(t_stack_node **a, t_stack_node **b);
void			partition_stack(t_stack_node **src, t_stack_node **dst,
					t_partition_info *info);

#endif