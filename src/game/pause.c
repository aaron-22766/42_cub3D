#include "../../include/cub3D.h"

void	render_pause_screen(t_game *game)
{
	if (game->paused)
	{
		create_blur(game);
		game->pause_screen->enabled = true;
		game->pause_text = mlx_put_string(game->mlx, "Press P to play",
				game->pause_screen->width / 2 - 75,
				game->pause_screen->height / 2 - 10);
		mlx_set_instance_depth(game->pause_text->instances, 4);
	}
	else
	{
		game->pause_screen->enabled = false;
		delete_image(game->mlx, game->pause_text);
	}
}

void	pause_key(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int32_t	temp_mouse_y;

	game = param;
	if (game->too_small || keydata.action != MLX_PRESS
		|| keydata.key != MLX_KEY_P)
		return ;
	game->paused = !game->paused;
	if (game->paused)
		mlx_set_cursor_mode(game->mlx, MLX_MOUSE_NORMAL);
	else
	{
		mlx_set_cursor_mode(game->mlx, MLX_MOUSE_DISABLED);
		mlx_get_mouse_pos(game->mlx, &game->mouse_x, &temp_mouse_y);
	}
	render_pause_screen(game);
}
