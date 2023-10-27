
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

	render = init_render(game);
	render_reset_image(game);
	while (render.ray_index < game->image->width)
	{
		init_ray(&render);
		find_intersections(game, &render.rays[render.ray_index]);
		render_raycast(game, &render, &render.rays[render.ray_index]);
		update_ray(&render);
	}
	// while (render.ray_index < game->image->width)
	// {
	// 	init_ray(&render, &render.rays[render.ray_index]);
	// 	render_raycast(game, &render, &render.rays[render.ray_index]);
	// 	render.ray_index++;
	// 	render.theta += render.delta;
	// 	if (render.theta > 2 * M_PI)
	// 		render.theta -= 2 * M_PI;
	// }
}
