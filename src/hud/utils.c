#include "../../include/cub3D.h"

void	draw_circle(t_hud *hud, double radius, uint32_t color)
{
	uint32_t	i;
	uint32_t	j;
	uint32_t	edge;

	edge = hud->minimap_center + radius;
	i = hud->minimap_center - radius;
	while (i <= edge)
	{
		j = hud->minimap_center - radius;
		while (j <= edge)
		{
			if (sqrd_distance(hud->minimap_center, hud->minimap_center, i, j)
				< radius * radius)
				mlx_put_pixel(hud->image, i, j, color);
			j++;
		}
		i++;
	}
}

uint32_t	rotate(t_game *game, double a, double b, uint8_t scale)
{
	return (roundf(scale * (a * sin(game->player.orientation)
				+ b * cos(game->player.orientation))));
}

uint32_t	sqrd_distance(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2)
{
	uint32_t	dx;
	uint32_t	dy;

	dx = x2 - x1;
	dy = y2 - y1;
	return (dx * dx + dy * dy);
}

void	put_pixel(t_hud *hud, uint32_t x, uint32_t y, uint32_t color)
{
	if (sqrd_distance(hud->minimap_center, hud->minimap_center, x, y)
		< hud->minimap_radius_sqrd)
		mlx_put_pixel(hud->image, x, y, color);
}
