#include "../../include/cub3D.h"

static uint32_t	avrg_color_edge(t_game *game, uint32_t c_x, uint32_t c_y)
{
	t_rgb		**t;
	t_limits	x;
	t_limits	y;

	x.min = 0;
	y.min = 0;
	x.max = game->pause_screen->width - 1;
	y.max = game->pause_screen->height - 1;
	if (c_x > BLUR_RADIUS)
		x.min = c_x - BLUR_RADIUS;
	if (c_x < game->pause_screen->width - BLUR_RADIUS)
		x.max = c_x + BLUR_RADIUS;
	if (c_y > BLUR_RADIUS)
		y.min = c_y - BLUR_RADIUS;
	if (c_y < game->pause_screen->height - BLUR_RADIUS)
		y.max = c_y + BLUR_RADIUS;
	t = game->blur_table;
	return (get_color((t[y.max][x.max].r - t[y.min][x.max].r
		- t[y.max][x.min].r + t[y.min][x.min].r) / game->blur_area,
		(t[y.max][x.max].g - t[y.min][x.max].g
		- t[y.max][x.min].g + t[y.min][x.min].g) / game->blur_area,
		(t[y.max][x.max].b - t[y.min][x.max].b
		- t[y.max][x.min].b + t[y.min][x.min].b) / game->blur_area, 0xFF));
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

static void	put_row(t_game *game, t_limits x, uint32_t y,
	uint32_t (*f)(t_game *, uint32_t, uint32_t))
{
	while (x.min < x.max)
	{
		mlx_put_pixel(game->pause_screen, x.min, y, f(game, x.min, y));
		x.min++;
	}
}

static void	generate_blur(t_game *game)
{
	t_limits	x;
	t_limits	y;

	x.min = 0;
	x.max = game->pause_screen->width;
	y.min = 0;
	while (y.min < BLUR_RADIUS)
		put_row(game, x, y.min++, avrg_color_edge);
	y.max = game->pause_screen->height - BLUR_RADIUS;
	while (y.min < y.max)
	{
		x.min = 0;
		x.max = BLUR_RADIUS;
		put_row(game, x, y.min, avrg_color_edge);
		x.min = x.max;
		x.max = game->pause_screen->width - BLUR_RADIUS;
		put_row(game, x, y.min, avrg_color);
		x.min = x.max;
		x.max = game->pause_screen->width;
		put_row(game, x, y.min++, avrg_color_edge);
	}
	x.min = 0;
	x.max = game->pause_screen->width;
	while (y.min < game->pause_screen->height)
		put_row(game, x, y.min++, avrg_color_edge);
}

bool	render_blur(t_game *game)
{
	uint32_t	i;

	game->blur_table = ft_calloc(game->pause_screen->height + 1,
			sizeof(t_rgb *));
	if (!game->blur_table)
		return (false);
	i = 0;
	while (i < game->pause_screen->height)
	{
		game->blur_table[i] = ft_calloc(game->pause_screen->width,
				sizeof(t_rgb));
		if (!game->blur_table[i++])
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
