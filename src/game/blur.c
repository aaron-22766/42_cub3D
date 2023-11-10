#include "../../include/cub3D.h"

#define BLUR_RADIUS 15
#define BLUR_AREA ((BLUR_RADIUS * 2 + 1) * (BLUR_RADIUS * 2 + 1))

typedef struct s_rgb
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
}	t_rgb;

static void	sum_rgb(t_rgb **sum_table, uint32_t x, uint32_t y)
{
	sum_table[y][x].r += sum_table[y - 1][x].r + sum_table[y][x - 1].r
		- sum_table[y - 1][x - 1].r;
	sum_table[y][x].g += sum_table[y - 1][x].g + sum_table[y][x - 1].g
		- sum_table[y - 1][x - 1].g;
	sum_table[y][x].b += sum_table[y - 1][x].b + sum_table[y][x - 1].b
		- sum_table[y - 1][x - 1].b;
}

static void	get_rgb(t_game *game, t_rgb *set, uint32_t x, uint32_t y)
{
	uint32_t	base;
	uint32_t	top;
	uint8_t		a_top;
	uint8_t		a_base;

	base = get_pixel_img(game->image, x, y);
	top = get_pixel_img(game->hud.image, x, y);
	a_top = top & 0xFF;
	a_base = 0xFF - a_top;
	set->r = (red(top) * a_top + red(base) * a_base) / 0xFF;
	set->g = (green(top) * a_top + green(base) * a_base) / 0xFF;
	set->b = (blue(top) * a_top + blue(base) * a_base) / 0xFF;
}

static void	make_sum_table(t_game *game, t_rgb **sum_table)
{
	uint32_t	height;
	uint32_t	width;
	uint32_t	x;
	uint32_t	y;

	height = game->pause_screen->height + BLUR_RADIUS;
	width = game->pause_screen->width + BLUR_RADIUS;
	y = BLUR_RADIUS - 1;
	while (++y < height)
	{
		x = BLUR_RADIUS - 1;
		while (++x < width)
		{
			get_rgb(game, &sum_table[y][x], x - BLUR_RADIUS, y - BLUR_RADIUS);
			sum_rgb(sum_table, x, y);
		}
	}
}

static uint32_t	avrg_color(t_rgb **sum_table, uint32_t x, uint32_t y)
{
	uint32_t	x_min;
	uint32_t	y_min;

	x_min = x - BLUR_RADIUS;
	y_min = y - BLUR_RADIUS;
	return (get_color((sum_table[y][x].r - sum_table[y_min][x].r
		- sum_table[y][x_min].r + sum_table[y_min][x_min].r) / BLUR_AREA,
		(sum_table[y][x].g - sum_table[y_min][x].g
		- sum_table[y][x_min].g + sum_table[y_min][x_min].g) / BLUR_AREA,
		(sum_table[y][x].b - sum_table[y_min][x].b
		- sum_table[y][x_min].b + sum_table[y_min][x_min].b) / BLUR_AREA,
		0xFF));
}

static void	generate_blur(t_game *game, t_rgb **sum_table)
{
	uint32_t	height;
	uint32_t	width;
	uint32_t	x;
	uint32_t	y;

	height = game->pause_screen->height + BLUR_RADIUS;
	width = game->pause_screen->width + BLUR_RADIUS;
	y = BLUR_RADIUS - 1;
	while (++y < height)
	{
		x = BLUR_RADIUS - 1;
		while (++x < width)
			mlx_put_pixel(game->pause_screen, x - BLUR_RADIUS,
				y - BLUR_RADIUS, avrg_color(sum_table, x, y));
	}
}

bool	render_blur(t_game *game)
{
	t_rgb		**sum_table;
	uint32_t	height;
	uint32_t	width;
	uint32_t	y;

	height = game->pause_screen->height + 2 * BLUR_RADIUS;
	width = game->pause_screen->width + 2 * BLUR_RADIUS;
	sum_table = ft_calloc(height + 1, sizeof(t_rgb *));
	if (!sum_table)
		return (false);
	y = 0;
	while (y < height)
	{
		sum_table[y] = ft_calloc(width, sizeof(t_rgb));
		if (!sum_table[y])
			return (ft_free_2d_array((void **)sum_table), false);
		y++;
	}
	make_sum_table(game, sum_table);
	generate_blur(game, sum_table);
	return (ft_free_2d_array((void **)sum_table), true);
}
