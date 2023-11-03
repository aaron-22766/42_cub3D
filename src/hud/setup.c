#include "../../include/cub3D.h"

void	setup_hud(t_game *game)
{
	game->hud.image = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->hud.image)
		game_fail(game, CUB_MLXFAIL, "Failed to create image");
	draw_minimap(game);
	animate_torch(game);
	if (mlx_image_to_window(game->mlx, game->hud.image, 0, 0) == -1)
		game_fail(game, CUB_MLXFAIL, "Failed to render hud");
	mlx_set_instance_depth(game->hud.image->instances, 2);
}
