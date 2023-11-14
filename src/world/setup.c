#include "../../include/cub3D.h"

void	resize_world(t_game *game)
{
	if (game->world.rays)
		free(game->world.rays);
	game->world.rays = (t_ray *) malloc(sizeof(t_ray)
			* game->world.image->width);
	if (!game->world.rays)
		game_fail(game, CUB_MEMFAIL, "creating rays");
}

void	setup_world(t_game *game)
{
	game->world.image = mlx_new_image(game->mlx,
			game->mlx->width, game->mlx->height);
	if (!game->world.image)
		game_fail(game, CUB_MLXFAIL, "Failed to create image");
	resize_world(game);
	draw_world(game);
	if (mlx_image_to_window(game->mlx, game->world.image, 0, 0) == -1)
		game_fail(game, CUB_MLXFAIL, "Failed to render image");
	mlx_set_instance_depth(game->world.image->instances, 1);
}
