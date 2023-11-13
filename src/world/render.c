#include "../../include/cub3D.h"

t_world	init_render(t_game *game)
{
	t_world	world;

	world.rays = NULL;
	world.rays = (t_ray *) malloc(game->mlx->width * sizeof(t_ray));
	if (!world.rays)
	game_fail(game, CUB_MEMFAIL, "creating rays");
	world.ray_index = 0;
	world.theta = game->player.orientation + M_PI_2 - (game->player.fov / 2);
	if (world.theta > 2 * M_PI)
		world.theta -= 2 * M_PI;
	world.delta = game->player.fov / (double) game->image->width;
	world.distance = ((double) TILE_SIZE * (game->image->width / 2))
		/ tan(game->player.fov / 2);
	world.pov = init_vector(TILE_SIZE * game->player.pos.y,
TILE_SIZE * game->player.pos.x, TILE_SIZE * game->player.pos.z);
	return (world);
}

void	update_render(t_world *world)
{
	world->ray_index++;
	world->theta += world->delta;
	if (world->theta > 2 * M_PI)
		world->theta -= 2 * M_PI;
	// Maybe also update world->distance?
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
