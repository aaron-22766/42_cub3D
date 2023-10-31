#include "../../include/cub3D.h"

static void	draw_background(t_game *game)
{
	uint32_t	x;
	uint32_t	y;

	y = 0;

	while (y < MINIMAP_SIZE && y + MINIMAP_OFFSET < WINDOW_WIDTH)
	{
		x = 0;
		while (x < MINIMAP_SIZE && x + MINIMAP_OFFSET < WINDOW_HEIGHT)
			mlx_put_pixel(game->foreground, MINIMAP_OFFSET + x++,
				MINIMAP_OFFSET + y, MINIMAP_PATH_COLOR);
		y++;
	}
}

static void	draw_square_line(t_game *game, uint8_t offset)
{
	size_t	i;

	i = 0;
	while (i < (size_t)(MINIMAP_SIZE - offset - 1))
	{
		mlx_put_pixel(game->foreground, MINIMAP_OFFSET + offset + i,
			MINIMAP_OFFSET + offset, MINIMAP_FRAME_COLOR);
		mlx_put_pixel(game->foreground, MINIMAP_OFFSET + offset,
			MINIMAP_OFFSET + offset + i, MINIMAP_FRAME_COLOR);
		mlx_put_pixel(game->foreground, MINIMAP_OFFSET + offset + i,
			MINIMAP_OFFSET + MINIMAP_SIZE - offset - 1, MINIMAP_FRAME_COLOR);
		mlx_put_pixel(game->foreground, MINIMAP_OFFSET + MINIMAP_SIZE
			- offset - 1, MINIMAP_OFFSET + offset + i, MINIMAP_FRAME_COLOR);
		i++;
	}
	mlx_put_pixel(game->foreground, MINIMAP_OFFSET + i,
		MINIMAP_OFFSET + i, MINIMAP_FRAME_COLOR);
}

static void	draw_frame(t_game *game)
{
	uint8_t	i;

	i = 0;
	while (i < MINIMAP_FRAME_WIDTH)
		draw_square_line(game, i++);
}

static void	draw_tile(t_game *game, size_t x, size_t y, uint32_t color)
{
	uint8_t	tile_x;
	uint8_t	tile_y;

	tile_y = 0;
	while (tile_y < MINIMAP_TILE_SIZE)
	{
		tile_x = 0;
		while (tile_x < MINIMAP_TILE_SIZE)
			mlx_put_pixel(game->foreground,
				MINIMAP_OFFSET + MINIMAP_FRAME_WIDTH + x + tile_x++,
				MINIMAP_OFFSET + MINIMAP_FRAME_WIDTH + y + tile_y, color);
		tile_y++;
	}
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < MINIMAP_TILE_AMOUNT)
	{
		y = 0;
		while (y < MINIMAP_TILE_AMOUNT)
		{
			if (game->map.map[y][x] == WALL)
				draw_tile(game, MINIMAP_TILE_SIZE * y,
					MINIMAP_TILE_SIZE * x, MINIMAP_WALL_COLOR);
			y++;
		}
		x++;
	}
}
// floor(game->player.pos.x) - (MINIMAP_TILE_AMOUNT + 1) / 2;
void	draw_minimap(t_game *game)
{
	draw_background(game);
	draw_frame(game);
	draw_map(game);
	// draw_player(game);
}
