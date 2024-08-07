/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:17:46 by mhummel           #+#    #+#             */
/*   Updated: 2024/08/08 00:24:09 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	stack_len(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

int	get_biggest(t_stack *stack)
{
	t_stack	*biggest;

	biggest = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->index > biggest->index)
			biggest = stack;
		stack = stack->next;
	}
	return (biggest->index);
}

int	get_smallest(t_stack *stack, int *i)
{
	t_stack	*smallest;

	smallest = stack;
	stack = stack->next;
	while (stack)
	{
		if (smallest->i > stack->i)
		{
			*i += 1;
			smallest = stack;
		}
		stack = stack->next;
	}
	return (smallest->i);
}

t_stack	*get_last_node(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*get_before_last_node(t_stack *stack)
{
	while (stack->next->next)
		stack = stack->next;
	return (stack);
}
