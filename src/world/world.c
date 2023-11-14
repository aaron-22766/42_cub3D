#include "../../include/cub3D.h"

void	draw_world(t_game *game)
{
	init_world(game);
	draw_background(game);
	while (game->world.ray_index < game->world.image->width)
	{
		init_ray(&game->world);
		find_ray_intersection(game, &game->world.rays[game->world.ray_index]);
		draw_wall_slice(game, &game->world.rays[game->world.ray_index]);
		game->world.theta += game->world.delta;
		if (game->world.theta > 2 * M_PI)
			game->world.theta -= 2 * M_PI;
		game->world.ray_index++;
	}
}
