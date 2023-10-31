#include "../../include/parser.h"

static void	map_size(t_parser *parser)
{
	if (parser->game->fix_map.height == 0)
		parser_fail(parser, CUB_NOMAP, NULL);
	if (parser->game->fix_map.height < 3 || parser->game->fix_map.max_width < 3)
		parser_fail(parser, CUB_SMALLMAP, NULL);
}

static double	get_radian(char c)
{
	if (c == 'N')
		return (M_PI_2);
	if (c == 'E')
		return (0.0);
	if (c == 'S')
		return ((3 * M_PI) / 2);
	if (c == 'W')
		return (M_PI);
	return (-1);
}

static void	player_spawn(t_parser *parser)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < parser->game->fix_map.height)
	{
		x = 0;
		while (parser->game->fix_map.map[y][x])
		{
			if (ft_strchr(PLAYER_ORIENTATIONS, parser->game->fix_map.map[y][x]))
			{
				if (parser->game->player.pos.x >= 0.0)
					parser_fail(parser, CUB_DUPPLAYER, NULL);
				parser->game->player.orientation
					= get_radian(parser->game->fix_map.map[y][x]);
				parser->game->player.pos.x = x;
				parser->game->player.pos.y = y;
			}
			x++;
		}
		y++;
	}
	if (parser->game->player.pos.x < 0.0)
		parser_fail(parser, CUB_MISSPLAYER, NULL);
}

void	check_map(t_parser *parser)
{
	if (calc_widths(&parser->game->fix_map) == false)
		parser_fail(parser, CUB_MEMFAIL, "calculating widths of map");
	map_size(parser);
	player_spawn(parser);
	check_walls(parser);
}
