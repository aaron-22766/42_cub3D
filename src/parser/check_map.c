#include "../../include/parser.h"

static void	map_size(t_parser *parser)
{
	if (parser->game->map.height == 0)
		exit_parser(parser, CUB_NOMAP, NULL);
	if (parser->game->map.height < 3 || parser->game->map.max_width < 3)
		exit_parser(parser, CUB_SMALLMAP, NULL);
}

static double	get_radian(char c)
{
	if (c == 'N')
		return (0.0);
	if (c == 'E')
		return (M_PI_2);
	if (c == 'S')
		return (M_PI);
	if (c == 'W')
		return ((3 * M_PI) / 2);
	return (-1);
}

static void	player_spawn(t_parser *parser)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < parser->game->map.height)
	{
		j = 0;
		while (parser->game->map.map[i][j])
		{
			if (ft_strchr(PLAYER_ORIENTATIONS, parser->game->map.map[i][j]))
			{
				if (parser->game->player.pos.x >= 0.0)
					exit_parser(parser, CUB_DUPPLAYER, NULL);
				parser->game->player.orientation = get_radian(parser->game->map.map[i][j]);
				parser->game->player.pos.x = i;
				parser->game->player.pos.y = j;
			}
			j++;
		}
		i++;
	}
	if (parser->game->player.pos.x < 0.0)
		exit_parser(parser, CUB_MISSPLAYER, NULL);
}

void	check_map(t_parser *parser)
{
	if (calc_widths(&parser->game->map) == false)
		exit_parser(parser, CUB_MEMFAIL, "calculating widths of map");
	map_size(parser);
	player_spawn(parser);
	check_walls(parser);
}
