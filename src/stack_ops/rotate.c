/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:36:28 by mhummel           #+#    #+#             */
/*   Updated: 2024/07/31 12:38:54 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rotate(t_stack_node **stack, char *operation)
{
	t_stack_node	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	tmp->next = NULL;
	tmp->prev = get_last_node(*stack);
	tmp->prev->next = tmp;
	if (operation)
		print_operation(operation);
}

void	ra(t_stack_node **a)
{
	rotate(a, "ra");
}

void	rb(t_stack_node **b)
{
	rotate(b, "rb");
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a, NULL);
	rotate(b, "rr");
}
