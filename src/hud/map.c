#include "../../include/cub3D.h"

static void	put_pixel(t_hud *hud, uint32_t x, uint32_t y, uint32_t color)
{
	if (y < hud->minimap_start || y > hud->minimap_end
		|| x < hud->minimap_start || x > hud->minimap_end)
		return ;
	mlx_put_pixel(hud->image, x, y, color);
}

static void	draw_plus(t_hud *hud, uint32_t x, uint32_t y, uint32_t color)
{
	put_pixel(hud, x, y, color);
	put_pixel(hud, x + 1, y, color);
	put_pixel(hud, x - 1, y, color);
	put_pixel(hud, x, y + 1, color);
	put_pixel(hud, x, y - 1, color);
}

uint32_t	rotate(t_game *game, int a, int b)
{
	return (a * sin(fmod(game->player.orientation, M_PI_2))
		+ b * cos(fmod(game->player.orientation, M_PI_2)));
}

static void	draw_square(t_game *game, uint32_t x, uint32_t y, uint32_t color)
{
	int	i;
	int	j;
	
	i = -game->hud.minimap_half_tile_size;
	while (++i < game->hud.minimap_half_tile_size)
	{
		j = -game->hud.minimap_half_tile_size;
		while (++j < game->hud.minimap_half_tile_size)
			draw_plus(&game->hud, x + rotate(game, j, -i),
				y + rotate(game, i, j), color);
	}
}

void draw_tile(t_game *game, size_t x, size_t y, uint32_t color)
{
	double		rel_x;
	double		rel_y;
	uint32_t	pixel_x;
	uint32_t	pixel_y;
	
	rel_x = x * MINIMAP_TILE_SIZE - game->player.pos.x * MINIMAP_TILE_SIZE
		+ game->hud.minimap_half_tile_size;
	rel_y = y * MINIMAP_TILE_SIZE - game->player.pos.y * MINIMAP_TILE_SIZE
		+ game->hud.minimap_half_tile_size;
	pixel_x = game->hud.minimap_center + rel_x;
	pixel_y = game->hud.minimap_center - rel_y;
	draw_square(game, pixel_x, pixel_y, color);
}

void	draw_doors(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (game->fix_map.map[y])
	{
		x = 0;
		while (game->fix_map.map[y][x])
		{
			if (game->fix_map.map[y][x] == DOOR)
			{
				if (game->flex_map.map[y][x] == PATH)
					draw_tile(game, x, y, MINIMAP_DOOR_OPEN_COLOR);
				else
					draw_tile(game, x, y, MINIMAP_DOOR_CLOSED_COLOR);
			}
			x++;
		}
		y++;
	}
}

void	draw_walls(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (game->fix_map.map[y])
	{
		x = 0;
		while (game->fix_map.map[y][x])
		{
			if (game->fix_map.map[y][x] == WALL)
				draw_tile(game, x, y, MINIMAP_WALL_COLOR);
			x++;
		}
		y++;
	}
}
