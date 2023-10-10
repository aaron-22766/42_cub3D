
#include "cub3D.h"

void free_game(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map->height)
	{
		free(game->map->map[i]);
		i++;
	}
	free(game->map);
	if (game->no_texture)
		mlx_delete_texture(game->no_texture);
	if (game->so_texture)
		mlx_delete_texture(game->so_texture);
	if (game->we_texture)
		mlx_delete_texture(game->we_texture);
	if (game->ea_texture)
		mlx_delete_texture(game->ea_texture);
}
