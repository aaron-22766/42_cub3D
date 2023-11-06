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

	x = floor(vector.x / TILE_SIZE);
	y = floor(vector.y / TILE_SIZE);
	if (x <= 0 || y <= 0 || x >= game->flex_map.height || y >= game->flex_map.max_width)
		return (true);
	return (game->flex_map.map[y][x] != '0');// || game->flex_map.map[y][x] == ' ');
}
