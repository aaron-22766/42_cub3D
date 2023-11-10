#include "../../include/cub3D.h"

static void	track_fps(t_game *game)
{
	game->fps++;
	game->time += game->mlx->delta_time;
	if (game->time >= 1.0)
	{
		printf("FPS: %.0f\n\033[A\033[K\r", game->fps / game->time);
		game->time = 0;
		game->fps = 0;
	}
}

static t_keys_down	detect_keys(t_game *game)
{
	t_keys_down	keys;

	keys = KEY_NONE;
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
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		keys |= KEY_ESCAPE;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SHIFT))
		keys |= KEY_LEFT_SHIFT;
	if (mlx_is_key_down(game->mlx, MLX_KEY_F))
		keys |= KEY_F;
	return (keys);
}

static bool	mouse_moved(t_game *game)
{
	int32_t	new_mouse_x;
	int32_t	temp_mouse_y;

	mlx_get_mouse_pos(game->mlx, &new_mouse_x, &temp_mouse_y);
	if (new_mouse_x != game->mouse_x)
	{
		rotate_player(game, (double)(game->mouse_x - new_mouse_x)
			/ MOUSE_DIVISOR);
		game->mouse_x = new_mouse_x;
		return (true);
	}
	return (false);
}

void	hook(void *param)
{
	t_game		*game;
	t_keys_down	keys;

	game = (t_game *)param;
	if (game->resized)
		resize_game(game);
	keys = detect_keys(game);
	if (keys & KEY_ESCAPE)
		mlx_close_window(game->mlx);
	if (game->paused || game->too_small || (keys & KEY_ESCAPE))
		return ;
	if (keys & KEY_PLAYER)
		do_player_action(game, &keys);
	if (mouse_moved(game) || (keys & KEY_PLAYER))
	{
		generate_render(game);
		draw_minimap(game);
	}
	animate_torch(game, false);
	track_fps(game);
}
