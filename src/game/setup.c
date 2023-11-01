#include "../../include/cub3D.h"

static void	setup_world(t_game *game)
{
	game->image = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->image)
		game_fail(game, CUB_MLXFAIL, "Failed to create image");
	render_background(game);
	generate_render(game);
	if (mlx_image_to_window(game->mlx, game->image, 0, 0) == -1)
		game_fail(game, CUB_MLXFAIL, "Failed to render image");
	mlx_set_instance_depth(game->image->instances, 1);
}

static void	setup_hud(t_game *game)
{
	game->hud.image = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->hud.image)
		game_fail(game, CUB_MLXFAIL, "Failed to create image");
	generate_hud(game);
	if (mlx_image_to_window(game->mlx, game->hud.image, 0, 0) == -1)
		game_fail(game, CUB_MLXFAIL, "Failed to render hud");
	mlx_set_instance_depth(game->hud.image->instances, 2);
}

void	setup_game(t_game *game)
{
	game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D", false);
	if (!game->mlx)
		game_fail(game, CUB_MLXFAIL, "Failed to initialize MLX");
	setup_world(game);
	setup_hud(game);
}
