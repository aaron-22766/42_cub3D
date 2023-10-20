
#include "../../include/cub3D.h"

void	render_background(t_game *game)
{
	uint32_t	x;
	uint32_t	y;

	mlx_delete_image(game->mlx, game->image);
	game->image = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			if (y < WINDOW_HEIGHT / 2)
				mlx_put_pixel(game->image, x, y, game->ceiling_color);
			else
				mlx_put_pixel(game->image, x, y, game->floor_color);
			x++;
		}
		y++;
	}
}
