/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:47:19 by mhummel           #+#    #+#             */
/*   Updated: 2024/05/17 13:02:46 by mhummel          ###   ########.fr       */
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
	stack_a->top->next = tmp;
}

void	sb(t_stack *stack_b)
{
	sa(stack_b);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
