#include "../../include/cub3D.h"

void	rotate_player(t_game *game, double dir)
{
	game->player.orientation += dir * ROTATE_SPEED * game->mlx->delta_time;
	if (game->player.orientation < 0)
		game->player.orientation += 2 * M_PI;
	else if (game->player.orientation >= 2 * M_PI)
		game->player.orientation -= 2 * M_PI;
}

void	move_player(t_game *game, double x, double y)
{
	t_pos	dir;

	dir.x = x * game->player.speed * game->mlx->delta_time;
	dir.y = y * game->player.speed * game->mlx->delta_time;
	if (game->flex_map.map[(uint32_t)game->player.pos.y][(uint32_t) \
		(game->player. pos.x + dir.x + COLLISION * sign(x))] == MAP_PATH)
		game->player.pos.x += dir.x;
	if (game->flex_map.map[(uint32_t)((game->player.pos.y + dir.y + \
		COLLISION * sign(y)))][(uint32_t)(game->player.pos.x)] == MAP_PATH)
		game->player.pos.y += dir.y;
}
