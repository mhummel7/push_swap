/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:47:19 by mhummel           #+#    #+#             */
/*   Updated: 2024/07/03 09:45:20 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	int	tmp;

	if (stack_a->size < 2)
		return ;
	tmp = stack_a->top->data;
	stack_a->top->data = stack_a->top->next->data;
	stack_a->top->next->data = tmp;
	printf("sa\n");
}

void	sb(t_stack *stack_b)
{
	int	tmp;

	if (stack_b->size < 2)
		return ;
	tmp = stack_b->top->data;
	stack_b->top->data = stack_b->top->next->data;
	stack_b->top->next->data = tmp;
	printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	printf("ss\n");
}
