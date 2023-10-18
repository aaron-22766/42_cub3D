#include "../../include/parser.h"

static void	allocate_vis(t_parser *parser)
{
	size_t	i;

	parser->vis = ft_calloc(parser->map.height + 1, sizeof(char *));
	if (!parser->vis)
		exit_parser(parser, CUB_MEMFAIL, "checking walls");
	i = 0;
	while (i < parser->map.height)
	{
		parser->vis[i] = ft_calloc(parser->map.widths[i], sizeof(char));
		if (!parser->vis[i])
			exit_parser(parser, CUB_MEMFAIL, "checking walls");
		i++;
	}
}

static char	get_pos(t_parser *parser, char **map, int x, int y)
{
	if (x < 0 || x >= (int)parser->map.height
		|| y < 0 || y >= (int)parser->map.widths[x])
		exit_parser(parser, CUB_INVWALLS, NULL);
	return (map[x][y]);
}

static bool	flood(t_parser *parser, int x, int y)
{
	if (get_pos(parser, parser->map.map, x, y) == '1')
		return (false);
	parser->vis[x][y] = true;
	if (!get_pos(parser, parser->vis, x - 1, y) && flood(parser, x - 1, y))
		return (true);
	if (!get_pos(parser, parser->vis, x, y + 1) && flood(parser, x, y + 1))
		return (true);
	if (!get_pos(parser, parser->vis, x + 1, y) && flood(parser, x + 1, y))
		return (true);
	if (!get_pos(parser, parser->vis, x, y - 1) && flood(parser, x, y - 1))
		return (true);
	return (false);
}

void	surrounded_by_walls(t_parser *parser)
{
	allocate_vis(parser);
	flood(parser, parser->player.x, parser->player.y);
	free_arr(parser->vis);
	parser->vis = NULL;
}
