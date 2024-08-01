/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:17:46 by mhummel           #+#    #+#             */
/*   Updated: 2024/08/01 12:07:31 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void partition_stack(t_stack_node **src, t_stack_node **dst, t_partition_info *info)
{
    int i;
    int push_count;

    i = 0;
    push_count = 0;
    while (*src && i < info->size && push_count < info->size / 2)
    {
        if (*(int *)(*src)->nbr < info->median)
        {
            if (info->is_a)
                pb(dst, src);
            else
                pa(dst, src);
            push_count++;
        }
        else
        {
            if (info->is_a)
                ra(src);
            else
                rb(src);
        }
        i++;
    }
    if (push_count == 0 && *src)
    {
        if (info->is_a)
            pb(dst, src);
        else
            pa(dst, src);
    }
}

void	ft_sort_int_arr(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	find_median(t_stack_node *stack, int size)
{
	int	*arr;
	int	i;
	int	median;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		exit(ft_print_error());
	i = 0;
	while (i < size)
	{
		arr[i] = *(int *)stack->nbr;
		stack = stack->next;
		i++;
	}
	ft_sort_int_arr(arr, size);
	median = arr[size / 2];
	free(arr);
	return (median);
}

void	merge_stacks(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*tmp;

	while (*b)
	{
		tmp = *b;
		*b = (*b)->next;
		if (*b)
			(*b)->prev = NULL;
		tmp->next = *a;
		tmp->prev = NULL;
		if (*a)
			(*a)->prev = tmp;
		*a = tmp;
	}
}

t_stack_node	*find_largest(t_stack_node *stack)
{
	t_stack_node	*largest;
	int				max;

	if (!stack)
	{
		ft_print_error();
		exit(1);
	}
	largest = stack;
	max = *(int *)stack->nbr;
	while (stack)
	{
		if (*(int *)stack->nbr > max)
		{
			max = *(int *)stack->nbr;
			largest = stack;
		}
		stack = stack->next;
	}
	return (largest);
}

int	get_stack_position(t_stack_node *stack, t_stack_node *node)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack == node)
			return (pos);
		stack = stack->next;
		pos++;
	}
	ft_print_error();
	return (1);
}
