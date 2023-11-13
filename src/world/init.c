#include "../../include/cub3D.h"

void	generate_render(t_game *game)
{
	t_world	world;

	world = init_render(game);
	render_background(game);
	while (world.ray_index < game->image->width)
	{
		init_ray(&world);
		find_ray_intersection(game, &world.rays[world.ray_index]);
		render_raycast(game, &world.rays[world.ray_index]);
		update_render(&world);
	}
}
