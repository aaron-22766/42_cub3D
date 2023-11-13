#include "../../include/cub3D.h"

void	setup_world(t_game *game)
{
	game->image = mlx_new_image(game->mlx, game->mlx->width, game->mlx->height);
	if (!game->image)
		game_fail(game, CUB_MLXFAIL, "Failed to create image");
    resize_world(game);
	generate_render(game);
	if (mlx_image_to_window(game->mlx, game->image, 0, 0) == -1)
		game_fail(game, CUB_MLXFAIL, "Failed to render image");
	mlx_set_instance_depth(game->image->instances, 1);
}
