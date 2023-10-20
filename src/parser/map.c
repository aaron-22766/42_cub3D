#include "../../include/parser.h"

static bool	realloc_arr(char ***ptr, size_t count)
{
	char	**new;

	if (count < 2)
		return (false);
	if (!(*ptr))
	{
		*ptr = ft_calloc(count, sizeof(char *));
		return (!!(*ptr));
	}
	new = ft_calloc(count, sizeof(char *));
	if (!new)
		return (false);
	ft_memcpy(new, *ptr, ft_count_2d_array((void **)*ptr) * sizeof(char *));
	free(*ptr);
	*ptr = new;
	return (true);
}

bool	map(t_parser *parser)
{
	if (!is_valid_map_line(parser->line))
		return (false);
	if (!realloc_arr(&parser->map.map, parser->map.height + 2))
		exit_parser(parser, CUB_MEMFAIL, "reading map");
	parser->map.map[parser->map.height] = ft_strdup(parser->line);
	if (!parser->map.map[parser->map.height])
		exit_parser(parser, CUB_MEMFAIL, "reading map");
	parser->map.height++;
	return (true);
}
