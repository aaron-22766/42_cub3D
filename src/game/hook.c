#include "../../include/cub3D.h"

void	key_hook(void* param)
{
	t_game	*game;

	game = (t_game*)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(game->mlx);
		exit(EXIT_SUCCESS);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_player_forward(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_player_backward(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_player_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_player_right(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate_player_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate_player_right(game);
	print_player(&game->player);		//DEBUG
	render_background(game);
	mlx_image_to_window(game->mlx, game->image, 0, 0);
}
