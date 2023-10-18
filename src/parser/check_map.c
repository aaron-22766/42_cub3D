#include "../../include/parser.h"

static void	map_size(t_parser *parser)
{
	if (parser->map.height == 0)
		exit_parser(parser, CUB_NOMAP, NULL);
	if (parser->map.height < 3 || parser->map.max_width < 3)
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
	while (i < parser->map.height)
	{
		j = 0;
		while (parser->map.map[i][j])
		{
			if (ft_strchr(PLAYER_ORIENTATIONS, parser->map.map[i][j]))
			{
				if (parser->player.x >= 0.0)
					exit_parser(parser, CUB_DUPPLAYER, NULL);
				parser->game->orientation = get_radian(parser->map.map[i][j]);
				parser->player.x = i;
				parser->player.y = j;
			}
			j++;
		}
		i++;
	}
	if (parser->player.x < 0.0)
		exit_parser(parser, CUB_MISSPLAYER, NULL);
}

static void	convert_spaces(t_parser *parser)
{
	size_t	i;
	char	*space;

	i = 0;
	while (i < parser->map.height)
	{
		space = ft_strchr(parser->map.map[i], ' ');
		while (space)
		{
			*space = '0';
			space = ft_strchr(space + 1, ' ');
		}
		i++;
	}
}

void	check_map(t_parser *parser)
{
	if (calc_widths(&parser->map) == false)
		exit_parser(parser, CUB_MEMFAIL, "calculating widths of map");
	map_size(parser);
	player_spawn(parser);
	convert_spaces(parser);
	surrounded_by_walls(parser);
}
