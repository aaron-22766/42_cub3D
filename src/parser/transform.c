#include "../../include/parser.h"

static void	init_new_map(t_parser *parser, t_map *new)
{
	size_t	i;

	new->map = ft_calloc(new->height + 1, sizeof(char *));
	if (!new->map)
		parser_fail(parser, CUB_MEMFAIL, "transforming map");
	i = 0;
	while (i < new->height)
	{
		new->map[i] = ft_calloc(new->max_width + 1, sizeof(char));
		if (!new->map[i])
			parser_fail(parser, CUB_MEMFAIL, "transforming map");
		i++;
	}
}

static void	get_limits(t_map *map, size_t *min, size_t *max)
{
	size_t	temp;
	size_t	i;

	*min = -1;
	*max = 0;
	i = 0;
	while (i < map->height)
	{
		temp = ft_strspn(map->map[i], ALLIGN);
		if (temp < *min)
			*min = temp;
		temp = ft_strrspn(map->map[i], ALLIGN);
		if (temp > *max)
			*max = temp;
		i++;
	}
}

static void	rotate_cropped(t_map *new, t_map *old, size_t min, size_t max)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (max - i >= min && i <= max)
	{
		j = 0;
		while (j < old->height)
		{
			if (max - i < old->widths[j])
				new->map[i][j] = old->map[j][max - i];
			else
				new->map[i][j] = ' ';
			j++;
		}
		i++;
	}
}

void	transform_map(t_parser *parser)
{
	t_map	new;
	size_t	min;
	size_t	max;

	get_limits(&parser->game->map, &min, &max);
	init_map(&new);
	new.height = max - min + 1;
	new.max_width = parser->game->map.height;
	init_new_map(parser, &new);
	rotate_cropped(&new, &parser->game->map, min, max);
	free_map(&parser->game->map);
	parser->game->map = new;
}
