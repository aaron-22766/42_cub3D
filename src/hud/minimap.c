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

static void	draw_tile(mlx_image_t *image, size_t x, size_t y, uint32_t color)
{
	uint8_t	tile_x;
	uint8_t	tile_y;

	tile_y = 0;
	while (tile_y < MINIMAP_TILE_SIZE)
	{
		tile_x = 0;
		while (tile_x < MINIMAP_TILE_SIZE)
			mlx_put_pixel(image,
				MINIMAP_OFFSET + MINIMAP_FRAME_WIDTH + x + tile_x++,
				MINIMAP_OFFSET + MINIMAP_FRAME_WIDTH + y + tile_y, color);
		tile_y++;
	}
}

void	draw_map(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < MINIMAP_TILE_AMOUNT && y < game->fix_map.height)
	{
		x = 0;
		while (x < MINIMAP_TILE_AMOUNT && x < game->fix_map.max_width)
		{
			if (game->fix_map.map[y][x] == WALL)
				draw_tile(game->hud.image, MINIMAP_TILE_SIZE * x,
					MINIMAP_TILE_SIZE * y, MINIMAP_WALL_COLOR);
			x++;
		}
		y++;
	}
}

void	draw_player(t_hud *hud)
{
	int8_t	i;
	int8_t	j;

	i = -1;
	while (++i < 4)
	{
		j = -2;
		while (++j <= 1)
		{
			mlx_put_pixel(hud->image, hud->minimap_center + j,
				hud->minimap_center + i, hud->minimap_color);
			mlx_put_pixel(hud->image, hud->minimap_center + j,
				hud->minimap_center - i, hud->minimap_color);
			mlx_put_pixel(hud->image, hud->minimap_center + i,
				hud->minimap_center + j, hud->minimap_color);
			mlx_put_pixel(hud->image, hud->minimap_center - i,
				hud->minimap_center + j, hud->minimap_color);
		}
	}
	i = -3;
	while (++i < 3)
	{
		j = -3;
		while (++j < 3)
			mlx_put_pixel(hud->image, hud->minimap_center + i,
				hud->minimap_center + j, hud->minimap_color);
	}
}

void	draw_minimap(t_game *game)
{
	draw_background(&game->hud);
	draw_map(game);
	draw_frame(&game->hud);
	draw_player(&game->hud);
}
