
#include "../../include/cub3D.h"

void	render_raycast(t_game *game, t_ray *ray)
{
	double  tile = (double) TILE_SIZE;
	double  iw_half = (double) WINDOW_WIDTH / 2.0;
	double  d_player_pp = iw_half / tan(game->player.fov / 2.0);
	double  d_player_wall = ray->length;
	double  h = tile * (d_player_pp / d_player_wall);

	u_int32_t a = (WINDOW_HEIGHT - h) / 2.0;
	u_int32_t b = (WINDOW_HEIGHT + h) / 2.0;
	t_pixel pixel;
	pixel.x = WINDOW_WIDTH - ray->id - 1;
	pixel.y = a;
	pixel.color = get_pixel_color(ray->texture, 1, 1);
	while (pixel.y < b)
	{
		mlx_put_pixel(game->image, pixel.x, pixel.y, pixel.color);
		pixel.y++;
	}
}
