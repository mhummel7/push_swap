/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:53:17 by mhummel           #+#    #+#             */
/*   Updated: 2024/07/03 09:57:59 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_duplicate(t_stack *stack, int num)
{
	t_list	*current;

	current = stack->top;
	while (current)
	{
		if (current->data == num)
			return (1);
		current = current->next;
	}
	return (0);
}

static int	process_arg(t_stack *stack, char *arg)
{
	long	num;

	if (!is_number(arg))
		return (0);
	num = ft_atoi(arg);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	if (is_duplicate(stack, (int)num))
		return (0);
	push(stack, (int)num);
	return (1);
}

t_stack	*process_input(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	stack = create_stack();
	if (!stack)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		if (!process_arg(stack, argv[i]))
		{
			free_stack(stack);
			ft_putendl_fd("Error", 2);
			exit(1);
		}
		i++;
	}
	return (stack);
}
