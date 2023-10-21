
#include "../../include/cub3D.h"

void	render_background(t_game *game)
{
	uint32_t	row;
	uint32_t	col;
	uint32_t	colour;

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
