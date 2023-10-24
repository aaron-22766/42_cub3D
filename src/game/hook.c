
#include "../../include/cub3D.h"

void	key_hook(mlx_key_data_t keydata, void* param)
{
	t_game	*game;

	game = (t_game*)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_forward(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_backward(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_right(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate_counterclockwise(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate_clockwise(game);
	generate_render(game);
}

/**
 * To-do: mouse_hook
 * 
 */

