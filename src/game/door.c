#include "../../include/cub3D.h"

static bool	is_door(t_game *game, t_vector vector)
{
	if (vector.x < TILE_SIZE || vector.y < TILE_SIZE
		|| vector.x >= (int64_t) game->flex_map.height * TILE_SIZE
		|| vector.y >= (int64_t) game->flex_map.max_width * TILE_SIZE
		|| game->fix_map.map[vector.x / TILE_SIZE][vector.y / TILE_SIZE] != 'D')
		return (false);	
	return (true);
}

void	door(t_game *game)
{
	t_ray	*aim;

	printf("DOOR\n");
	aim = &game->world.rays[game->mlx->width / 2];
	if (aim->length > DOOR_DISTANCE * TILE_SIZE
		|| is_door(game, aim->hit) == false)
		return ;
	// if (game->flex_map.map[aim.target.y][aim.target.x] == MAP_WALL)
	// 	game->flex_map.map[aim.target.y][aim.target.x] == MAP_PATH;
	// else
	// 	game->flex_map.map[aim.target.y][aim.target.x] == MAP_WALL;
	// draw_minimap(game);
	// generate_render(game);
	game->flex_map.map[aim->hit.x / TILE_SIZE][aim->hit.y / TILE_SIZE] -= '0';
	game->flex_map.map[aim->hit.x / TILE_SIZE][aim->hit.y / TILE_SIZE]++;
	game->flex_map.map[aim->hit.x / TILE_SIZE][aim->hit.y / TILE_SIZE] %= 2;
	game->flex_map.map[aim->hit.x / TILE_SIZE][aim->hit.y / TILE_SIZE] += '0';
	draw_minimap(game);
	generate_render(game);
}
