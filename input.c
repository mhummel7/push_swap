/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:53:17 by mhummel           #+#    #+#             */
/*   Updated: 2024/05/17 13:06:51 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct				s_node
{
	int				data;
	struct s_node	*next;
};

struct s_node	*creates_node(int data)
{
	struct s_node	*news_node;

	news_node = (struct s_node *)malloc(sizeof(struct s_node));
	news_node->data = data;
	news_node->next = NULL;
	return (news_node);
}

int	is_duplicate(struct s_node *head, int num)
{
	struct s_node	*current;

	current = head;
	while (current != NULL)
	{
		if (current->data == num)
		{
			return (1);
		}
		current = current->next;
	}
	return (0);
}

void	appends_node(struct s_node **headRef, int data)
{
	struct s_node	*news_node;
	struct s_node	*current;

	news_node = creates_node(data);
	if (*headRef == NULL)
	{
		*headRef = news_node;
	}
	else
	{
		current = *headRef;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = news_node;
	}
}

void	free_list(struct s_node *head)
{
	struct s_node	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

int	process_string(struct s_node **headRef, char *str)
{
	char	*token;
	char	*endptr;
	long	num;

	token = strtok(str, " ");
	while (token != NULL)
	{
		num = strtol(token, &endptr, 10);
		if (*endptr != '\0')
			return (printf("Unvalid Input '%s'. Please enter another number.\n",
					token), 1);
		else if (num < INT_MIN || num > INT_MAX)
			return (printf("Unvalid Input '%s'. Number is not in 'int'.\n",
					token), 1);
		else if (is_duplicate(*headRef, (int)num))
			return (printf("Duplicate '%ld'. Please enter another number.\n",
					num), 1);
		else
			appends_node(headRef, (int)num);
		token = strtok(NULL, " ");
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	struct s_node	*head;
	char			*endptr;
	long			num;
	int				i;
	char			input[256];
	struct s_node	*current;

	head = NULL;
	i = 1;
	if (argc < 2)
		return (printf("Usage: %s num1 num2 ... or %s \"num1 num2 ...\"\n",
				argv[0], argv[0]), 1);
	while (i < argc)
	{
		if (strchr(argv[i], ' ') != NULL)
		{
			strncpy(input, argv[i], sizeof(input));
			input[sizeof(input) - 1] = '\0';
			if (process_string(&head, input) != 0)
				return (free_list(head), 1);
		}
		else
		{
			num = strtol(argv[i], &endptr, 10);
			if (*endptr != '\0')
			{
				printf("Unvalid Input '%s'. Please enter another number.\n",
					argv[i]);
				return (free_list(head), 1);
			}
			else if (num < INT_MIN || num > INT_MAX)
			{
				printf("Unvalid Input '%s'. Number is not in 'int'.\n",
					argv[i]);
				return (free_list(head), 1);
			}
			else if (is_duplicate(head, (int)num))
			{
				printf("Duplicate '%ld'. Please enter another number.\n", num);
				return (free_list(head), 1);
			}
			else
				appends_node(&head, (int)num);
		}
		i++;
	}
	printf("Input:\n");
	current = head;
	while (current != NULL)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
	return (free_list(head), 0);
}
