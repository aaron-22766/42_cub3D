#include "../../include/cub3D.h"

t_render	init_render(t_game *game)
{
	t_render	render;

	render.rays = NULL;
	render.rays = (t_ray *) malloc(game->mlx->width * sizeof(t_ray));
	if (!render.rays)
	game_fail(game, CUB_MEMFAIL, "creating rays");
	render.ray_index = 0;
	render.theta = game->player.orientation + M_PI_2 - (game->player.fov / 2);
	if (render.theta > 2 * M_PI)
		render.theta -= 2 * M_PI;
	render.delta = game->player.fov / (double) game->image->width;
	render.distance = ((double) TILE_SIZE * (game->image->width / 2))
		/ tan(game->player.fov / 2);
	render.pov = init_vector(TILE_SIZE * game->player.pos.y,
TILE_SIZE * game->player.pos.x, TILE_SIZE * game->player.pos.z);
	return (render);
}

void	update_render(t_render *render)
{
	render->ray_index++;
	render->theta += render->delta;
	if (render->theta > 2 * M_PI)
		render->theta -= 2 * M_PI;
	// Maybe also update render->distance?
}

void	print_render(t_render *render)
{
	printf("\nRENDER:\n");
	printf(" ray_index: %zu\n", render->ray_index);
	printf(" theta: %f\n", render->theta);
	printf(" delta: %f\n", render->delta);
	printf(" distance (from POV to Projection Plane): %lf\n",
		render->distance);
	print_vector(&render->pov, "  pov:", true);
}
