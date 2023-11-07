#include "../../include/cub3D.h"

void	init_map(t_map *map)
{
	map->map = NULL;
	map->height = 0;
	map->max_width = 0;
	map->widths = NULL;
}

void	free_map(t_map *map)
{
	ft_free_2d_array((void **)map->map);
	free(map->widths);
}

bool	calc_widths(t_map *map)
{
	uint32_t	i;
	uint32_t	len;

	if (!map->widths)
		map->widths = malloc(map->height * sizeof(uint32_t));
	if (!map->widths)
		return (false);
	map->max_width = 0;
	i = 0;
	while (i < map->height)
	{
		len = ft_strlen(map->map[i]);
		if (len > map->max_width)
			map->max_width = len;
		map->widths[i] = len;
		i++;
	}
	return (true);
}

void	print_map(t_map *map)
{
	uint32_t	i;

	printf("Map (height: %u, max_width: %u)\n", map->height, map->max_width);
	i = 0;
	while (i < map->height)
	{
		printf("%*u|%-*s", (int)log10(map->height) + 1, i,
			(int)map->max_width, map->map[i]);
		if (map->widths)
			printf("|w%u", map->widths[i]);
		printf("\n");
		i++;
	}
}
