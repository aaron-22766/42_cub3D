
#include "../../include/cub3D.h"

void	run_game(t_game *game)
{
	printf("\nMAP Before:\n");	// DEBUG
	print_map(&game->map);		// DEBUG
	transform_map(game);
	printf("\nMAP After:\n");	// DEBUG
	print_map(&game->map);		// DEBUG


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
	// print_game(game);
	generate_render(game);
	mlx_key_hook(game->mlx, key_hook, game);
	mlx_loop(game->mlx);
	/*
	TODO:	-	Loop through all mouse events
			-	For each mouse event:
				-	Handle mouse event
				-	Before Generate New render
	*/
}
