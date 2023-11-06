#include "../../include/cub3D.h"

static void	draw_line(t_game *game, uint32_t x, uint32_t y)
{
	int32_t	dx;
	int32_t	dy;
	int32_t	sx;
	int32_t	err;

	dx = ft_abs(x - game->hud.minimap_center);
	dy = -ft_abs(y - game->hud.minimap_center);
	sx = (x < game->hud.minimap_center) * 2 - 1;
	err = dx + dy;
	while (true)
	{
		put_pixel(&game->hud, x, y, MINIMAP_FOV_COLOR);
		if (x == game->hud.minimap_center && y == game->hud.minimap_center)
			break ;
		if (2 * err >= dy)
		{
			err += dy;
			x += sx;
		}
		if (2 * err <= dx)
		{
			err += dx;
			y++;
		}
	}
}

void	draw_fov(t_game *game)
{
	uint32_t	half_way;
	uint32_t	i;
	uint32_t	max;

	half_way = tan(game->player.fov / 2) * game->hud.minimap_center;
	i = game->hud.minimap_center - half_way;
	max = game->hud.minimap_center + half_way;
	while (i < max)
		draw_line(game, i++, 0);
}
