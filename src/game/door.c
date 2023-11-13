#include "../../include/cub3D.h"

void	door(t_game *game)
{
	t_vector	door;
	t_ray	*aim;

	aim = &game->world.rays[game->mlx->width / 2];
	if (get_distance_between(aim->d_hor, zero_vector())
		< get_distance_between(aim->d_ver, zero_vector()))
		door = vector_sum(aim->origin, aim->d_hor);
	else
		door = vector_sum(aim->origin, aim->d_ver);
	if (is_door(game, door) == false)
		return ;
	game->flex_map.map[door.x / TILE_SIZE][door.y / TILE_SIZE] -= '0';
	game->flex_map.map[door.x / TILE_SIZE][door.y / TILE_SIZE]++;
	game->flex_map.map[door.x / TILE_SIZE][door.y / TILE_SIZE] %= 2;
	game->flex_map.map[door.x / TILE_SIZE][door.y / TILE_SIZE] += '0';
	draw_minimap(game);
	render_world(game);
}
