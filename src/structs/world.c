#include "../../include/cub3D.h"

void	init_world(t_game *game)
{
	game->world.rays = NULL;
	game->world.image = NULL;
}

void	free_world(t_world *world)
{
	free(world->rays);
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
