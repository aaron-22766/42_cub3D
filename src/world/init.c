#include "../../include/cub3D.h"

void	generate_render(t_game *game)
{
	reset_render(game);
	render_background(game);
	while (game->world.ray_index < game->world.image->width)
	{
		init_ray(&game->world);
		find_ray_intersection(game, &game->world.rays[game->world.ray_index]);
		render_raycast(game, &game->world.rays[game->world.ray_index]);
		game->world.ray_index++;
		game->world.theta += game->world.delta;
		if (game->world.theta > 2 * M_PI)
			game->world.theta -= 2 * M_PI;
	}
}
