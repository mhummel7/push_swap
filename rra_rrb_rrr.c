/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:59:43 by mhummel           #+#    #+#             */
/*   Updated: 2024/05/16 11:00:06 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack_a)
{
	t_list	*tmp;
	t_list	*last;

	if (stack_a->size < 2)
		return ;
	tmp = stack_a->top;
	stack_a->top = stack_a->top->next;
	last = stack_a->top;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
}

void	rrb(t_stack *stack_b)
{
	rra(stack_b);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}