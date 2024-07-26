/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:58:26 by mhummel           #+#    #+#             */
/*   Updated: 2024/07/03 09:45:53 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a)
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
	printf("ra\n");
}

void	rb(t_stack *stack_b)
{
	t_list	*tmp;
	t_list	*last;

	if (stack_b->size < 2)
		return ;
	tmp = stack_b->top;
	stack_b->top = stack_b->top->next;
	last = stack_b->top;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
	printf("rr\n");
}
