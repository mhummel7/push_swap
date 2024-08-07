/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:15:51 by mhummel           #+#    #+#             */
/*   Updated: 2024/08/08 00:12:47 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	stack_sorted(t_stack *stack)
{
	int	prev;

	if (!stack)
		print_error(stack, NULL);
	prev = stack->i;
	stack = stack->next;
	while (stack)
	{
		if (prev > stack->i)
			return (0);
		prev = stack->i;
		stack = stack->next;
	}
	return (1);
}

int	has_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*next;

	current = stack;
	while (current)
	{
		next = current->next;
		while (next)
		{
			if (current->i == next->i)
				return (1);
			next = next->next;
		}
		current = current->next;
	}
	return (0);
}

int	check_error(t_stack *stack, char **tab, int i)
{
	return (not_number(tab, i) || has_duplicates(stack));
}
