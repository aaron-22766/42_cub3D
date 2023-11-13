#include "../../include/cub3D.h"

void	generate_render(t_game *game)
{
	t_render	render;

	render = init_render(game);
	render_background(game);
	while (render.ray_index < game->image->width)
	{
		init_ray(&render);
		find_ray_intersection(game, &render.rays[render.ray_index]);
		render_raycast(game, &render.rays[render.ray_index]);
		update_render(&render);
	}
	// print_render(&render); // DEBUG
	// print_ray(&render.rays[0]); // DEBUG
	// print_ray(&render.rays[game->image->width / 2]); // DEBUG
	// print_ray(&render.rays[game->image->width - 1]); // DEBUG
}
