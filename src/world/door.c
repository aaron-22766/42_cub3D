#include "../../include/cub3D.h"

static t_vector	get_door_vector(t_game *game)
{
	int64_t		distance;
	int64_t		dx;
	int64_t		dy;
	t_vector	door;
	t_ray		*aim;

	distance = 0;
	door = zero_vector();
	aim = &game->world.rays[game->mlx->width / 2];
	dx = cos(aim->angle) * TILE_SIZE;
	dy = sin(aim->angle) * TILE_SIZE;
	while (distance < MAX_DOOR_DISTANCE && !is_door(game, door))
	{
		distance++;
		door = init_vector(aim->origin.x + dx * distance,
		aim->origin.y + dy * distance, aim->origin.z);
	}
	return (door);
}

static void	change_door_state(char **map, t_vector door)
{
	if (map[door.x / TILE_SIZE][door.y / TILE_SIZE] == MAP_DOOR)
		map[door.x / TILE_SIZE][door.y / TILE_SIZE] = MAP_PATH;
	else
		map[door.x / TILE_SIZE][door.y / TILE_SIZE] = MAP_DOOR;
}

void	draw_door(t_game *game)
{
	t_vector	door;

	door = get_door_vector(game);
	if (is_door(game, door) == false)
		return ;
	change_door_state(game->flex_map.map, door);
	draw_minimap(game);
	draw_world(game);
}
