#include "../../include/cub3D.h"

static void	track_fps(t_game *game)
{
	game->fps++;
	game->time += game->mlx->delta_time;
	if (game->time >= 1.0)
	{
		printf("FPS: %d\n\033[K\033[A\r", game->fps);
		game->time = 0;
		game->fps = 0;
	}
}

static void	detect_keys(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W)
		&& !mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_player(game, MOVE_FORWARD);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S)
		&& !mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_player(game, MOVE_BACKWARD);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A)
		&& !mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_player(game, MOVE_LEFT);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D)
		&& !mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_player(game, MOVE_RIGHT);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT)
		&& !mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate_player(game, ROTATE_CCW);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT)
		&& !mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate_player(game, ROTATE_CW);
}

void	hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	track_fps(game);
	detect_keys(game);
	if (game->update)
	{
		game->update = false;
		generate_render(game);
		draw_minimap(game);
	}
	animate_torch(game);
}
