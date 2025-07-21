#include "push_swap.h"
#include <string.h>

int	check_int_valid(const char *str)
{
	long	num;
	int		i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	num = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		num = num * 10 + (str[i] - '0');
		if ((str[0] != '-' && num > INT_MAX)
			|| (str[0] == '-' && num > ((long)INT_MAX + 1)))
			return (0);
		i++;
	}
	return (1);
}

void	free_split_result(char **result, int count)
{
	int	i;

	if (!result)
		return ;
	i = 0;
	while (i < count)
		free(result[i++]);
	free(result);
}

char	**split_string(const char *str, const char *delim, int *count)
{
	char	*s;
	char	*item;
	char	**result;
	int		spaces;

	if (!count || !init_split(str, delim, &s, &result))
		return (NULL);
	spaces = 0;
	item = strtok(s, delim);
	while (item)
	{
		while (*item && *item == ' ')
			item++;
		if (!*item)
			break ;
		result = add_item_to_result(result, item, &spaces);
		if (!result)
			return (handle_split_error(s, result, spaces));
		item = strtok(NULL, delim);
	}
	*count = spaces;
	free(s);
	return (result);
}