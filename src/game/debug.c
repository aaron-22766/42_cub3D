
#include "../../include/cub3D.h"

static void	print_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->height)
		printf("%s\n", map->map[i++]);
}

void	print_game(t_game *game)
{
	printf("\nGAME:\n");
	printf("Resolution: %dx%d\n", HEIGHT, WIDTH);
	printf("Map (%zu,%zu)\n", game->map.height, game->map.width);
	print_map(&game->map);
	printf("North texture: %p\n", game->no_texture);
	printf("South texture: %p\n", game->so_texture);
	printf("West texture: %p\n", game->we_texture);
	printf("East texture: %p\n", game->ea_texture);
	// RGB colors in hexadecimal format
	printf("Floor color: %x\n", game->floor_color);
	printf("Ceiling color: %x\n", game->ceiling_color);
}