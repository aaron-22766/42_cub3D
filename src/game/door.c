#include "../../include/cub3D.h"

static t_vector	get_door_vector(t_game *game, int distance)
{
	t_vector	door;
	t_ray		*aim;

	aim = &game->world.rays[game->mlx->width / 2];
	door = init_vector(aim->origin.x + cos(aim->angle) * TILE_SIZE
			* distance, aim->origin.y + sin(aim->angle) * TILE_SIZE
			* distance, aim->origin.z);
	return (door);
}

void	door(t_game *game)
{
	t_vector	door;
	int			door_distance;

	door_distance = 1;
	door = get_door_vector(game, door_distance);
	while (door_distance < MAX_DOOR_DISTANCE && !is_door(game, door))
		door = get_door_vector(game, ++door_distance);
	if (is_door(game, door) == false)
		return ;
	game->flex_map.map[door.x / TILE_SIZE][door.y / TILE_SIZE] -= '0';
	game->flex_map.map[door.x / TILE_SIZE][door.y / TILE_SIZE]++;
	game->flex_map.map[door.x / TILE_SIZE][door.y / TILE_SIZE] %= 2;
	game->flex_map.map[door.x / TILE_SIZE][door.y / TILE_SIZE] += '0';
	draw_minimap(game);
	render_world(game);
}
