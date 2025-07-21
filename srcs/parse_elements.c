#include "push_swap.h"

static int	filter_numbers(char **numbers, int count,
		t_stack *stack_a, int *has_nbrs)
{
	int	j;

	j = 0;
	while (j < count)
	{
		if (!check_int_valid(numbers[j])
			|| is_duplicate(stack_a, atol(numbers[j])))
		{
			free_split_result(numbers, count);
			return (0);
		}
		add_node_bottom(stack_a, create_node(atol(numbers[j])));
		*has_nbrs = 1;
		j++;
	}
	return (1);
}

int	parse_and_fill_stack(int argc, char **argv, t_stack *stack_a)
{
	int		i;
	int		count;
	char	**numbers;
	int		has_nbrs;

	i = 1;
	has_nbrs = 0;
	while (i < argc)
	{
		if (!argv[i][0])
			return (0);
		numbers = split_string(argv[i], " ", &count);
		if (!numbers || count == 0)
			return (0);
		if (!filter_numbers(numbers, count, stack_a, &has_nbrs))
			return (0);
		free_split_result(numbers, count);
		i++;
	}
	return (has_nbrs);
}