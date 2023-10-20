
#include "../../include/cub3D.h"

void	render_background(t_game *game)
{
	uint32_t	row;
	uint32_t	col;
	uint32_t	colour;

	mlx_delete_image(game->mlx, game->image);
	game->image = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	// y = 0;
	// while (y < game->image->height)
	// {
	// 	x = 0;
	// 	while (x < WINDOW_WIDTH)
	// 	{
	// 		if (y < WINDOW_HEIGHT / 2)
	// 			mlx_put_pixel(game->image, x, y, game->ceiling_color);
	// 		else
	// 			mlx_put_pixel(game->image, x, y, game->floor_color);
	// 		x++;
	// 	}
	// 	y++;
	// }
	row = 0;
	while (row < game->image->height)
	{
		if (row < game->image->height / 2)
			colour = game->ceiling_color;
		else
			colour = game->floor_color;
		col = 0;
		while (col < game->image->width)
		{
			mlx_put_pixel(game->image, col, row, colour);
			col++;
		}
		row++;
	}
}
