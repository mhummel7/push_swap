/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:35:39 by mhummel           #+#    #+#             */
/*   Updated: 2024/08/08 01:16:53 by mhummel          ###   ########.fr       */
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

typedef struct s_stack	t_stack;

struct s_stack
{
	int						i;
	int						index;
	t_stack					*next;
};

// ------<>------ Error handling------<>------

void		print_error(t_stack *stack, char **tab);
void		free_stack(t_stack *stack);
void		free_tab(char **tab);

// ------<>------ Operations ------<>------

void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);

void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);

void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);

void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);

// ------<>------  Stack initation ------<>------

t_stack		*create_stack(t_stack *stack, int j, char **argv, char **tab);
t_stack		*add_stack(t_stack *stack, char *c, char **tab);
void		put_index(t_stack *stack);

// ------<>------ Stack utils ------<>------

int			stack_sorted(t_stack *stack);
int			has_duplicates(t_stack *stack);
int			check_error(t_stack *stack, char **tab, int i);

// ------<>------ Utils ------<>------

int			not_number(char **tab, int i);
int			ft_atoi_push_swap(char *str, t_stack *stack, char **tab);
int			tab_len(char **tab);

// ------<>------ Sort ------<>------

void		sort(int len, t_stack **stack_a, t_stack **stack_b);
void		sort_two(t_stack **stack_a);
void		sort_three(t_stack **stack_a);
void		sort_four(t_stack **stack_a, t_stack **stack_b);
void		sort_five(t_stack **stack_a, t_stack **stack_b);
void		sort_all(t_stack **stack_a, t_stack **stack_b);

// ------<>------ Sort Utils ------<>------

int			stack_len(t_stack *stack);
int			get_biggest(t_stack *stack);
int			get_smallest(t_stack *stack, int *i);
t_stack		*get_last_node(t_stack *stack);
t_stack		*get_before_last_node(t_stack *stack);

#endif
