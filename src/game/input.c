#include "../../include/cub3D.h"

void	keyboard(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (game->too_small)
		return ;
	if (!game->paused && keydata.action == MLX_PRESS
		&& keydata.key == MLX_KEY_SPACE)
		door(game);
	if (keydata.action != MLX_PRESS || keydata.key != MLX_KEY_P)
		return ;
	toggle_pause(game);
}

void	mouse(mouse_key_t button, action_t action,
	modifier_key_t mods, void *param)
{
	t_game	*game;
	bool	redraw;

	(void)mods;
	game = param;
	if (game->paused || game->too_small)
		return ;
	if (action == MLX_PRESS && button == MLX_MOUSE_BUTTON_LEFT)
		door(game);
	if (action != MLX_RELEASE || button != MLX_MOUSE_BUTTON_MIDDLE)
		return ;
	redraw = false;
	if (set_fov(game, game->player.default_fov))
	{
		render_world(game);
		redraw = true;
	}
	if (set_zoom(game, MINIMAP_DEFAULT_TILE_SIZE))
		redraw = true;
	if (redraw)
		draw_minimap(game);
}
