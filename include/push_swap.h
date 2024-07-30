#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>

# include "../libft/libft/libft.h"
# include "../libft/get_next_line/get_next_line.h"
# include "../libft/ft_printf/ft_printf.h"

typedef struct s_stack_node
{
	void					*nbr;
	int						index;
	int						push_cost;
	bool					above_median;
	bool					cheapest;
	struct s_stack_node		*target_node;
	struct s_stack_node		*next;
	struct s_stack_node		*prev;
}	t_stack_node;

// ------<>------ Error handling------<>------

// ------<>------  Stack initation ------<>------

// ------<>------ Nodes initation ------<>------

// ------<>------ Stack utils ------<>------

// ------<>------ Commands ------<>------

// ------<>------ Algorithms ------<>------

#endif