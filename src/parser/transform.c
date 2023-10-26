#include "../../include/parser.h"

static size_t	remove_excess_allign(t_map *map)
{
	size_t	min;
	size_t	max;
	size_t	i;
	size_t	temp;

	min = -1;
	max = 0;
	i = 0;
	while (i < map->height)
	{
		temp = ft_strspn(map->map[i], ALLIGN);
		if (temp < min)
			min = temp;
		temp = ft_strrspn(map->map[i], ALLIGN);
		if (temp > max)
			max = temp;
		map->map[i++][temp + 1] = '\0';
	}
	i = 0;
	while (i < map->height)
	{
		ft_memmove(map->map[i], &map->map[i][min], max - min + 2);
		i++;
	}
	return (min);
}

static void	init_new_map(t_parser *parser, t_map *map)
{
	size_t	i;

	init_map(map);
	map->height = parser->game->map.max_width;
	map->max_width = parser->game->map.height;
	map->map = ft_calloc(map->height + 1, sizeof(char *));
	if (!map->map)
		parser_fail(parser, CUB_MEMFAIL, "transforming map");
	i = 0;
	while (i < map->height)
	{
		map->map[i] = ft_calloc(map->max_width + 1, sizeof(char));
		if (!map->map[i])
			parser_fail(parser, CUB_MEMFAIL, "transforming map");
		ft_memset(map->map[i], ' ', map->max_width);
		i++;
	}
}

static void	rotate_map(t_map *new_map, t_map *map, t_player *player)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->widths[i])
		{
			new_map->map[map->max_width - 1 - j][i] = map->map[i][j];
			if (ft_strchr(PLAYER_ORIENTATIONS, map->map[i][j]))
			{
				player->pos.x = map->max_width - 1 - j;
				player->pos.y = i;
			}
			j++;
		}
		i++;
	}
}

void	transform_map(t_parser *parser)
{
	t_map	new_map;

	parser->game->player.pos.y -= remove_excess_allign(&parser->game->map);
	calc_widths(&parser->game->map);
	init_new_map(parser, &new_map);
	rotate_map(&new_map, &parser->game->map, &parser->game->player);
	free_map(&parser->game->map);
	parser->game->map = new_map;
	calc_widths(&parser->game->map);
}
