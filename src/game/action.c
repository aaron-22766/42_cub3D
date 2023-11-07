#include "../../include/cub3D.h"

void	rotate_player(t_game *game, double dir)
{
	game->player.orientation += dir * ROTATE_SPEED * game->mlx->delta_time;
	if (game->player.orientation < 0)
		game->player.orientation += 2 * M_PI;
	else if (game->player.orientation >= 2 * M_PI)
		game->player.orientation -= 2 * M_PI;
}

static void	move_player(t_game *game, double x, double y)
{
	t_pos	dir;

	dir.x = x * MOVE_SPEED * game->mlx->delta_time;
	dir.y = y * MOVE_SPEED * game->mlx->delta_time;
	if (game->flex_map.map[(size_t)game->player.pos.y][(size_t)(game->player. \
		pos.x + dir.x + game->collision * sign(x))] == PATH)
		game->player.pos.x += dir.x;
	if (game->flex_map.map[(size_t)((game->player.pos.y + dir.y + \
		game->collision * sign(y)))][(size_t)(game->player.pos.x)] == PATH)
		game->player.pos.y += dir.y;
}

static bool	no_movement(t_keys_down *keys)
{
	if ((*keys & KEY_W) && (*keys & KEY_S))
		*keys &= ~(KEY_W | KEY_S);
	if ((*keys & KEY_A) && (*keys & KEY_D))
		*keys &= ~(KEY_A | KEY_D);
	return (!(*keys & (KEY_W | KEY_A | KEY_S | KEY_D)));
}

void	do_player_action(t_game *game, t_keys_down keys)
{
	double	sin_angle;
	double	cos_angle;

	if ((keys & KEY_LEFT) && !(keys & KEY_RIGHT))
		rotate_player(game, 1.0);
	else if ((keys & KEY_RIGHT) && !(keys & KEY_LEFT))
		rotate_player(game, -1.0);
	if (no_movement(&keys))
		return ;
	sin_angle = sin(game->player.orientation);
	cos_angle = cos(game->player.orientation);
	if ((keys & (KEY_W | KEY_S)) && (keys & (KEY_A | KEY_D)))
	{
		sin_angle *= M_SQRT1_2;
		cos_angle *= M_SQRT1_2;
	}
	if (keys & KEY_W)
		move_player(game, cos_angle, -sin_angle);
	else if (keys & KEY_S)
		move_player(game, -cos_angle, sin_angle);
	if (keys & KEY_A)
		move_player(game, -sin_angle, -cos_angle);
	else if (keys & KEY_D)
		move_player(game, sin_angle, cos_angle);
}
