/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:39:08 by mhummel           #+#    #+#             */
/*   Updated: 2024/07/31 12:40:16 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	reverse_rotate(t_stack_node **stack, char *operation)
{
	t_stack_node	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = get_last_node(*stack);
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = tmp;
	if (operation)
		print_operation(operation);
}

void	rra(t_stack_node **a)
{
	reverse_rotate(a, "rra");
}

void	rrb(t_stack_node **b)
{
	reverse_rotate(b, "rrb");
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a, NULL);
	reverse_rotate(b, "rrr");
}
