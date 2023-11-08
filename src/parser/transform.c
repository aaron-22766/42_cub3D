#include "../../include/cub3D.h"

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
	dst->has_door = src->has_door;
	dst->map = ft_calloc(dst->height + 1, sizeof(char *));
	if (!dst->map)
		return (false);
	i = 0;
	while (i < dst->height)
	{
		dst->map[i] = ft_calloc(dst->max_width + 1, sizeof(char));
		if (!dst->map[i])
			return (false);
		ft_memset(dst->map[i], (ALLIGN)[0], dst->max_width);
		ft_strncpy(dst->map[i], src->map[i], src->widths[i]);
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
			if (parser->game->flex_map.map[y][x] == MAP_DOOR)
			{
				parser->game->flex_map.map[y][x] = MAP_WALL;
				parser->game->fix_map.has_door = true;
				parser->game->flex_map.has_door = true;
			}
			x++;
		}
		y++;
	}
	parser->game->flex_map.map[(uint32_t)(parser->game->player.pos.y)] \
		[(uint32_t)(parser->game->player.pos.x)] = MAP_PATH;
}

void	transform_map(t_parser *parser)
{
	t_map	temp;

	parser->game->player.pos.x -= remove_excess_allign(&parser->game->fix_map);
	init_map(&temp);
	if (dup_map(&temp, &parser->game->fix_map) == false)
		parser_fail(parser, CUB_MEMFAIL, "duplicating map");
	free_map(&parser->game->fix_map);
	parser->game->fix_map = temp;
	calc_widths(&parser->game->fix_map);
	if (dup_map(&parser->game->flex_map, &parser->game->fix_map) == false)
		parser_fail(parser, CUB_MEMFAIL, "duplicating map");
	setup_flex_map(parser);
}
