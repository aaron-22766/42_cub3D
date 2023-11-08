#include "../../include/cub3D.h"

static void	set_zoom(t_game *game, uint32_t new_tile_size)
{
	if (new_tile_size < MINIMAP_MIN_TILE_SIZE
		|| new_tile_size > MINIMAP_MAX_TILE_SIZE)
		return ;
	game->hud.minimap_tile_size = new_tile_size;
	game->hud.minimap_half_tile_size = new_tile_size / 2.0;
	game->collision = MINIMAP_PLAYER_RADIUS / new_tile_size;
	game->nb_tiles = MINIMAP_RADIUS / new_tile_size;
	draw_minimap(game);
}

void	zoom_minimap(double xdelta, double ydelta, void *param)
{
	t_game	*game;

	(void)xdelta;
	game = param;
	set_zoom(game, game->hud.minimap_tile_size + sign(ydelta) * 2);
}

void	reset_zoom(mouse_key_t button, action_t action,
	modifier_key_t mods, void *param)
{
	t_game	*game;

	(void)mods;
	game = param;
	if (action == MLX_RELEASE && button == MLX_MOUSE_BUTTON_MIDDLE)
		set_zoom(game, MINIMAP_DEFAULT_TILE_SIZE);
}
