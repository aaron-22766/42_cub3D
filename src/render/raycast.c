
#include "../../include/cub3D.h"

static uint32_t get_txt_pix_col(t_game *game, t_ray *ray)
{
	uint32_t	col;

	col = TILE_SIZE / 2;
	if (game->wall_textures[SOUTH] == ray->texture)
		col = TILE_SIZE - (ray->hit.x % TILE_SIZE);
	else if (game->wall_textures[NORTH] == ray->texture)
		col = ray->hit.x % TILE_SIZE;
	else if (game->wall_textures[EAST] == ray->texture)
		col = TILE_SIZE - (ray->hit.y % TILE_SIZE);
	else if (game->wall_textures[WEST] == ray->texture)
		col = ray->hit.y % TILE_SIZE;
	return (col % ray->texture->width);
}

// static void set_txt_pix_row(t_ray *ray, t_pixel *img)
// {
// 	if (ray->angle > 0 && ray->angle < M_PI)
// 		img->color = get_pixel_color(ray->texture, 32, col);
// 	else
// 		img->color = get_pixel_color(ray->texture, 32, TILE_SIZE - col);
// }


void	render_raycast(t_game *game, t_ray *ray)
{
	double  tile = (double) TILE_SIZE;
	double  iw_half = (double) WINDOW_WIDTH / 2.0;
	double  d_player_pp = iw_half / tan(game->player.fov / 2.0);
	double  d_player_wall = ray->length;
	double  h = tile * (d_player_pp / d_player_wall);

	u_int32_t a = fmax((WINDOW_HEIGHT - h) / 2.0, 0.0);
	u_int32_t b = fmin((WINDOW_HEIGHT + h) / 2.0, WINDOW_HEIGHT);
	t_pixel img;
	img.x = WINDOW_WIDTH - ray->id - 1;
	img.y = a;
	uint32_t col = get_txt_pix_col(game, ray);
	while (img.y < b)
	{
		// img.color = get_pixel_color(ray->texture, 32, (ray->hit.x + ray->hit.y) % TILE_SIZE);
		// ray->txt.y = (h / (double) (img.y - a)) * TILE_SIZE; // (h / (img.y - a)) * TILE_SIZE;
		uint32_t row = ((double) (img.y - a) * ray->texture->height) / h;
		row = row % ray->texture->height;
		img.color = get_pixel_color(ray->texture, col, row);		
		mlx_put_pixel(game->image, img.x, img.y, img.color);
		img.y++;
	}
	// print_pixel_hex(img.color);	// Debug
	// printf("ray->texture->height: %d\n", ray->texture->height);	// Debug
	// printf("ray->texture->width: %d\n", ray->texture->width);	// Debug
}
