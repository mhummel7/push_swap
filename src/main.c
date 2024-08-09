/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:32:15 by mhummel           #+#    #+#             */
/*   Updated: 2024/08/09 14:27:22 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort(int len, t_stack **stack_a, t_stack **stack_b)
{
	if (has_duplicates(*stack_a))
		print_error(*stack_a, NULL);
	if (stack_sorted(*stack_a))
		return ;
	put_index(*stack_a);
	if (len == 2)
		sort_two(stack_a);
	else if (len == 3)
		sort_three(stack_a);
	else if (len == 4)
		sort_four(stack_a, stack_b);
	else if (len == 5)
		sort_five(stack_a, stack_b);
	else
		sort_all(stack_a, stack_b);
}

int	check_argument(char *arg)
{
	int	i;
	int	has_digit;

	if (!arg || arg[0] == '\0')
		return (0);
	i = 0;
	has_digit = 0;
	while (arg[i])
	{
		if (arg[i] == ' ')
			i++;
		else if ((arg[i] == '+' || arg[i] == '-') && (i == 0 || arg[i
					- 1] == ' ') && ft_isdigit(arg[i + 1]))
			i++;
		else if (ft_isdigit(arg[i]))
		{
			has_digit = 1;
			i++;
		}
		else
			return (0);
	}
	return (has_digit);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**tab;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (1);
	if (argc == 2)
	{
		if (!check_argument(argv[1]))
			print_error(NULL, NULL);
		tab = ft_split(argv[1], ' ');
		stack_a = create_stack(stack_a, 0, tab, tab);
		free_tab(tab);
	}
	else
	{
		if (!check_argument(argv[1]))
			print_error(NULL, NULL);
		stack_a = create_stack(stack_a, 1, argv, NULL);
	}
	sort(stack_len(stack_a), &stack_a, &stack_b);
	free_stack(stack_a);
	exit(0);
}
