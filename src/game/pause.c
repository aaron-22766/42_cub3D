#include "../../include/cub3D.h"

void	render_pause_screen(t_game *game)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	color;

	color = INVISIBLE;
	if (game->paused)
		color = PAUSE_SCREEN_BACKGROUND;
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
			mlx_put_pixel(game->pause_screen, x++, y, color);
		y++;
	}
	if (game->paused)
	{
		game->pause_text = mlx_put_string(game->mlx, "Press P to play",
				WINDOW_WIDTH / 2 - 75, WINDOW_HEIGHT / 2 - 10);
		mlx_set_instance_depth(game->pause_text->instances, 4);
	}
	else
		delete_image(game->mlx, game->pause_text);
}

void	pause_key(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int32_t	temp_mouse_y;

	if (keydata.action != MLX_PRESS || keydata.key != MLX_KEY_P)
		return ;
	game = param;
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
