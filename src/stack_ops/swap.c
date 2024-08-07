/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:22:58 by mhummel           #+#    #+#             */
/*   Updated: 2024/08/08 00:52:31 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sa(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*temp;

	first = *stack_a;
	temp = (*stack_a)->next;
	first->next = temp->next;
	temp->next = first;
	*stack_a = temp;
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*temp;

	first = *stack_b;
	temp = (*stack_b)->next;
	first->next = temp->next;
	temp->next = first;
	*stack_b = temp;
	write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}
