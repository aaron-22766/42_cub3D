#include "../../include/cub3D.h"

static void	set_rgb(t_game *game, t_rgb *set, uint32_t x, uint32_t y)
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

static void	sum_rgb_x(t_rgb **t, uint32_t x)
{
	t[0][x].r += t[0][x - 1].r;
	t[0][x].g += t[0][x - 1].g;
	t[0][x].b += t[0][x - 1].b;
}

static void	sum_rgb_y(t_rgb **t, uint32_t y)
{
	t[y][0].r += t[y - 1][0].r;
	t[y][0].g += t[y - 1][0].g;
	t[y][0].b += t[y - 1][0].b;
}

static void	sum_rgb(t_rgb **t, uint32_t x, uint32_t y)
{
	t[y][x].r += t[y - 1][x].r + t[y][x - 1].r - t[y - 1][x - 1].r;
	t[y][x].g += t[y - 1][x].g + t[y][x - 1].g - t[y - 1][x - 1].g;
	t[y][x].b += t[y - 1][x].b + t[y][x - 1].b - t[y - 1][x - 1].b;
}

void	make_table(t_game *game)
{
	uint32_t	x;
	uint32_t	y;

	y = 0;
	while (y < game->pause_screen->height)
	{
		x = 0;
		set_rgb(game, &game->blur_table[y][x], x, y);
		while (++x < game->pause_screen->width)
			set_rgb(game, &game->blur_table[y][x], x, y);
		y++;
	}
	x = 0;
	while (++x < game->pause_screen->width)
		sum_rgb_x(game->blur_table, x);
	y = 0;
	while (++y < game->pause_screen->height)
		sum_rgb_y(game->blur_table, y);
	y = 0;
	while (++y < game->pause_screen->height)
	{
		x = 0;
		while (++x < game->pause_screen->width)
			sum_rgb(game->blur_table, x, y);
	}
}
