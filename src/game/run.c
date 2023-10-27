#include "../../include/cub3D.h"

void	run_game(t_game *game)
{
	game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D", false);
	if (!game->mlx)
		ft_perror(CUB_MLXFAIL, "Failed to initialize MLX");
	game->image = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->image)
		ft_perror(CUB_MLXFAIL, "Failed to create image");
	render_background(game);
	if (mlx_image_to_window(game->mlx, game->image, 0, 0))
		ft_perror(CUB_MLXFAIL, "Failed to create window");
	generate_render(game);
	mlx_loop_hook(game->mlx, hook, game);
	mlx_loop(game->mlx);
}
