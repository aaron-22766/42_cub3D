#include "../../include/cub3D.h"

void	draw_background(t_game *game)
{
	size_t	img_row;
	size_t	img_col;

	img_row = 0;
	while (img_row < game->world.image->height / 2)
	{
		img_col = 0;
		while (img_col < game->world.image->width)
			mlx_put_pixel(game->world.image,
				img_col++, img_row, game->ceiling_color);
		img_row++;
	}
	while (img_row < game->world.image->height)
	{
		img_col = 0;
		while (img_col < game->world.image->width)
			mlx_put_pixel(game->world.image,
				img_col++, img_row, game->floor_color);
		img_row++;
	}
}
