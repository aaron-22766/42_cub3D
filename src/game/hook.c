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

static t_keys_down	detect_keys(t_game *game)
{
	t_keys_down	keys;

	keys = KEY_NONE;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		keys |= KEY_W;
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		keys |= KEY_A;
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		keys |= KEY_S;
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		keys |= KEY_D;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		keys |= KEY_LEFT;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		keys |= KEY_RIGHT;
	return (keys);
}

void	hook(void *param)
{
	t_game		*game;
	t_keys_down	keys;

	game = (t_game *)param;
	keys = detect_keys(game);
	if (keys != KEY_NONE)
	{
		do_player_action(game, keys);
		generate_render(game);
		draw_minimap(game);
	}
	animate_torch(game);
	track_fps(game);
}
