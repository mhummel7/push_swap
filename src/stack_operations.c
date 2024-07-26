/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:42:06 by mhummel           #+#    #+#             */
/*   Updated: 2024/07/03 09:45:40 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void	push(t_stack *stack, int data)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->data = data;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

int	pop(t_stack *stack)
{
	t_list	*temp;
	int		data;

	if (!stack->top)
		return (0);
	temp = stack->top;
	data = temp->data;
	stack->top = stack->top->next;
	free(temp);
	stack->size--;
	return (data);
}

void	free_stack(t_stack *stack)
{
	while (stack->top)
		pop(stack);
	free(stack);
}

int	is_sorted(t_stack *stack)
{
	t_list	*current;

	current = stack->top;
	while (current && current->next)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}
