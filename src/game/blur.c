#include "../../include/cub3D.h"

#define BLUR_RADIUS 5
#define BLUR_AREA ((BLUR_RADIUS * 2 + 1) * (BLUR_RADIUS * 2 + 1))
#define DARKEN 0.2

typedef struct s_kernel
{
	uint32_t	map[BLUR_RADIUS * 2 + 1][BLUR_RADIUS * 2 + 1];
}	t_kernel;

static uint32_t	combine_colors(t_game *game, t_pixel c, t_pixel k)
{
	uint32_t	base;
	uint32_t	top;
	uint8_t		a_top;
	uint8_t		a_base;

	base = get_pixel_img(game->image, c.x - BLUR_RADIUS + k.x,
		c.y - BLUR_RADIUS + k.y);
	top = get_pixel_img(game->hud.image, c.x - BLUR_RADIUS + k.x,
		c.y - BLUR_RADIUS + k.y);
	a_top = top & 0xFF;
	a_base = 0xFF - a_top;
	return (get_color((red(top) * a_top + red(base) * a_base) / 0xFF * DARKEN,
			(green(top) * a_top + green(base) * a_base) / 0xFF * DARKEN,
			(blue(top) * a_top + blue(base) * a_base) / 0xFF * DARKEN, 0xFF));
}

static void	shift_kernel_left(t_kernel *kernel)
{
	t_pixel	k;

	k.x = 0;
	while (k.x <= BLUR_RADIUS * 2)
	{
		k.y = 0;
		while (k.y <= BLUR_RADIUS * 2)
		{
			kernel->map[k.y][k.x] = kernel->map[k.y][k.x + 1];
			k.y++;
		}
		k.x++;
	}
}

static void	colors_to_kernel(t_game *game, t_pixel c, t_kernel *kernel)
{
	t_pixel	k;

	k.x = 0;
	if (c.x)
	{
		k.x = BLUR_RADIUS * 2;
		shift_kernel_left(kernel);
	}
	while (k.x <= BLUR_RADIUS * 2)
	{
		k.y = 0;
		while (k.y <= BLUR_RADIUS * 2)
		{
			kernel->map[k.y][k.x] = combine_colors(game, c, k);
			k.y++;
		}
		k.x++;
	}
}

static uint32_t	kernel_color(t_kernel *kernel)
{
	t_pixel		k;
	uint32_t	rgb[3];
	
	ft_memset(&rgb, 0, 3 * sizeof(uint32_t));
	k.y = 0;
	while (k.y <= BLUR_RADIUS * 2)
	{
		k.x = 0;
		while (k.x <= BLUR_RADIUS * 2)
		{
			rgb[0] += red(kernel->map[k.y][k.x]);
			rgb[1] += green(kernel->map[k.y][k.x]);
			rgb[2] += blue(kernel->map[k.y][k.x]);
			k.x++;
		}
		k.y++;
	}
	return (get_color(rgb[0] / BLUR_AREA, rgb[1] / BLUR_AREA,
			rgb[2] / BLUR_AREA, 0xFF));
}

void	create_blur(t_game *game)
{
	t_kernel	kernel;
	t_pixel		c;

	c.y = 0;
	while (c.y < game->pause_screen->height)
	{
		c.x = 0;
		while (c.x < game->pause_screen->width)
		{
			colors_to_kernel(game, c, &kernel);
			mlx_put_pixel(game->pause_screen, c.x, c.y, kernel_color(&kernel));
			c.x++;
		}
		c.y++;
	}
}
