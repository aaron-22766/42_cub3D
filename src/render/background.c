#include "../../include/render.h"

void	render_background(t_game *game)
{
	size_t	img_row;
	size_t	img_col;

	img_row = 0;
	while (img_row < game->image->height / 2)
	{
		img_col = 0;
		while (img_col < game->image->width)
			mlx_put_pixel(game->image, img_col++, img_row, game->ceiling_color);
		img_row++;
	}
	while (img_row < game->image->height)
	{
		img_col = 0;
		while (img_col < game->image->width)
			mlx_put_pixel(game->image, img_col++, img_row, game->floor_color);
		img_row++;
	}
}
