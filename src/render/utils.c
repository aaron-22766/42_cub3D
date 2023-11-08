#include "../../include/cub3D.h"

int64_t	get_distance_between(t_vector vector, t_vector origin)
{
	t_vector	distance;

	distance.x = vector.x - origin.x;
	distance.y = vector.y - origin.y;
	// distance.z = vector.z - origin.z;
	distance.z = 0;
	return (sqrt(pow(distance.x, 2) + pow(distance.y, 2) + pow(distance.z, 2)));
}

bool	is_wall(t_game *game, t_vector vector)
{
	size_t	x;
	size_t	y;

	x = floor((double) vector.x / TILE_SIZE);
	y = floor((double) vector.y / TILE_SIZE);
	if (vector.x < TILE_SIZE || vector.y < TILE_SIZE
		|| vector.x >= (int64_t) game->flex_map.height * TILE_SIZE
		|| vector.y >= (int64_t) game->flex_map.max_width * TILE_SIZE)
		return (1);
	return (game->flex_map.map[y][x] != '0');
}
