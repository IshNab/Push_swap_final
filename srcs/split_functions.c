#include "push_swap.h"
#include <string.h>

char	**handle_split_error(char *s, char **result, int spaces)
{
	while (spaces > 0)
		free(result[--spaces]);
	free(result);
	free(s);
	return (NULL);
}

char	**add_item_to_result(char **result, char *item, int *spaces)
{
	result = realloc(result, sizeof(char *) * (*spaces + 1));
	if (!result)
		return (NULL);
	result[*spaces] = strdup(item);
	if (!result[*spaces])
		return (NULL);
	(*spaces)++;
	return (result);
}

int	init_split(const char *str, const char *delim, char **s, char ***result)
{
	if (!str || !delim || !*str)
		return (0);
	*s = strdup(str);
	if (!*s)
		return (0);
	*result = NULL;
	return (1);
}