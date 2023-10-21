#include "../../include/cub3D.h"

void	free_game(t_game *game)
{
	free_map(&game->map);
	// To-do: free image, mlx, window, ...
	// terminate game, then 
	if (game->no_texture)
		mlx_delete_texture(game->no_texture);
	if (game->so_texture)
		mlx_delete_texture(game->so_texture);
	if (game->we_texture)
		mlx_delete_texture(game->we_texture);
	if (game->ea_texture)
		mlx_delete_texture(game->ea_texture);
}
