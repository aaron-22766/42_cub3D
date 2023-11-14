#include "../../include/cub3D.h"

void	init_world(t_game *game)
{
	game->world.ray_index = 0;
	game->world.fov_2 = game->player.fov / 2;
	game->world.theta = game->player.orientation + M_PI_2 - game->world.fov_2;
	if (game->world.theta > 2 * M_PI)
		game->world.theta -= 2 * M_PI;
	game->world.delta = game->player.fov / (double) game->world.image->width;
	game->world.distance = ((double) TILE_SIZE * (game->world.image->width / 2))
		/ tan(game->world.fov_2);
	game->world.pov = init_vector(TILE_SIZE * game->player.pos.y,
			TILE_SIZE * game->player.pos.x, TILE_SIZE * game->player.pos.z);
}

void	print_world(t_world *world)
{
	printf("\nWorld:\n");
	printf(" ray_index: %zu\n", world->ray_index);
	printf(" theta: %f\n", world->theta);
	printf(" delta: %f\n", world->delta);
	printf(" distance (to projection plane center): %lf\n",
		world->distance);
	print_vector(&world->pov, "  pov:", true);
}
