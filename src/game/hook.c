#include "../../include/cub3D.h"

void	hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_player(game, MOVE_FORWARD);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_player(game, MOVE_BACKWARD);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_player(game, MOVE_LEFT);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_player(game, MOVE_RIGHT);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate_player(game, ROTATE_CCW);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate_player(game, ROTATE_CW);
	// print_pos(&game->player.pos);
	generate_render(game);
	draw_foreground(game);
	mlx_image_to_window(game->mlx, game->image, 0, 0);
}
