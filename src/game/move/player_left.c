
#include "../../../include/cub3D.h"

// static void	check_valid_position

void	move_player_left(t_game *game)
{
	t_pos	new_pos;

	new_pos.x = game->player.pos.x - cos(game->player.orientation) * MOVE_SPEED;
	new_pos.y = game->player.pos.y + sin(game->player.orientation) * MOVE_SPEED;
	if (true) // check_valid_position(game, new_pos.x, new_pos.y))
	{
		game->player.pos = new_pos;
	}
}
