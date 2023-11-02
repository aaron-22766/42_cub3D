#include "../../include/cub3D.h"

static void	draw_background(t_hud *hud)
{
	uint32_t	x;
	uint32_t	y;

	y = 0;
	while (y < hud->minimap_size && y + MINIMAP_OFFSET < WINDOW_WIDTH)
	{
		x = 0;
		while (x < hud->minimap_size && x + MINIMAP_OFFSET < WINDOW_HEIGHT)
			mlx_put_pixel(hud->image, MINIMAP_OFFSET + x++,
				MINIMAP_OFFSET + y, MINIMAP_PATH_COLOR);
		y++;
	}
}

static void	draw_square_line(t_hud *hud, uint8_t offset)
{
	size_t	i;

	i = 0;
	while (i < (size_t)(hud->minimap_size - offset - 1))
	{
		mlx_put_pixel(hud->image, MINIMAP_OFFSET + offset + i, MINIMAP_OFFSET
			+ offset, hud->minimap_color);
		mlx_put_pixel(hud->image, MINIMAP_OFFSET + offset, MINIMAP_OFFSET
			+ offset + i, hud->minimap_color);
		mlx_put_pixel(hud->image, MINIMAP_OFFSET + offset + i, MINIMAP_OFFSET
			+ hud->minimap_size - offset - 1, hud->minimap_color);
		mlx_put_pixel(hud->image, MINIMAP_OFFSET + hud->minimap_size
			- offset - 1, MINIMAP_OFFSET + offset + i, hud->minimap_color);
		i++;
	}
	mlx_put_pixel(hud->image, MINIMAP_OFFSET + i, MINIMAP_OFFSET + i,
		hud->minimap_color);
}

static void	draw_frame(t_hud *hud)
{
	uint8_t	i;

	i = 0;
	while (i < MINIMAP_FRAME_WIDTH)
		draw_square_line(hud, i++);
}

static void	draw_player(t_hud *hud)
{
	int8_t	i;
	int8_t	j;

	i = -3;
	while (++i < 3)
	{
		j = -3;
		while (++j < 3)
			mlx_put_pixel(hud->image, hud->minimap_center + i,
				hud->minimap_center + j, hud->minimap_color);
	}
	i = -2;
	while (++i < 2)
	{
		mlx_put_pixel(hud->image, hud->minimap_center + 3,
					hud->minimap_center + i, hud->minimap_color);
		mlx_put_pixel(hud->image, hud->minimap_center - 3,
					hud->minimap_center + i, hud->minimap_color);
		mlx_put_pixel(hud->image, hud->minimap_center + i,
					hud->minimap_center + 3, hud->minimap_color);
		mlx_put_pixel(hud->image, hud->minimap_center + i,
					hud->minimap_center - 3, hud->minimap_color);
	}
}

void	draw_minimap(t_game *game)
{
	draw_background(&game->hud);
	draw_doors(game);
	draw_walls(game);
	draw_player(&game->hud);
	draw_frame(&game->hud);
}
