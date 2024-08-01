/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:16:03 by mhummel           #+#    #+#             */
/*   Updated: 2024/08/01 11:53:24 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack(t_stack_node *stack)
{
	while (stack)
		stack = stack->next;
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int					size;
	t_partition_info	info;
	int					a_size;
	int					b_size;

	size = stack_len(*a);
	if (size <= 3)
	{
		sort_small_a(a, size);
		return ;
	}
	info.median = find_median(*a, size);
	info.size = size;
	info.is_a = 1;
	partition_stack(a, b, &info);
	a_size = stack_len(*a);
	b_size = stack_len(*b);
	print_stack(*a);
	print_stack(*b);
	if (a_size > 3)
		sort_stacks(a, b);
	else
		sort_small_a(a, a_size);
	if (b_size > 0)
		sort_b(a, b);
	merge_stacks(a, b);
}

void	sort_three(t_stack_node **a)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)(*a)->nbr;
	second = *(int *)(*a)->next->nbr;
	third = *(int *)(*a)->next->next->nbr;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort_small_b(t_stack_node **a, t_stack_node **b, int size)
{
	if (size == 1)
		pa(a, b);
	else if (size == 2)
	{
		if (*(int *)(*b)->nbr < *(int *)(*b)->next->nbr)
			sb(b);
		pa(a, b);
		pa(a, b);
	}
	else if (size == 3)
	{
		if (*(int *)(*b)->nbr > *(int *)(*b)->next->nbr
			&& *(int *)(*b)->nbr > *(int *)(*b)->next->next->nbr)
			rb(b);
		else if (*(int *)(*b)->next->nbr > *(int *)(*b)->nbr
			&& *(int *)(*b)->next->nbr > *(int *)(*b)->next->next->nbr)
			rrb(b);
		if (*(int *)(*b)->nbr < *(int *)(*b)->next->nbr)
			sb(b);
		pa(a, b);
		pa(a, b);
		pa(a, b);
	}
}

void	sort_small_a(t_stack_node **a, int size)
{
	if (size == 2 && *(int *)(*a)->nbr > *(int *)(*a)->next->nbr)
		sa(a);
	else if (size == 3)
		sort_three(a);
}

void	sort_b(t_stack_node **a, t_stack_node **b)
{
	int					size;
	t_partition_info	info;
	int					new_b_size;
	int					new_a_size;

	size = stack_len(*b);
	if (size <= 3)
	{
		sort_small_b(a, b, size);
		return ;
	}
	info.median = find_median(*b, size);
	info.size = size;
	info.is_a = 0;
	partition_stack(b, a, &info);
	new_b_size = stack_len(*b);
	new_a_size = stack_len(*a);
	if (new_b_size > 3)
		sort_b(a, b);
	else if (new_b_size > 0)
		sort_small_b(a, b, new_b_size);
	if (new_a_size > 3)
		sort_stacks(a, b);
	else if (new_a_size > 0)
		sort_small_a(a, new_a_size);
}

void	insertion_sort(t_stack_node **a)
{
	t_stack_node	*sorted;
	t_stack_node	*current;
	t_stack_node	*tmp;

	sorted = NULL;
	while (*a)
	{
		current = *a;
		*a = (*a)->next;
		current->next = NULL;
		if (sorted == NULL || *(int *)current->nbr < *(int *)sorted->nbr)
		{
			current->next = sorted;
			sorted = current;
		}
		else
		{
			tmp = sorted;
			while (tmp->next && *(int *)current->nbr > *(int *)tmp->next->nbr)
				tmp = tmp->next;
			current->next = tmp->next;
			tmp->next = current;
		}
	}
	*a = sorted;
}

void	swap_nodes(t_stack_node **head, t_stack_node *a, t_stack_node *b)
{
	t_stack_node *prev_a = NULL;
	t_stack_node *temp = *head;

	while (temp != a)
	{
		prev_a = temp;
		temp = temp->next;
	}

	if (prev_a)
		prev_a->next = b;
	else
		*head = b;

	temp = b->next;
	b->next = a;
	a->next = temp;
}