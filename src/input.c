/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:32:13 by mhummel           #+#    #+#             */
/*   Updated: 2024/08/01 11:54:23 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	validate_arg(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	if (!argv[i])
		return (1);
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_overflow(char *argv)
{
	long	nbr;

	nbr = ft_atol(argv);
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (1);
	return (0);
}

int	handle_one_arg(char *argv)
{
	int		i;
	char	**split_args;

	i = 0;
	split_args = ft_split(argv, ' ');
	if (!split_args)
	{
		ft_printf("Error\n");
		return (1);
	}
	while (split_args[i])
	{
		if (validate_arg(split_args[i]) || check_overflow(split_args[i]))
		{
			ft_printf("Error\n");
			free_split(split_args);
			return (1);
		}
		i++;
	}
	free_split(split_args);
	return (0);
}

int	handle_multiple_args(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (validate_arg(argv[1]) || check_overflow(argv[i]))
		{
			ft_printf("Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}
