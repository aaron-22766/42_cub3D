#include "../../include/cub3D.h"

void	draw_torch(t_game *game, mlx_texture_t *torch)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	color;

	y = 0;
	while (y < torch->height && TORCH_Y + y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < torch->width && TORCH_X + x < WINDOW_WIDTH)
		{
			color = get_pixel_color(torch, x, y);
			if ((color & 0xFF) > 50)
				mlx_put_pixel(game->image, TORCH_X + x, TORCH_Y + y, color);
			x++;
		}
		y++;
	}
}

void	draw_foreground(t_game *game)
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
