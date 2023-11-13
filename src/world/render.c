#include "../../include/cub3D.h"

void	reset_render(t_game *game)
{
	game->world.ray_index = 0;
	game->world.theta = game->player.orientation + M_PI_2 - (game->player.fov / 2);
	if (game->world.theta > 2 * M_PI)
		game->world.theta -= 2 * M_PI;
	game->world.delta = game->player.fov / (double) game->world.image->width;
	game->world.distance = ((double) TILE_SIZE * (game->world.image->width / 2))
		/ tan(game->player.fov / 2);
	game->world.pov = init_vector(TILE_SIZE * game->player.pos.y,
TILE_SIZE * game->player.pos.x, TILE_SIZE * game->player.pos.z);
}

void	resize_world(t_game *game)
{
	if (game->world.rays)
		free(game->world.rays);
	game->world.rays = (t_ray *) malloc(game->world.image->width * sizeof(t_ray));
	if (!game->world.rays)
		game_fail(game, CUB_MEMFAIL, "creating rays");
}

void	print_render(t_world *world)
{
	printf("\nRENDER:\n");
	printf(" ray_index: %zu\n", world->ray_index);
	printf(" theta: %f\n", world->theta);
	printf(" delta: %f\n", world->delta);
	printf(" distance (from POV to Projection Plane): %lf\n",
		world->distance);
	print_vector(&world->pov, "  pov:", true);
}
