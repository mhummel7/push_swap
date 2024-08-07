/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:36:28 by mhummel           #+#    #+#             */
/*   Updated: 2024/08/08 00:50:30 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ra(t_stack **stack_a)
{
	t_stack	*new_first;
	t_stack	*temp;

	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	new_first = get_last_node(*stack_a);
	temp->next = NULL;
	new_first->next = temp;
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	t_stack	*new_first;
	t_stack	*temp;

	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	new_first = get_last_node(*stack_b);
	temp->next = NULL;
	new_first->next = temp;
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}
