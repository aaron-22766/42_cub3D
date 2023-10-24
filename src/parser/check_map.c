#include "../../include/parser.h"

static void	map_size(t_parser *parser)
{
	if (parser->game->map.height == 0)
		exit_parser(parser, CUB_NOMAP, NULL);
	if (parser->game->map.height < 3 || parser->game->map.max_width < 3)
		exit_parser(parser, CUB_SMALLMAP, NULL);
}

// Changed: East is now 0 degrees, North is 90 degrees, West is 180 degrees, South is 270 degrees.
/**
 * @brief Get the radian object
 * Changes for consistency & ease of use:
 * 	- East is now 0 degrees
 * 	- North is 90 degrees
 *	- West is 180 degrees
 *	- South is 270 degrees
 * As in the unit circle.
 * 
 * You can delete this comment after you've read it.
 * @param c 
 * @return double 
 */

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
				parser->game->player.orientation
					= get_radian(parser->game->map.map[i][j]);
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
