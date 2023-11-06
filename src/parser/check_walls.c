#include "../../include/cub3D.h"

static void	create_vis(t_parser *parser)
{
	size_t	i;

	parser->vis = ft_calloc(parser->game->fix_map.height + 1, sizeof(char *));
	if (!parser->vis)
		parser_fail(parser, CUB_MEMFAIL, "checking walls");
	i = 0;
	while (i < parser->game->fix_map.height)
	{
		parser->vis[i] = ft_calloc(parser->game->fix_map.widths[i],
				sizeof(char));
		if (!parser->vis[i])
			parser_fail(parser, CUB_MEMFAIL, "checking walls");
		i++;
	}
}

static bool	flood(t_parser *parser, int x, int y)
{
	if (y < 0 || y >= (int)parser->game->fix_map.height
		|| x < 0 || x >= (int)parser->game->fix_map.widths[y])
		parser_fail(parser, CUB_INVWALLS, "hole in wall");
	if (parser->vis[y][x] || parser->game->fix_map.map[y][x] == WALL)
		return (false);
	if (ft_strchr(ALLIGN, parser->game->fix_map.map[y][x]))
		parser->game->fix_map.map[y][x] = PATH;
	parser->vis[y][x] = true;
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
	while (i < parser->game->fix_map.height)
	{
		if (parser->game->fix_map.map[i] \
			[ft_strspn(parser->game->fix_map.map[i], ALLIGN)] == PATH)
			parser_fail(parser, CUB_INVWALLS, "path outside of left walls");
		if (parser->game->fix_map.map[i] \
			[ft_strrspn(parser->game->fix_map.map[i], ALLIGN)] == PATH)
			parser_fail(parser, CUB_INVWALLS, "path outside of right walls");
		i++;
	}
	if (ft_strchr(parser->game->fix_map.map[0], PATH))
		parser_fail(parser, CUB_INVWALLS, "path outside of top walls");
	if (ft_strchr(parser->game->fix_map.map[parser->game->fix_map.height - 1],
			PATH))
		parser_fail(parser, CUB_INVWALLS, "path outside of bottom walls");
}

void	check_walls(t_parser *parser)
{
	create_vis(parser);
	flood(parser, parser->game->player.pos.x, parser->game->player.pos.y);
	ft_free_2d_array((void **)parser->vis);
	parser->vis = NULL;
	path_outside_walls(parser);
}
