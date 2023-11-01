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
	size_t	i;
	size_t	len;

	if (!map->widths)
		map->widths = malloc(map->height * sizeof(size_t));
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
	size_t	i;

	printf("Map (height: %zu, max_width: %zu)\n", map->height, map->max_width);
	i = 0;
	while (i < map->height)
	{
		printf("%*zu|%-*s", (int)log10(map->height) + 1, i,
			(int)map->max_width, map->map[i]);
		if (map->widths)
			printf("|w%zu", map->widths[i]);
		printf("\n");
		i++;
	}
}
