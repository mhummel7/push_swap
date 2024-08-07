/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 22:38:28 by mhummel           #+#    #+#             */
/*   Updated: 2024/08/08 01:16:10 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	not_number(char **tab, int i)
{
	int	j;

	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (!ft_isdigit(tab[i][j]) && tab[i][j] != '-' && tab[i][j] != '+')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_atoi_push_swap(char *str, t_stack *stack, char **tab)
{
	long long	nb;
	long		sign;
	int			i;

	nb = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] == 0)
		print_error(stack, tab);
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] == '0')
		i++;
	while (ft_isdigit(str[i]))
	{
		nb = nb * 10 + str[i++] - '0';
		if (nb * sign > INT_MAX || nb * sign < INT_MIN)
			print_error(stack, tab);
	}
	if ((int)ft_strlen(str) != i || str[i] == '-' || str[i] == '+')
		print_error(stack, tab);
	return ((int)(nb * sign));
}

int	tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
