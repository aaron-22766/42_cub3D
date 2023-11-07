#include "../../include/cub3D.h"

static void	set_limits(t_limits *limits, double axis, uint32_t apex,
	uint32_t nb_tiles)
{
	limits->min = fmax(axis - nb_tiles - 1.7, 0);
	limits->max = fmin(axis + nb_tiles + 1.7, apex);
}

void	draw_doors(t_game *game)
{
	uint32_t	x_iter;
	t_limits	x;
	t_limits	y;

	set_limits(&x, game->player.pos.x, game->fix_map.max_width, game->nb_tiles);
	set_limits(&y, game->player.pos.y, game->fix_map.height, game->nb_tiles);
	while (y.min < y.max)
	{
		x_iter = x.min;
		while (x_iter < x.max)
		{
			if (game->fix_map.map[y.min][x_iter] == DOOR)
			{
				if (game->flex_map.map[y.min][x_iter] == PATH)
					draw_tile(game, x_iter, y.min, MINIMAP_DOOR_OPEN_COLOR);
				else
					draw_tile(game, x_iter, y.min, MINIMAP_DOOR_CLOSED_COLOR);
			}
			x_iter++;
		}
		y.min++;
	}
}

void	draw_walls(t_game *game)
{
	uint32_t	x_iter;
	t_limits	x;
	t_limits	y;

	set_limits(&x, game->player.pos.x, game->fix_map.max_width, game->nb_tiles);
	set_limits(&y, game->player.pos.y, game->fix_map.height, game->nb_tiles);
	while (y.min < y.max)
	{
		x_iter = x.min;
		while (x_iter < x.max)
		{
			if (game->fix_map.map[y.min][x_iter] == WALL)
				draw_tile(game, x_iter, y.min, MINIMAP_WALL_COLOR);
			x_iter++;
		}
		y.min++;
	}
}
