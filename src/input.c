#include "../include/push_swap.h"

int handle_one_arg(char *argv)
{
	int i;

	i = 0;
	argv = ft_split(argv[1], ' ');
	if (!argv)
	{
		ft_printf("Error\n");
		return (0);
	}
}

int handle_multiple_args(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		i++;
	}
	return (0);
}
