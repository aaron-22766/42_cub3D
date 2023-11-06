#include "../../include/cub3D.h"

static void	draw_plus(t_hud *hud, uint32_t x, uint32_t y, uint32_t color)
{
	put_pixel(hud, x, y, color);
	put_pixel(hud, x + 1, y, color);
	put_pixel(hud, x - 1, y, color);
	put_pixel(hud, x, y + 1, color);
	put_pixel(hud, x, y - 1, color);
}

static void	draw_square(t_game *game, uint32_t x, uint32_t y, uint32_t color)
{
	int8_t	i;
	int8_t	j;

	i = -game->hud.minimap_half_tile_size + MINIMAP_TILE_GAP;
	while (++i < game->hud.minimap_half_tile_size - 1 - MINIMAP_TILE_GAP)
	{
		j = -game->hud.minimap_half_tile_size + MINIMAP_TILE_GAP;
		while (++j < game->hud.minimap_half_tile_size - 1 - MINIMAP_TILE_GAP)
			draw_plus(&game->hud, x + rotate(game, j, i, 1),
				y + rotate(game, i, -j, 1), color);
	}
	i = -game->hud.minimap_half_tile_size - 1 + MINIMAP_TILE_GAP;
	j = game->hud.minimap_half_tile_size - MINIMAP_TILE_GAP;
	while (++i < j + 1)
	{
		put_pixel(&game->hud, x + rotate(game, j, i, 1),
			y + rotate(game, i, -j, 1), color);
		put_pixel(&game->hud, x + rotate(game, -j, i, 1),
			y + rotate(game, i, j, 1), color);
		put_pixel(&game->hud, x + rotate(game, i, -j, 1),
			y + rotate(game, -j, -i, 1), color);
		put_pixel(&game->hud, x + rotate(game, i, j, 1),
			y + rotate(game, j, -i, 1), color);
	}
}

void	draw_tile(t_game *game, size_t x, size_t y, uint32_t color)
{
	double	rel_x;
	double	rel_y;

	rel_x = x + 0.5 - game->player.pos.x;
	rel_y = y + 0.5 - game->player.pos.y;
	draw_square(game, game->hud.minimap_center + rotate(game, rel_x, rel_y,
			MINIMAP_TILE_SIZE), game->hud.minimap_center + rotate(game, rel_y,
			-rel_x, MINIMAP_TILE_SIZE), color);
}
