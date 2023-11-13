#include "../../include/cub3D.h"

void	door(t_game *game)
{
	t_ray	*aim;

	aim = &game->world.rays[game->mlx->width / 2];
	if (aim->length > DOOR_DISTANCE * TILE_SIZE
		|| is_door(game, aim->hit) == false)
		return ;
	game->flex_map.map[aim->hit.x / TILE_SIZE][aim->hit.y / TILE_SIZE] -= '0';
	game->flex_map.map[aim->hit.x / TILE_SIZE][aim->hit.y / TILE_SIZE]++;
	game->flex_map.map[aim->hit.x / TILE_SIZE][aim->hit.y / TILE_SIZE] %= 2;
	game->flex_map.map[aim->hit.x / TILE_SIZE][aim->hit.y / TILE_SIZE] += '0';
	draw_minimap(game);
	render_world(game);
}
