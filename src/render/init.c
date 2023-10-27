#include "../../include/render.h"

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
		find_ray_intersection(game, &render.rays[render.ray_index]);
		// render_raycast(game, &render, &render.rays[render.ray_index]);
		update_render(&render);
	}
}
