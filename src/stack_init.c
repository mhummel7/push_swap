/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:57:27 by mhummel           #+#    #+#             */
/*   Updated: 2024/08/08 01:16:07 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*create_stack(t_stack *stack, int j, char **argv, char **tab)
{
	int	i;

	i = tab_len(argv) - 1;
	while (i >= j)
	{
		stack = add_stack(stack, argv[i], tab);
		i--;
	}
	return (stack);
}

t_stack	*add_stack(t_stack *stack, char *c, char **tab)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->i = ft_atoi_push_swap(c, stack, tab);
	new->next = stack;
	return (new);
}

void	put_index(t_stack *stack)
{
	t_stack	*next;
	t_stack	*current;

	current = stack;
	while (current)
	{
		current->index = 0;
		next = stack;
		while (next)
		{
			if (current->i > next->i)
				current->index++;
			next = next->next;
		}
		current = current->next;
	}
}
