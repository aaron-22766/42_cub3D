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

static bool	dup_map(t_map *dst, t_map *src)
{
	size_t	i;

	dst->height = src->height;
	dst->max_width = src->max_width;
	dst->map = ft_calloc(dst->height + 1, sizeof(char *));
	if (!dst->map)
		return (false);
	i = 0;
	while (i < dst->height)
	{
		dst->map[i] = ft_strdup(src->map[i]);
		if (!dst->map[i])
			return (false);
		i++;
	}
	return (true);
}

static void	setup_flex_map(t_parser *parser)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < parser->game->flex_map.height)
	{
		x = 0;
		while (x < parser->game->flex_map.max_width)
		{
			if (parser->game->flex_map.map[y][x] == DOOR)
				parser->game->flex_map.map[y][x] = WALL;
			x++;
		}
		y++;
	}
	parser->game->flex_map.map[(int)(parser->game->player.pos.y)]\
		[(int)(parser->game->player.pos.x)] = PATH;
}

void	transform_map(t_parser *parser)
{
	parser->game->player.pos.x -= remove_excess_allign(&parser->game->fix_map);
	calc_widths(&parser->game->fix_map);
	if (dup_map(&parser->game->flex_map, &parser->game->fix_map) == false)
		parser_fail(parser, CUB_MEMFAIL, "duplicating map");
	setup_flex_map(parser);
	print_map(&parser->game->flex_map);
}
