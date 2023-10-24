
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
	while (render.ray_index < game->image->width)
	{
		init_single_ray(&render, &render.rays[render.ray_index]);
		render_raycast(game, &render, &render.rays[render.ray_index]);
		render.ray_index++;
		render.angle += render.angle_increment;
		if (render.angle > 2 * M_PI)
			render.angle -= 2 * M_PI;
	}
	mlx_image_to_window(game->mlx, game->image, 0, 0);
}
