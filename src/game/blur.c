#include "../../include/cub3D.h"

static void	set_first_column(t_game *game)
{
	t_limits	y;
	uint32_t	i_y;

	i_y = 0;
	y.min = 0;
	while (++y.min < BLUR_RADIUS)
	{
		set_rgb(game, &game->blur_table[y.min][0], 0, i_y);
		sum_rgb_y(game->blur_table, y.min);
	}
	y.max = game->pause_screen->height + BLUR_RADIUS;
	while (y.min < y.max)
	{
		set_rgb(game, &game->blur_table[y.min][0], 0, i_y++);
		sum_rgb_y(game->blur_table, y.min++);
	}
	i_y--;
	y.max = game->pause_screen->height + 2 * BLUR_RADIUS;
	while (y.min < y.max)
	{
		set_rgb(game, &game->blur_table[y.min][0], 0, i_y);
		sum_rgb_y(game->blur_table, y.min++);
	}
}

static void	make_table(t_game *game)
{
	t_limits	y;
	t_pixel		i;

	set_rgb(game, &game->blur_table[0][0], 0, 0);
	i.y = 0;
	set_row(game, 0, i, sum_rgb_x);
	set_first_column(game);
	y.min = 0;
	while (++y.min < BLUR_RADIUS)
		set_row(game, y.min, i, sum_rgb);
	y.max = game->pause_screen->height + BLUR_RADIUS;
	while (y.min < y.max)
	{
		set_row(game, y.min++, i, sum_rgb);
		i.y++;
	}
	i.y--;
	y.max = game->pause_screen->height + 2 * BLUR_RADIUS;
	while (y.min < y.max)
		set_row(game, y.min++, i, sum_rgb);
}

static uint32_t	avrg_color(t_game *game, uint32_t c_x, uint32_t c_y)
{
	t_rgb		**t;
	t_limits	x;
	t_limits	y;

	x.min = c_x - BLUR_RADIUS;
	x.max = c_x + BLUR_RADIUS;
	y.min = c_y - BLUR_RADIUS;
	y.max = c_y + BLUR_RADIUS;
	t = game->blur_table;
	return (get_color((t[y.max][x.max].r - t[y.min][x.max].r
		- t[y.max][x.min].r + t[y.min][x.min].r) / game->blur_area,
		(t[y.max][x.max].g - t[y.min][x.max].g
		- t[y.max][x.min].g + t[y.min][x.min].g) / game->blur_area,
		(t[y.max][x.max].b - t[y.min][x.max].b
		- t[y.max][x.min].b + t[y.min][x.min].b) / game->blur_area, 0xFF));
}

static void	generate_blur(t_game *game)
{
	t_limits	x;
	t_limits	y;
	uint32_t	i;

	x.min = BLUR_RADIUS - 1;
	x.max = game->pause_screen->width + BLUR_RADIUS;
	y.min = BLUR_RADIUS - 1;
	y.max = game->pause_screen->height + BLUR_RADIUS;
	while (++y.min < y.max)
	{
		i = x.min;
		while (++i < x.max)
			mlx_put_pixel(game->pause_screen, i - BLUR_RADIUS,
				y.min - BLUR_RADIUS, avrg_color(game, i, y.min));
	}
}

bool	render_blur(t_game *game)
{
	t_limits	y;
	uint32_t	width;

	y.max = game->pause_screen->height + 2 * BLUR_RADIUS;
	width = game->pause_screen->width + 2 * BLUR_RADIUS;
	game->blur_table = ft_calloc(y.max + 1, sizeof(t_rgb *));
	if (!game->blur_table)
		return (false);
	y.min = 0;
	while (y.min < y.max)
	{
		game->blur_table[y.min] = ft_calloc(width, sizeof(t_rgb));
		if (!game->blur_table[y.min++])
		{
			ft_free_2d_array((void **)game->blur_table);
			game->blur_table = NULL;
			return (false);
		}
	}
	make_table(game);
	generate_blur(game);
	ft_free_2d_array((void **)game->blur_table);
	game->blur_table = NULL;
	return (true);
}
