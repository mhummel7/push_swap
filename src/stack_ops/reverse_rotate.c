/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:39:08 by mhummel           #+#    #+#             */
/*   Updated: 2024/08/08 00:48:04 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rra(t_stack **stack_a)
{
	t_stack	*new_first;
	t_stack	*new_last;

	new_first = get_last_node(*stack_a);
	new_last = get_before_last_node(*stack_a);
	new_first->next = *stack_a;
	new_last->next = NULL;
	*stack_a = new_first;
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	t_stack	*new_first;
	t_stack	*new_last;

	new_first = get_last_node(*stack_b);
	new_last = get_before_last_node(*stack_b);
	new_first->next = *stack_b;
	new_last->next = NULL;
	*stack_b = new_first;
	write(1, "rra\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write(1, "rrr\n", 4);
}
