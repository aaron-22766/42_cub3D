
#include "cub3D.h"

static void free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->map[i]);
		i++;
	}
	free(map);
}

void free_game(t_game *game)
{
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game->map)
		free_map(game->map);
	if (game->no_texture)
		mlx_delete_texture(game->no_texture);
	if (game->so_texture)
		mlx_delete_texture(game->so_texture);
	if (game->we_texture)
		mlx_delete_texture(game->we_texture);
	if (game->ea_texture)
		mlx_delete_texture(game->ea_texture);
}
