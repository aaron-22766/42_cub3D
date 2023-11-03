#include "../../include/cub3D.h"

static void	set_limits(size_t *min, size_t *max, double axis, size_t apex)
{
	*min = fmax(axis - MINIMAP_TILE_AMOUNT / 2 - 3.5, 0);
	*max = fmin(axis + MINIMAP_TILE_AMOUNT / 2 + 3.5, apex);
}

void	draw_doors(t_game *game)
{
	size_t	x;
	size_t	y;
	size_t	min_x;
	size_t	max_x;
	size_t	max_y;

	set_limits(&min_x, &max_x, game->player.pos.x, game->fix_map.max_width);
	set_limits(&y, &max_y, game->player.pos.y, game->fix_map.height);
	while (y < max_y)
	{
		x = min_x;
		while (x < max_x)
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
	size_t	min_x;
	size_t	max_x;
	size_t	max_y;

	set_limits(&min_x, &max_x, game->player.pos.x, game->fix_map.max_width);
	set_limits(&y, &max_y, game->player.pos.y, game->fix_map.height);
	while (y < max_y)
	{
		x = min_x;
		while (x < max_x)
		{
			if (game->fix_map.map[y][x] == WALL)
				draw_tile(game, x, y, MINIMAP_WALL_COLOR);
			x++;
		}
		y++;
	}
}
