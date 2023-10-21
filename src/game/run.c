
#include "../../include/cub3D.h"

void	run_game(t_game *game)
{
	printf("Running game\n");
	print_game(game);				//DEBUG
	// mlx_delete_image(game->mlx, game->image);
	// game->image = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	// render_background(game);
	// mlx_image_to_window(game->mlx, game->image, 0, 0);
	printf("mlx_loop\n");		//DEBUG
	generate_render(game);
	// mlx_loop_hook(game->mlx, (void (*)(void*))key_hook, game);
	mlx_key_hook(game->mlx, key_hook, game);
	mlx_loop(game->mlx);

	/*
	TODO:	-	Loop through all mouse events
			-	For each mouse event:
				-	Handle mouse event
				-	Before Generate New render
	*/
}
