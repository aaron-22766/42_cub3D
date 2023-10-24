

#include "../../include/cub3D.h"

/**
 * TODO:	-	Wall collision
 * 			-	Door collision ?
 */

// static void	check_valid_position(t_game *game, double x, double y)

void	move_backward(t_game *game)
{
	t_pos	new_pos;

	new_pos.x = game->player.pos.x - cos(game->player.orientation) * MOVE_SPEED;
	new_pos.y = game->player.pos.y - sin(game->player.orientation) * MOVE_SPEED;
	if (true) // check_valid_position(game, new_pos.x, new_pos.y))
	{
		game->player.pos = new_pos;
	}
}


void	move_forward(t_game *game)
{
	t_pos	new_pos;

	new_pos.x = game->player.pos.x + cos(game->player.orientation) * MOVE_SPEED;
	new_pos.y = game->player.pos.y + sin(game->player.orientation) * MOVE_SPEED;
	if (true)
	{
		game->player.pos = new_pos;
	}
}

void	move_left(t_game *game)
{
	t_pos	new_pos;

	new_pos.x = game->player.pos.x - cos(game->player.orientation) * MOVE_SPEED;
	new_pos.y = game->player.pos.y + sin(game->player.orientation) * MOVE_SPEED;
	if (true)
	{
		game->player.pos = new_pos;
	}
}

void	move_right(t_game *game)
{
	t_pos	new_pos;

	new_pos.x = game->player.pos.x + cos(game->player.orientation) * MOVE_SPEED;
	new_pos.y = game->player.pos.y - sin(game->player.orientation) * MOVE_SPEED;
	if (true)
	{
		game->player.pos = new_pos;
	}
}
