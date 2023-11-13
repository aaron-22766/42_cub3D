#include "../../include/cub3D.h"

int8_t	sign(double x)
{
	return ((x > 0) - (x < 0));
}

bool	is_door(t_game *game, t_vector vector)
{
	if (vector.x < TILE_SIZE || vector.y < TILE_SIZE
		|| vector.x >= (int64_t) game->flex_map.height * TILE_SIZE
		|| vector.y >= (int64_t) game->flex_map.max_width * TILE_SIZE
		|| game->fix_map.map[vector.x / TILE_SIZE][vector.y / TILE_SIZE] != 'D')
		return (false);
	return (true);
}
