#include "../../include/cub3D.h"

static void	draw_torch(t_hud *hud, mlx_texture_t *torch)
{
	uint32_t	x;
	uint32_t	y;

	y = 0;
	while (y < torch->height && hud->torch_pos.y + y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < torch->width && hud->torch_pos.x + x < WINDOW_WIDTH)
		{
			mlx_put_pixel(hud->image, hud->torch_pos.x + x,
				hud->torch_pos.y + y, get_pixel_color(torch, x, y));
			x++;
		}
		y++;
	}
}

void	animate_torch(t_game *game)
{
	static double	time;
	static uint8_t	frame;

	time += game->mlx->delta_time;
	if (time > TORCH_SPEED)
	{
		time = 0;
		frame = (frame + 1) % TORCH_AMOUNT;
	}
	draw_torch(&game->hud, game->hud.torch_texture[frame]);
}
