
#include "../../include/cub3D.h"

void	render_background(t_game *game)
{
	uint32_t	x;
	uint32_t	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(game->image, x, y, game->ceiling_color);
			else
				mlx_put_pixel(game->image, x, y, game->floor_color);
			x++;
		}
		y++;
	}
}
