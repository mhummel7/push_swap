/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:20:49 by mhummel           #+#    #+#             */
/*   Updated: 2024/07/31 12:31:49 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	print_operation(const char *operation)
{
	ft_printf("%s\n", operation);
}

void	push(t_stack_node **dst, t_stack_node **src, char *operation)
{
	t_stack_node	*tmp;

	if (*src == NULL)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = *dst;
	tmp->prev = NULL;
	if (*dst)
		(*dst)->prev = tmp;
	*dst = tmp;
	if (operation)
		print_op(operation);
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a, b, "pa");
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	push(b, a, "pb");
}
