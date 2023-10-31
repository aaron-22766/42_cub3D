#include "../../include/render.h"

void	generate_render(t_game *game)
{
	t_render	render;

	render = init_render(game);
	render_background(game);
	while (render.ray_index < game->image->width)
	{
		init_ray(&render);
		find_ray_intersection(game, &render.rays[render.ray_index]);
		// render_raycast(game, &render, &render.rays[render.ray_index]);
		update_render(&render);
	}
}
