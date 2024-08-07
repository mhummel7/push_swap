/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:16:03 by mhummel           #+#    #+#             */
/*   Updated: 2024/08/08 01:17:25 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_two(t_stack **stack_a)
{
	if (!stack_sorted(*stack_a))
		sa(stack_a);
}

void	sort_three(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->i;
	second = (*stack_a)->next->i;
	third = (*stack_a)->next->next->i;
	if (first > second && second < third && first < third)
		sa(stack_a);
	if (first > second && second < third && first > third)
		ra(stack_a);
	if (first < second && second > third && first > third)
		rra(stack_a);
	if (first > second && second > third && first > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	if (first < second && second > third && first < third)
	{
		sa(stack_a);
		ra(stack_a);
	}
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	smallest;

	i = 1;
	smallest = get_smallest(*stack_a, &i);
	while ((*stack_a)->i > smallest)
	{
		if (i < 3)
			ra(stack_a);
		else
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	smallest;

	i = 1;
	smallest = get_smallest(*stack_a, &i);
	while ((*stack_a)->i > smallest)
	{
		if (i < 3)
			ra(stack_a);
		else
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_all(t_stack **stack_a, t_stack **stack_b)
{
	int	biggest;
	int	size;
	int	i;
	int	j;
	int	b;

	b = 0;
	i = -1;
	biggest = get_biggest(*stack_a);
	size = stack_len(*stack_a);
	while (((biggest) >> b) != 0)
		b++;
	while (++i < b)
	{
		j = -1;
		while (++j < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (stack_len(*stack_b))
			pa(stack_a, stack_b);
	}
}
