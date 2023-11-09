#include "../../include/cub3D.h"

static void	draw_torch(t_game *game, mlx_texture_t *torch)
{
	uint32_t	x;
	uint32_t	y;

	y = 0;
	while (y < torch->height
		&& game->hud.torch_pos.y + y < game->hud.image->height)
	{
		x = 0;
		while (x < torch->width
			&& game->hud.torch_pos.x + x < game->hud.image->width)
		{
			mlx_put_pixel(game->hud.image, game->hud.torch_pos.x + x,
				game->hud.torch_pos.y + y, get_pixel_txt(torch, x, y));
			x++;
		}
		y++;
	}
}

void	animate_torch(t_game *game, bool force)
{
	game->hud.torch_time += game->mlx->delta_time;
	if (force || game->hud.torch_time > game->hud.torch_speed)
	{
		game->hud.torch_time = 0;
		draw_torch(game, game->hud.torch_textures[game->hud.torch_frame]);
		game->hud.torch_frame = (game->hud.torch_frame + 1) % TORCH_AMOUNT;
	}
}
