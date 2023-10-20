
#include "../../include/cub3D.h"

void	run_game(t_game *game)
{
	render_background(game);
	mlx_loop_hook(game->mlx, key_hook, game);
	mlx_loop(game->mlx);
}
