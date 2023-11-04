#include "../../include/cub3D.h"

double	distance(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2)
{
	return (sqrt(pow((double)x2 - x1, 2) + pow((double)y2 - y1, 2)));
}

void	put_pixel(t_hud *hud, uint32_t x, uint32_t y, uint32_t color)
{
	if (y >= hud->minimap_start && y < hud->minimap_end
		&& x >= hud->minimap_start && x < hud->minimap_end/*
		&& distance(hud->minimap_center, hud->minimap_center, x, y)
			< (MINIMAP_TILE_AMOUNT * MINIMAP_TILE_SIZE) / 2*/)
		mlx_put_pixel(hud->image, x, y, color);
}

uint32_t	rotate(t_game *game, double a, double b, uint8_t scale)
{
	return (roundf(scale * (a * sin(game->player.orientation)
				+ b * cos(game->player.orientation))));
}
