#include "../../include/parser.h"

static void	create_vis(t_parser *parser)
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

static bool	flood(t_parser *parser, int x, int y)
{
	if (x < 0 || x >= (int)parser->map.height
		|| y < 0 || y >= (int)parser->map.widths[x])
		exit_parser(parser, CUB_INVWALLS, "hole in wall");
	if (parser->vis[x][y] || parser->map.map[x][y] == WALL)
		return (false);
	parser->vis[x][y] = true;
	if (flood(parser, x - 1, y))
		return (true);
	if (flood(parser, x, y + 1))
		return (true);
	if (flood(parser, x + 1, y))
		return (true);
	if (flood(parser, x, y - 1))
		return (true);
	return (false);
}

static bool	has_path_outside_walls(char *line)
{
	return (line[ft_strspn(line, ALLIGN)] == PATH
		|| line[ft_strrspn(line, ALLIGN)] == PATH);
}

static void	path_outside_walls(t_parser *parser)
{
	size_t	i;

	i = 0;
	if (ft_strchr(parser->map.map[i++], PATH))
		exit_parser(parser, CUB_INVWALLS, "path outside of walls");
	while (i < parser->map.height - 1)
		if (has_path_outside_walls(parser->map.map[i++]))
			exit_parser(parser, CUB_INVWALLS, "path outside of walls");
	if (ft_strchr(parser->map.map[i - 1], PATH))
		exit_parser(parser, CUB_INVWALLS, "path outside of walls");
}

void	check_walls(t_parser *parser)
{
	create_vis(parser);
	flood(parser, parser->player.x, parser->player.y);
	ft_free_2d_array((void **)parser->vis);
	parser->vis = NULL;
	path_outside_walls(parser);
}
