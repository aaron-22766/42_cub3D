#include "../../include/cub3D.h"

void	render_world(t_game *game)
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
	print_ray(&game->world.rays[game->world.image->width / 2]); // debug
}
