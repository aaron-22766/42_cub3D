#include "../../include/cub3D.h"

void	draw_minimap(t_game *game)
{
	draw_circle(&game->hud, MINIMAP_RADIUS, MINIMAP_PATH_COLOR);
	draw_fov(game);
	draw_doors(game);
	draw_walls(game);
	draw_circle(&game->hud, game->hud.minimap_player_radius,
		game->hud.minimap_color);
}
