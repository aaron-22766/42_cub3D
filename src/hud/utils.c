#include "../../include/cub3D.h"

void	put_pixel(t_hud *hud, uint32_t x, uint32_t y, uint32_t color)
{
	if (y < hud->minimap_start || y > hud->minimap_end
		|| x < hud->minimap_start || x > hud->minimap_end)
		return ;
	mlx_put_pixel(hud->image, x, y, color);
}

uint32_t	rotate(t_game *game, double a, double b, uint8_t scale)
{
	return (roundf(scale * (a * sin(game->player.orientation)
				+ b * cos(game->player.orientation))));
}
