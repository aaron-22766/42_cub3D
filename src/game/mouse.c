#include "../../include/cub3D.h"

static bool	set_zoom(t_game *game, uint32_t new_tile_size)
{
	double	new_radius;

	if (new_tile_size == game->hud.minimap_tile_size
		|| new_tile_size < MINIMAP_MIN_TILE_SIZE
		|| new_tile_size > MINIMAP_MAX_TILE_SIZE)
		return (false);
	game->nb_tiles = MINIMAP_RADIUS / new_tile_size;
	game->hud.minimap_tile_size = new_tile_size;
	game->hud.minimap_half_tile_size = new_tile_size / 2.0;
	new_radius = (double)new_tile_size / MINIMAP_PLAYER_SIZE_DIVISOR;
	if (new_radius > MINIMAP_MIN_PLAYER_SIZE)
		game->hud.minimap_player_radius = new_radius;
	return (true);
}

static bool	set_fov(t_game *game, double new_fov)
{
	if (new_fov == game->player.fov || new_fov < game->player.min_fov
		|| new_fov > game->player.max_fov)
		return (false);
	game->player.fov = new_fov;
	return (true);
}

void	zoom_minimap(double xdelta, double ydelta, void *param)
{
	t_game	*game;
	bool	redraw;

	game = param;
	if (game->paused)
		return ;
	redraw = false;
	if (set_fov(game, game->player.fov + sign(xdelta) / 11.0))
		redraw = true;
	if (set_zoom(game, game->hud.minimap_tile_size + sign(ydelta) * 2))
		redraw = true;
	if (redraw)
		draw_minimap(game);
}

void	reset_minimap(mouse_key_t button, action_t action,
	modifier_key_t mods, void *param)
{
	t_game	*game;
	bool	redraw;

	(void)mods;
	game = param;
	if (game->paused || action != MLX_RELEASE
		|| button != MLX_MOUSE_BUTTON_MIDDLE)
		return ;
	redraw = false;
	if (set_fov(game, PLAYER_DEFAULT_FOV / 180.0 * M_PI))
		redraw = true;
	if (set_zoom(game, MINIMAP_DEFAULT_TILE_SIZE))
		redraw = true;
	if (redraw)
		draw_minimap(game);
}
