
#include "../../include/cub3D.h"

void	print_rotated_map(t_map *map)
{
	size_t	i;

	printf("Map (height: %zu, max_width: %zu)\n", map->height, map->max_width);
	i = map->height;
	while (i > 0)
	{
		i--;
		printf("%*zu|%-*s|w%zu\n", (int)log10(map->height) + 1, i,
			(int)map->max_width, map->map[i], map->max_width);
	}
	printf("%*s_", (int)log10(map->height) + 1, "");
	i = 0;
	while (i < map->max_width)
	{
		printf("%c", (char) ('0' + i % 10));
		i++;
	}
	printf("_\n");
}
