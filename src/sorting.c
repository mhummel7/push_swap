/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:42:21 by mhummel           #+#    #+#             */
/*   Updated: 2024/07/26 11:56:47 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	cheapest;
	int	best_position;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (stack_a->size > 3)
	{
		cheapest = find_cheapest_number(stack_a, stack_b);
		move_number(stack_a, stack_b, cheapest);
	}
	sort_three(stack_a);
	while (stack_b->size > 0)
	{
		best_position = find_best_position(stack_a, stack_b->top->data);
		move_to_position(stack_a, best_position);
		pa(stack_a, stack_b);
	}
	move_smallest_to_top(stack_a);
}