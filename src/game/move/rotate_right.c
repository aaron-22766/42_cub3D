
#include "../../../include/cub3D.h"

void	rotate_player_right(t_game *game)
{
	game->player.orientation += ROTATE_SPEED;
	if (game->player.orientation >= 2 * M_PI)
		game->player.orientation -= 2 * M_PI;
}
