
#include "../../include/cub3D.h"

static void	render_reset_image(t_game *game)
{
	mlx_delete_image(game->mlx, game->image);
	game->image = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	render_background(game);
}

void	generate_render(t_game *game)
{
	t_render	render;

	render_reset_image(game);
	init_raycast_frame(game, &render);
	


	mlx_image_to_window(game->mlx, game->image, 0, 0);
}
