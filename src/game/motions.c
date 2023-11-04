#include "../../include/cub3D.h"

static t_pos	get_displacement(t_game *game, t_player_action action)
{
	t_pos	displacement;

	init_pos(&displacement);
	if (action == MOVE_FORWARD)
	{
		displacement.x = cos(game->player.orientation);
		displacement.y = -sin(game->player.orientation);
	}
	else if (action == MOVE_BACKWARD)
	{
		displacement.x = -cos(game->player.orientation);
		displacement.y = sin(game->player.orientation);
	}
	else if (action == MOVE_LEFT)
	{
		displacement.x = -sin(game->player.orientation);
		displacement.y = -cos(game->player.orientation);
	}
	else if (action == MOVE_RIGHT)
	{
		displacement.x = sin(game->player.orientation);
		displacement.y = cos(game->player.orientation);
	}
	return (displacement);
}

// What was the idea with fmin & fmax here? works better without
// Also could need some simplifying, reducing functions...
// And fix being faster if two keys are pressed (W + D for example)
// Make sliding at wall possible

static t_pos	get_new_pos(t_game *game, t_player_action action)
{
	t_pos	new_pos;
	t_pos	displacement;

	new_pos = game->player.pos;
	displacement = get_displacement(game, action);
	new_pos.x = game->player.pos.x + displacement.x
		* MOVE_SPEED * game->mlx->delta_time;
	// new_pos.x = fmin(fmax(new_pos.x, 1), game->flex_map.max_width - 2);
	new_pos.y = game->player.pos.y + displacement.y
		* MOVE_SPEED * game->mlx->delta_time;
	// new_pos.y = fmin(fmax(new_pos.y, 1), game->flex_map.height - 2);
	/*
	Check if new_pos is a valid position
	*/
	return (new_pos);
}

void	move_player(t_game *game, t_player_action action)
{
	t_pos	new_pos;

	new_pos = get_new_pos(game, action);
	if (game->flex_map.map[(size_t)new_pos.y][(size_t)new_pos.x] == PATH)
	{
		game->player.pos.x = new_pos.x;
		game->player.pos.y = new_pos.y;
	}
	game->update = true;
}
