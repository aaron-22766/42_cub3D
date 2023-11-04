#include "../../include/cub3D.h"

static void	draw_background(t_hud *hud)
{
	uint32_t	x;
	uint32_t	y;

	y = MINIMAP_FRAME_WIDTH;
	while (y < hud->minimap_size - MINIMAP_FRAME_WIDTH
		&& y + MINIMAP_OFFSET < WINDOW_WIDTH)
	{
		x = MINIMAP_FRAME_WIDTH;
		while (x < hud->minimap_size - MINIMAP_FRAME_WIDTH
			&& x + MINIMAP_OFFSET < WINDOW_HEIGHT)
			mlx_put_pixel(hud->image, MINIMAP_OFFSET + x++,
				MINIMAP_OFFSET + y, MINIMAP_PATH_COLOR);
		y++;
	}
}

static void	draw_player(t_hud *hud)
{
	int8_t	i;
	int8_t	j;

	i = -3;
	while (i <= 3)
	{
		j = -3;
		while (j <= 3)
		{
			if (distance(hud->minimap_center, hud->minimap_center,
					hud->minimap_center + i, hud->minimap_center + j) < 3.5)
				mlx_put_pixel(hud->image, hud->minimap_center + i,
					hud->minimap_center + j, hud->minimap_color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_game *game)
{
	draw_background(&game->hud);
	draw_fov(game);
	draw_doors(game);
	draw_walls(game);
	draw_player(&game->hud);
}
