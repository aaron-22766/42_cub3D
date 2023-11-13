#include "../../include/cub3D.h"

void	set_rgb(t_game *game, t_rgb *set, uint32_t x, uint32_t y)
{
	uint32_t	base;
	uint32_t	top;
	uint8_t		a_top;
	uint8_t		a_base;

	base = get_pixel_img(game->image, x, y);
	top = get_pixel_img(game->hud.image, x, y);
	a_top = top & 0xFF;
	a_base = 0xFF - a_top;
	set->r = (red(top) * a_top + red(base) * a_base) / 0xFF * BLUR_DARKEN;
	set->g = (green(top) * a_top + green(base) * a_base) / 0xFF * BLUR_DARKEN;
	set->b = (blue(top) * a_top + blue(base) * a_base) / 0xFF * BLUR_DARKEN;
}

void	sum_rgb_x(t_rgb **t, uint32_t x, uint32_t y)
{
	(void)y;
	t[0][x].r += t[0][x - 1].r;
	t[0][x].g += t[0][x - 1].g;
	t[0][x].b += t[0][x - 1].b;
}

void	sum_rgb_y(t_rgb **t, uint32_t y)
{
	t[y][0].r += t[y - 1][0].r;
	t[y][0].g += t[y - 1][0].g;
	t[y][0].b += t[y - 1][0].b;
}

void	sum_rgb(t_rgb **t, uint32_t x, uint32_t y)
{
	t[y][x].r += t[y - 1][x].r + t[y][x - 1].r - t[y - 1][x - 1].r;
	t[y][x].g += t[y - 1][x].g + t[y][x - 1].g - t[y - 1][x - 1].g;
	t[y][x].b += t[y - 1][x].b + t[y][x - 1].b - t[y - 1][x - 1].b;
}

void	set_row(t_game *game, uint32_t y, t_pixel i,
	void (*f)(t_rgb **t, uint32_t x, uint32_t y))
{
	t_limits	x;

	i.x = 0;
	x.min = 0;
	while (++x.min < BLUR_RADIUS)
	{
		set_rgb(game, &game->blur_table[y][x.min], i.x, i.y);
		f(game->blur_table, x.min, y);
	}
	x.max = game->pause_screen->width + BLUR_RADIUS;
	while (x.min < x.max)
	{
		set_rgb(game, &game->blur_table[y][x.min], i.x++, i.y);
		f(game->blur_table, x.min++, y);
	}
	i.x--;
	x.max = game->pause_screen->width + 2 * BLUR_RADIUS;
	while (x.min < x.max)
	{
		set_rgb(game, &game->blur_table[y][x.min], i.x, i.y);
		f(game->blur_table, x.min++, y);
	}
}
