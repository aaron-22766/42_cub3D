
#include "../../include/cub3D.h"

void	rotate_counterclockwise(t_game *game)
{
	game->player.orientation -= ROTATE_SPEED;
	if (game->player.orientation < 0)
		game->player.orientation += 2 * M_PI;
}


void	rotate_clockwise(t_game *game)
{
	game->player.orientation += ROTATE_SPEED;
	if (game->player.orientation >= 2 * M_PI)
		game->player.orientation -= 2 * M_PI;
}

void	rotate_player(t_game *game, t_player_action action)
{
	double	new_orientation;

	new_orientation = game->player.orientation;
	if (action == ROTATE_CCW)
		new_orientation -= ROTATE_SPEED;
	else if (action == ROTATE_CW)
		new_orientation += ROTATE_SPEED;
	if (new_orientation < 0)
		new_orientation += 2 * M_PI;
	else if (new_orientation >= 2 * M_PI)
		new_orientation -= 2 * M_PI;
	game->player.orientation = new_orientation;
}

/* To be implemented later
 * rotate_player_up(t_game *game)
 * rotate_player_down(t_game *game)
 * 
 */
