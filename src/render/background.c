
#include "../../include/cub3D.h"

void	render_background(t_game *game)
{
	uint32_t	img_row;
	uint32_t	img_col;
	uint32_t	color;

	img_row = 0;
	while (img_row < game->image->height)
	{
		img_col = 0;
		if (img_row < game->image->height / 2)
			color = game->ceiling_color;
		else
			color = game->floor_color;
		while (img_col < game->image->width)
		{
			mlx_put_pixel(game->image, img_col, img_row, color);
			img_col++;
		}
		img_row++;
	}

	// Minimap
	int m = 16;
	int n = 128;
	int i = 0;
	while (i < n) {
		int j = 0;
		while (j < n) {
			int i2 = 0;
			while (i2 < m) {
				int j2 = 0;
				while (j2 < m) {
					if (((i/m) + (j/m)) % 2 == 0)
						mlx_put_pixel(game->image, i + i2, j + j2, get_color(0, 255, 0, 128));
					else
						mlx_put_pixel(game->image, i + i2, j + j2, get_color(0, 0, 255, 128));
					j2++;
				}
				i2++;
			}
			j += m;
		}
		i += m;
	}
	
}
