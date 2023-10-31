#include "../../include/cub3D.h"

void	rotate_player(t_game *game, t_player_action action)
{
	double	new_orientation;
	double	rotation;

	rotation = MOVE_SPEED / 2;
	new_orientation = game->player.orientation;
	if (action == ROTATE_CCW)
		new_orientation += rotation;
	else if (action == ROTATE_CW)
		new_orientation -= rotation;
	if (new_orientation < 0)
		new_orientation += 2 * M_PI;
	else if (new_orientation >= 2 * M_PI)
		new_orientation -= 2 * M_PI;
	game->player.orientation = new_orientation;
}
