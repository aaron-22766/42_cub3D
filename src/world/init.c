#include "../../include/cub3D.h"

// void	generate_render(t_game *game)
// {
// 	t_world	world;

// 	world =	init_render(game);
// 	render_background(game);
// 	while (world.ray_index < game->image->width)
// 	{
// 		init_ray(&world);
// 		find_ray_intersection(game, &world.rays[world.ray_index]);
// 		render_raycast(game, &world.rays[world.ray_index]);
// 		update_render(&world);
// 	}
// }

void	generate_render(t_game *game)
{
	reset_render(game);
	render_background(game);
	while (game->world.ray_index < game->image->width)
	{
		init_ray(&game->world);
		find_ray_intersection(game, &game->world.rays[game->world.ray_index]);
		render_raycast(game, &game->world.rays[game->world.ray_index]);
		update_render(&game->world);
	}
}
