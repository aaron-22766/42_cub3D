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
	if (ft_strchr(ALLIGN, parser->map.map[x][y]))
		parser->map.map[x][y] = PATH;
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

static void	path_outside_walls(t_parser *parser)
{
	size_t	i;

	i = 0;
	while (i < parser->map.height)
	{
		if (parser->map.map[i][ft_strspn(parser->map.map[i], ALLIGN)] == PATH)
			exit_parser(parser, CUB_INVWALLS, "path outside of left walls");
		if (parser->map.map[i][ft_strrspn(parser->map.map[i], ALLIGN)] == PATH)
			exit_parser(parser, CUB_INVWALLS, "path outside of right walls");
		i++;
	}
	if (ft_strchr(parser->map.map[0], PATH))
		exit_parser(parser, CUB_INVWALLS, "path outside of top walls");
	if (ft_strchr(parser->map.map[parser->map.height - 1], PATH))
		exit_parser(parser, CUB_INVWALLS, "path outside of bottom walls");
}

void	check_walls(t_parser *parser)
{
	create_vis(parser);
	flood(parser, parser->player.x, parser->player.y);
	ft_free_2d_array((void **)parser->vis);
	parser->vis = NULL;
	path_outside_walls(parser);
}
