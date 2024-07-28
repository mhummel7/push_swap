/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:42:21 by mhummel           #+#    #+#             */
/*   Updated: 2024/07/27 16:50:49 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	cheapest;
	int	best_position;

	// ft_printf("Entering sort_stack\n");
	// print_stack(stack_a);
	if (is_sorted(stack_a))
	{
		// ft_printf("Stack is already sorted\n");
		return ;
	}
	// Handle small inputs directly
	if (stack_a->size <= 3)
	{
		sort_small_stack(stack_a);
		// print_stack(stack_a);
		return ;
	}
	// Push first two numbers to B
	if (stack_a->size > 1)
	{
		pb(stack_a, stack_b);
		// ft_printf("Pushed first number to B\n");
		if (stack_a->size > 1)
		{
			pb(stack_a, stack_b);
			// ft_printf("Pushed second number to B\n");
		}
	}
	// ft_printf("Starting main sorting loop\n");
	// Push numbers until 3 remain in A
	while (stack_a->size > 3)
	{
		// ft_printf("Finding cheapest number\n");
		cheapest = find_cheapest_number(stack_a, stack_b);
		// ft_printf("Cheapest number: %d\n", cheapest);
		// ft_printf("Moving number\n");
		move_number(stack_a, stack_b, cheapest);
		// ft_printf("Number moved\n");
	}
	// ft_printf("Sorting remaining elements in A\n");
	// Sort remaining elements in A
	if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size == 2
		&& stack_a->top->data > stack_a->top->next->data)
		sa(stack_a);
	// ft_printf("Pushing back to A\n");
	// Push back to A
	while (stack_b->size > 0)
	{
		// ft_printf("Finding best position\n");
		best_position = find_best_position(stack_a, stack_b->top->data);
		// ft_printf("Best position: %d\n", best_position);
		// ft_printf("Moving to position\n");
		move_to_position(stack_a, best_position);
		// ft_printf("Pushing from B to A\n");
		pa(stack_a, stack_b);
	}
	// ft_printf("Moving smallest to top\n");
	// Final arrangement
	move_smallest_to_top(stack_a);
	// print_stack(stack_a);
	// ft_printf("Sorting completed\n");
}

// void	print_stack(t_stack *stack)
// {
// 	t_list	*current;

// 	current = stack->top;
// 	ft_printf("Stack contents: ");
// 	while (current)
// 	{
// 		ft_printf("%d ", current->data);
// 		current = current->next;
// 	}
// 	ft_printf("\n");
// }

void	sort_small_stack(t_stack *stack)
{
	if (stack->size == 2)
	{
		if (stack->top->data > stack->top->next->data)
		{
			sa(stack);
			ft_printf("sa\n");
		}
	}
	else if (stack->size == 3)
	{
		sort_three(stack);
	}
}

int	find_cheapest_number(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*current;
	int		cheapest_num;
	int		cheapest_cost;
	int		current_cost;

	cheapest_num = 0;
	cheapest_cost = INT_MAX;
	current = stack_a->top;
	while (current)
	{
		current_cost = calculate_cost(stack_a, stack_b, current->data);
		if (current_cost < cheapest_cost)
		{
			cheapest_cost = current_cost;
			cheapest_num = current->data;
		}
		current = current->next;
	}
	return (cheapest_num);
}

int	calculate_cost(t_stack *stack_a, t_stack *stack_b, int num)
{
	int	cost_a;
	int	cost_b;

	cost_a = get_position(stack_a, num);
	cost_b = get_target_position(stack_b, num);
	// Optimize for simultaneous rotations
	if (cost_a < 0 && cost_b < 0)
		return (ft_max(ft_abs(cost_a), ft_abs(cost_b)));
	else if (cost_a > 0 && cost_b > 0)
		return (ft_max(cost_a, cost_b));
	else
		return (ft_abs(cost_a) + ft_abs(cost_b));
}

void	move_number(t_stack *stack_a, t_stack *stack_b, int num)
{
	int	pos_a;
	int	pos_b;

	pos_a = get_position(stack_a, num);
	pos_b = get_target_position(stack_b, num);
	// Perform rotations
	while (pos_a != 0 && pos_b != 0)
	{
		if (pos_a > 0 && pos_b > 0)
			rr(stack_a, stack_b);
		else if (pos_a < 0 && pos_b < 0)
			rrr(stack_a, stack_b);
		else
			break ;
		pos_a = (pos_a > 0) ? pos_a - 1 : pos_a + 1;
		pos_b = (pos_b > 0) ? pos_b - 1 : pos_b + 1;
	}
	// Finish rotations for stack A
	while (pos_a != 0)
	{
		if (pos_a > 0)
			ra(stack_a);
		else
			rra(stack_a);
		pos_a = (pos_a > 0) ? pos_a - 1 : pos_a + 1;
	}
	// Finish rotations for stack B
	while (pos_b != 0)
	{
		if (pos_b > 0)
			rb(stack_b);
		else
			rrb(stack_b);
		pos_b = (pos_b > 0) ? pos_b - 1 : pos_b + 1;
	}
	// Push the number to B
	pb(stack_a, stack_b);
}

// void	sort_three(t_stack *stack)
// {
// 	int	a;
// 	int	b;
// 	int	c;

// 	a = stack->top->data;
// 	b = stack->top->next->data;
// 	c = stack->top->next->next->data;
// 	if (a > b && b < c && a < c)
// 		sa(stack);
// 	else if (a > b && b > c)
// 	{
// 		sa(stack);
// 		rra(stack);
// 	}
// 	else if (a > b && b < c && a > c)
// 		ra(stack);
// 	else if (a < b && b > c && a < c)
// 	{
// 		sa(stack);
// 		ra(stack);
// 	}
// 	else if (a < b && b > c && a > c)
// 		rra(stack);
// }

void	sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	// ft_printf("Entering sort_three\n");
	if (stack->size < 3)
		return ;
	a = stack->top->data;
	b = stack->top->next->data;
	c = stack->top->next->next->data;
	// ft_printf("Initial state: %d %d %d\n", a, b, c);
	if (a > b && b > c) // 3 2 1
	{
		sa(stack);
		ft_printf("sa\n");
		rra(stack);
		ft_printf("rra\n");
	}
	else if (a > b && b < c && a > c) // 3 1 2
	{
		ra(stack);
		ft_printf("ra\n");
	}
	else if (a > b && b < c && a < c) // 2 1 3
	{
		sa(stack);
		ft_printf("sa\n");
	}
	else if (a < b && b > c && a < c) // 1 3 2
	{
		sa(stack);
		ft_printf("sa\n");
		ra(stack);
		ft_printf("ra\n");
	}
	else if (a < b && b > c && a > c) // 2 3 1
	{
		rra(stack);
		ft_printf("rra\n");
	}
	// If a < b < c, it's already sorted
	// ft_printf("Exiting sort_three\n");
}

int	find_best_position(t_stack *stack, int num)
{
	t_list	*current;
	int		position;
	int		min;
	int		max;
	int		best_pos;

	position = 0;
	min = INT_MAX;
	max = INT_MIN;
	best_pos = 0;
	current = stack->top;
	while (current)
	{
		if (current->data < min)
			min = current->data;
		if (current->data > max)
			max = current->data;
		current = current->next;
	}
	if (num < min || num > max)
		return (get_position(stack, min));
	current = stack->top;
	while (current && current->next)
	{
		if (num > current->data && num < current->next->data)
		{
			best_pos = position + 1;
			break ;
		}
		position++;
		current = current->next;
	}
	return (best_pos);
}

void	move_to_position(t_stack *stack, int position)
{
	int	stack_size;

	stack_size = stack->size;
	if (position <= stack_size / 2)
	{
		while (position > 0)
		{
			ra(stack);
			position--;
		}
	}
	else
	{
		while (position < stack_size)
		{
			rra(stack);
			position++;
		}
	}
}

void	move_smallest_to_top(t_stack *stack)
{
	int	smallest;
	int	position;

	smallest = find_smallest(stack);
	position = get_position(stack, smallest);
	move_to_position(stack, position);
}

int	get_position(t_stack *stack, int num)
{
	t_list	*current;
	int		position;

	current = stack->top;
	position = 0;
	while (current)
	{
		if (current->data == num)
			return (position);
		position++;
		current = current->next;
	}
	return (-1);
}

int	get_target_position(t_stack *stack_b, int num)
{
	t_list	*current;
	int		target_pos;
	int		best_match;
	int		stack_size;
	int		max;

	target_pos = 0;
	best_match = INT_MIN;
	stack_size = stack_b->size;
	if (stack_size == 0)
		return (0);
	current = stack_b->top;
	for (int i = 0; i < stack_size; i++)
	{
		if (current->data < num && current->data > best_match)
		{
			best_match = current->data;
			target_pos = i;
		}
		current = current->next;
	}
	if (best_match == INT_MIN)
	{
		max = find_max(stack_b);
		target_pos = get_position(stack_b, max);
	}
	target_pos = (target_pos + 1) % stack_size;
	return (target_pos);
}

int	find_max(t_stack *stack)
{
	t_list	*current;
	int		max;

	current = stack->top;
	max = INT_MIN;
	while (current)
	{
		if (current->data > max)
			max = current->data;
		current = current->next;
	}
	return (max);
}

int	find_smallest(t_stack *stack)
{
	t_list	*current;
	int		smallest;

	current = stack->top;
	smallest = INT_MAX;
	while (current)
	{
		if (current->data < smallest)
			smallest = current->data;
		current = current->next;
	}
	return (smallest);
}

int	ft_max(int a, int b)
{
	return ((a > b) ? a : b);
}

int	ft_abs(int n)
{
	return ((n < 0) ? -n : n);
}
