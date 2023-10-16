
#include "../../include/parser.h"

static void	check_line(t_parser *parser)
{
	size_t	i;

	i = 0;
	while (parser->line[i])
		if (!ft_strchr(MAP_CHARACTERS, parser->line[i++]))
			parser_fail(parser, CUB_INVLINE, parser->line);
}

// static char	**ft_realloc_map(char **ptr, size_t count)
// {
// 	char	**new;
// 	size_t	i;

// 	if (count < 2)
// 		return (NULL);
// 	if (!ptr)
// 		return (ft_calloc(count, sizeof(char *)));
// 	new = ft_calloc(count, sizeof(char *));
// 	if (!new)
// 		return (NULL);
// 	i = -1;
// 	while (ptr[++i])
// 		new[i] = ptr[i];
// 	free(ptr);
// 	return (new);
// }

// static char	**ft_get_map(int fd)
// {
// 	size_t	i;
// 	char	**map;

// 	map = 0;
// 	i = 0;
// 	while (1)
// 	{
// 		map = ft_realloc_map(map, i + 2);
// 		if (!map)
// 			return (NULL);
// 		map[i] = get_next_line(fd);
// 		if (map[i] == NULL)
// 			break ;
// 		if (ft_strchr(map[i], '\n'))
// 			ft_strchr(map[i], '\n')[0] = 0;
// 		i++;
// 	}
// 	return (map);
// }

void	map(t_parser *parser)
{
	if (parser->line[0])
	{
		parser->read = false;
		return ;
	}
	check_line(parser);

}
