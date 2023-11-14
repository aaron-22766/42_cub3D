#include "../../include/cub3D.h"

static double	find_distance_to_projection_plane(t_game *game)
{
	double	iw_half;

	iw_half = (double) game->world.image->width / 2.0;
	return (iw_half / tan(game->world.fov_2));
}

void	reset_world(t_game *game)
{
	game->world.ray_index = 0;
	game->world.fov_2 = game->player.fov / 2;
	game->world.theta = game->player.orientation + M_PI_2 - game->world.fov_2;
	if (game->world.theta > 2 * M_PI)
		game->world.theta -= 2 * M_PI;
	game->world.delta = game->player.fov / (double) game->world.image->width;
	game->world.pov = init_vector(TILE_SIZE * game->player.pos.y,
			TILE_SIZE * game->player.pos.x, TILE_SIZE * game->player.pos.z);
	game->world.distance = find_distance_to_projection_plane(game);
}

void	setup_world(t_game *game)
{
	game->world.image = mlx_new_image(game->mlx,
			game->mlx->width, game->mlx->height);
	if (!game->world.image)
		game_fail(game, CUB_MLXFAIL, "Failed to create image");
	free(game->world.rays);
	game->world.rays = (t_ray *) malloc(sizeof(t_ray)
			* game->world.image->width);
	if (!game->world.rays)
		game_fail(game, CUB_MEMFAIL, "creating rays");
	draw_world(game);
	if (mlx_image_to_window(game->mlx, game->world.image, 0, 0) == -1)
		game_fail(game, CUB_MLXFAIL, "Failed to render image");
	mlx_set_instance_depth(game->world.image->instances, 1);
}
