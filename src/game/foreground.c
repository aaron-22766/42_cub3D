#include "../../include/cub3D.h"

static void	draw_torch(t_game *game, mlx_texture_t *torch)
{
	uint32_t	torch_y;
	uint32_t	x;
	uint32_t	y;

	torch_y = WINDOW_HEIGHT - torch->height;
	y = 0;
	while (y < torch->height && torch_y + y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < torch->width && TORCH_X + x < WINDOW_WIDTH)
		{
			mlx_put_pixel(game->foreground, TORCH_X + x, torch_y + y,
				get_pixel_color(torch, x, y));
			x++;
		}
		y++;
	}
}

static void	animate_torch(t_game *game)
{
	static double	time;
	static uint8_t	frame;

	time += game->mlx->delta_time;
	if (time > TORCH_SPEED)
	{
		time = 0;
		frame = (frame + 1) % TORCH_AMOUNT;
	}
	draw_torch(game, game->torch[frame]);
}

void	generate_foreground(t_game *game)
{
	animate_torch(game);
	draw_minimap(game);
}
