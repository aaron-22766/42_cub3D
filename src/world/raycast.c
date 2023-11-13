
#include "../../include/cub3D.h"

static uint32_t get_txt_pix_col(t_game *game, t_ray *ray)
{
	uint32_t	col;

	col = ray->texture->width / 2;
	if (game->wall_textures[SOUTH] == ray->texture)
		col = ray->texture->width - (uint32_t) (ray->hit.x % ray->texture->width);
	else if (game->wall_textures[NORTH] == ray->texture)
		col = ray->hit.x % ray->texture->width;
	else if (game->wall_textures[EAST] == ray->texture)
		col = ray->texture->width - (uint32_t) (ray->hit.y % ray->texture->width);
	else if (game->wall_textures[WEST] == ray->texture)
		col = ray->hit.y % ray->texture->width;
	return (col % ray->texture->width);
}

void	render_raycast(t_game *game, t_ray *ray)
{
	t_pixel	img;
	double	tile = (double) ray->texture->width;
	double	iw_half = (double) game->world.image->width / 2.0;
	double	d_player_pp = iw_half / tan(game->player.fov / 2.0);
	double	d_player_wall = ray->length;
	double	h = tile * (d_player_pp / d_player_wall);

	u_int32_t	a = fmax((game->world.image->height - h) / 2.0, 0.0);
	u_int32_t	b = fmin((game->world.image->height + h) / 2.0, game->world.image->height);
	img.x = game->world.image->width - ray->id - 1;
	img.y = a;
	uint32_t	col = get_txt_pix_col(game, ray);
	uint32_t	row = 0;
	while (img.y < b)
	{
		row = ((double) (img.y - a) * ray->texture->height) / h;
		row = row % ray->texture->height;
		img.color = get_pixel_txt(ray->texture, col, row);		
		mlx_put_pixel(game->world.image, img.x, img.y, img.color);
		img.y++;
	}
	// if (ray->id % game->world.image->width == 0) printf("col: %d, row: %d\n", col, row); //DEBUG
}
