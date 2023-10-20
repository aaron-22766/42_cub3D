
#include "../../../include/cub3D.h"

void	move_player_backward(t_game *game)
{
	t_pos	new_pos;

	new_pos.x = game->player.x - cos(game->player.orientation) * MOVE_SPEED;
	new_pos.y = game->player.y - sin(game->player.orientation) * MOVE_SPEED;
	if (true) // check_valid_position(game, new_pos.x, new_pos.y))
	{
		game->player.pos = new_pos;
	}
}
