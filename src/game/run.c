
#include "../../include/cub3D.h"

void	run_game(t_game *game)
{
	a = copy_vector(b);
	printf("a = copy_vector(b)\n");
	print_vector(&a, "a", false);
	transform_map(game);
	game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D", false);
	if (!game->mlx)
		ft_perror(CUB_MLXFAIL, "Failed to initialize MLX");
	game->image = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->image)
		ft_perror(CUB_MLXFAIL, "Failed to create image");
	render_background(game);
	if (mlx_image_to_window(game->mlx, game->image, 0, 0))
		ft_perror(CUB_MLXFAIL, "Failed to create window");
	game->player.pos.x += 0.5;
	game->player.pos.y += 0.5;
	generate_render(game);
	mlx_loop_hook(game->mlx, hook, game);
	// mlx_mouse_hook(game->mlx, mouse_hook, game);  // To-do: mouse_hook (bonus)
	mlx_loop(game->mlx);
}
