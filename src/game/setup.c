#include "../../include/cub3D.h"

static void	setup_world(t_game *game) // move to render/world folder
{
	game->image = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->image)
		game_fail(game, CUB_MLXFAIL, "Failed to create image");
	generate_render(game);
	if (mlx_image_to_window(game->mlx, game->image, 0, 0) == -1)
		game_fail(game, CUB_MLXFAIL, "Failed to render image");
	mlx_set_instance_depth(game->image->instances, 1);
}

void	setup_game(t_game *game)
{
	game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D", false);
	if (!game->mlx)
		game_fail(game, CUB_MLXFAIL, "Failed to initialize MLX");
	game->player.pos.x += 0.5;
	game->player.pos.y += 0.5;
	setup_world(game);
	setup_hud(game);
	// print_player(&game->player);
}
