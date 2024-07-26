/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:59:43 by mhummel           #+#    #+#             */
/*   Updated: 2024/07/03 09:45:50 by mhummel          ###   ########.fr       */
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
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = stack_a->top;
	stack_a->top = last;
	printf("rra\n");
}

void	rrb(t_stack *stack_b)
{
	t_list	*tmp;
	t_list	*last;

	if (stack_b->size < 2)
		return ;
	tmp = stack_b->top;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = stack_b->top;
	stack_b->top = last;
	printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	printf("rrr\n");
}
