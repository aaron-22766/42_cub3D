#include "../../include/cub3D.h"

#define BLUR_RADIUS 1

static uint32_t	get_center_color(t_game *game, t_pixel c)
{
	uint32_t	kernel[BLUR_RADIUS * 2 + 1][BLUR_RADIUS * 2 + 1];
	uint32_t	kernel_area;
	uint32_t	rgb[3];
	t_vector	k;

	k.y = -BLUR_RADIUS;
	while (k.y < BLUR_RADIUS * 2)
	{
		k.x = -BLUR_RADIUS;
		while (k.x < BLUR_RADIUS * 2)
		{
			kernel[k.y + BLUR_RADIUS][k.x + BLUR_RADIUS]
				= get_pixel_img(game->image, c.x + k.x, c.y + k.y);
			k.x++;
		}
		k.y++;
	}
	ft_memset(&rgb, 0, 3 * sizeof(uint32_t));
	k.y = 0;
	while (k.y <= BLUR_RADIUS * 2)
	{
		k.x = 0;
		while (k.x <= BLUR_RADIUS * 2)
		{
			rgb[0] += kernel[k.y][k.x] >> 24;
			rgb[1] += kernel[k.y][k.x] >> 16;
			rgb[2] += kernel[k.y][k.x] >> 8;
			k.x++;
		}
		k.y++;
	}
	kernel_area = ft_pow(2 * BLUR_RADIUS + 1, 2);
	return (get_color(rgb[0] / kernel_area, rgb[1] / kernel_area,
		rgb[2] / kernel_area, 0xFF));
}

static void	create_blur(t_game *game)
{
	t_pixel	c;

	c.y = BLUR_RADIUS - 1;
	while (++c.y <= game->pause_screen->height - BLUR_RADIUS)
	{
		c.x = BLUR_RADIUS - 1;
		while (++c.x <= game->pause_screen->width - BLUR_RADIUS)
		{
			mlx_put_pixel(game->pause_screen, c.x, c.y,
				get_center_color(game, c));
		}
	}
}

void	render_pause_screen(t_game *game)
{
	if (game->paused)
	{
		create_blur(game);
		game->pause_screen->enabled = true;
		game->pause_text = mlx_put_string(game->mlx, "Press P to play",
				game->pause_screen->width / 2 - 75,
				game->pause_screen->height / 2 - 10);
		mlx_set_instance_depth(game->pause_text->instances, 4);
	}
	else
	{
		game->pause_screen->enabled = false;
		delete_image(game->mlx, game->pause_text);
	}
}

void	pause_key(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int32_t	temp_mouse_y;

	if (keydata.action != MLX_PRESS || keydata.key != MLX_KEY_P)
		return ;
	game = param;
	game->paused = !game->paused;
	if (game->paused)
		mlx_set_cursor_mode(game->mlx, MLX_MOUSE_NORMAL);
	else
	{
		mlx_set_cursor_mode(game->mlx, MLX_MOUSE_DISABLED);
		mlx_get_mouse_pos(game->mlx, &game->mouse_x, &temp_mouse_y);
	}
	render_pause_screen(game);
}
