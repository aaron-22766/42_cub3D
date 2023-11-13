#include "../../include/cub3D.h"

int64_t	get_distance_between(t_vector vector, t_vector origin)
{
	t_vector	distance;

	distance.x = vector.x - origin.x;
	distance.y = vector.y - origin.y;
	distance.z = vector.z - origin.z;
	return (sqrt(pow(distance.x, 2) + pow(distance.y, 2) + pow(distance.z, 2)));
}

bool	is_wall(t_game *game, t_vector vector)
{
	if (vector.x < TILE_SIZE || vector.y < TILE_SIZE
		|| vector.x >= (int64_t) game->flex_map.height * TILE_SIZE
		|| vector.y >= (int64_t) game->flex_map.max_width * TILE_SIZE
		|| game->flex_map.map[vector.x / TILE_SIZE][vector.y / TILE_SIZE]
			!= MAP_PATH)
		return (true);
	return (false);
}
