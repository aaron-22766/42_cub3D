#include "../../include/cub3D.h"

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D", false);
	if (!game->mlx)
		game_fail(game, CUB_MLXFAIL, "Failed to initialize MLX");
	game->image = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->image)
		game_fail(game, CUB_MLXFAIL, "Failed to create image");
	game->foreground = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->foreground)
		game_fail(game, CUB_MLXFAIL, "Failed to create image");
	render_background(game);
	generate_render(game);
	if (mlx_image_to_window(game->mlx, game->image, 0, 0) == -1)
		game_fail(game, CUB_MLXFAIL, "Failed to render image");
	mlx_set_instance_depth(game->image->instances, 1);
	generate_foreground(game);
	if (mlx_image_to_window(game->mlx, game->foreground, 0, 0) == -1)
		game_fail(game, CUB_MLXFAIL, "Failed to render foreground");
	mlx_set_instance_depth(game->foreground->instances, 2);
}
