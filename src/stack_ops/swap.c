/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:22:58 by mhummel           #+#    #+#             */
/*   Updated: 2024/07/31 12:38:06 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	swap(t_stack_node **stack, char *operation)
{
	t_stack_node	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
	(*stack)->prev = NULL;
	if (tmp->next)
		tmp->next->prev = tmp;
	if (operation)
		print_operation(operation);
}

void	sa(t_stack_node **a)
{
	swap(a, "sa");
}

void	sb(t_stack_node **b)
{
	swap(b, "sb");
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a, NULL);
	swap(b, "ss");
}
