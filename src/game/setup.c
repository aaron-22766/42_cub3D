#include "../../include/cub3D.h"

void	setup_world(t_game *game) // move to render/world folder
{
	game->image = mlx_new_image(game->mlx, game->mlx->width, game->mlx->height);
	if (!game->image)
		game_fail(game, CUB_MLXFAIL, "Failed to create image");
	generate_render(game);
	if (mlx_image_to_window(game->mlx, game->image, 0, 0) == -1)
		game_fail(game, CUB_MLXFAIL, "Failed to render image");
	mlx_set_instance_depth(game->image->instances, 1);
}

void	setup_pause_screen(t_game *game)
{
	game->pause_screen = mlx_new_image(game->mlx, game->mlx->width,
			game->mlx->height);
	if (!game->pause_screen)
		game_fail(game, CUB_MLXFAIL, "Failed to create image");
	render_pause_screen(game);
	if (mlx_image_to_window(game->mlx, game->pause_screen, 0, 0) == -1)
		game_fail(game, CUB_MLXFAIL, "Failed to render image");
	mlx_set_instance_depth(game->pause_screen->instances, 3);
}

void	setup_game(t_game *game)
{
	game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D", true);
	if (!game->mlx)
		game_fail(game, CUB_MLXFAIL, "Failed to initialize MLX");
	game->too_small_image = mlx_put_string(game->mlx, "Window too small", 0, 0);
	if (!game->too_small_image)
		game_fail(game, CUB_MLXFAIL, "Failed to create image");
	mlx_set_instance_depth(game->too_small_image->instances, 0);
	game->player.pos.x += 0.5;
	game->player.pos.y += 0.5;
	setup_world(game);
	setup_hud(game);
	setup_pause_screen(game);
}
