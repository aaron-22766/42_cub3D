#include "../../include/cub3D.h"

static void	setup_world(t_game *game) // move to render/world folder
{
	game->image = mlx_new_image(game->mlx, game->mlx->width, game->mlx->height);
	if (!game->image)
		game_fail(game, CUB_MLXFAIL, "Failed to create image");
	generate_render(game);
	if (mlx_image_to_window(game->mlx, game->image, 0, 0) == -1)
		game_fail(game, CUB_MLXFAIL, "Failed to render image");
	mlx_set_instance_depth(game->image->instances, 1);
}

void	reset_game(t_game *game)
{
	delete_image(game->mlx, game->image);
	delete_image(game->mlx, game->hud.image);
	delete_image(game->mlx, game->pause_screen);
	delete_image(game->mlx, game->pause_text);
	game->pause_screen = mlx_new_image(game->mlx, game->mlx->width,
			game->mlx->height);
	if (!game->pause_screen)
		game_fail(game, CUB_MLXFAIL, "Failed to create image");
	if (mlx_image_to_window(game->mlx, game->pause_screen, 0, 0) == -1)
		game_fail(game, CUB_MLXFAIL, "Failed to render image");
	mlx_set_instance_depth(game->pause_screen->instances, 3);
	setup_world(game);
	setup_hud(game);
	render_pause_screen(game);
}

void	setup_game(t_game *game)
{
	game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D", true);
	if (!game->mlx)
		game_fail(game, CUB_MLXFAIL, "Failed to initialize MLX");
	game->player.pos.x += 0.5;
	game->player.pos.y += 0.5;
	reset_game(game);
}
