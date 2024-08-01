/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:57:27 by mhummel           #+#    #+#             */
/*   Updated: 2024/08/01 11:33:42 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	init_stack_a(t_stack_node **a, int argc, char **argv)
{
	int		i;
	long	nbr;

	i = 1;
	while (i < argc)
	{
		if (check_overflow(argv[i]))
			return (1);
		nbr = ft_atol(argv[i]);
		if (add_node(a, (int)nbr))
			return (1);
		i++;
	}
	return (0);
}

int	add_node(t_stack_node **stack, int value)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	new_node = malloc(sizeof(t_stack_node));
	if (new_node == NULL)
		return (1);
	new_node->nbr = malloc(sizeof(int));
	if (new_node->nbr == NULL)
	{
		free(new_node);
		return (1);
	}
	*(int *)new_node->nbr = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		last_node = get_last_node(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
	return (0);
}
