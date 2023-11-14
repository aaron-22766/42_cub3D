#include "../../include/cub3D.h"

static double	get_projection_height(t_game *game, t_ray *ray)
{
	double	tile;
	double	iw_half;
	double	d_player_pp;
	double	d_player_wall;

	tile = (double) ray->texture->width;
	iw_half = (double) game->world.image->width / 2.0;
	d_player_pp = iw_half / tan(game->world.fov_2);
	d_player_wall = ray->length;
	return ((tile * d_player_pp) / d_player_wall);
}

static uint32_t	get_txt_pix_col(t_game *game, t_ray *ray)
{
	uint32_t	col;

	col = ray->texture->width / 2;
	if (game->wall_textures[SOUTH] == ray->texture)
		col = ray->texture->width - (ray->hit.x % ray->texture->width);
	else if (game->wall_textures[NORTH] == ray->texture)
		col = ray->hit.x % ray->texture->width;
	else if (game->wall_textures[EAST] == ray->texture)
		col = ray->texture->width - (ray->hit.y % ray->texture->width);
	else if (game->wall_textures[WEST] == ray->texture)
		col = ray->hit.y % ray->texture->width;
	return (col % ray->texture->width);
}

void	draw_wall_slice(t_game *game, t_ray *ray)
{
	double		p_h;
	double		p_w_start;
	double		p_w_ends;
	u_int32_t	col;
	u_int32_t	row;

	p_h = get_projection_height(game, ray);
	p_w_start = (game->world.image->height - p_h) / 2.0;
	p_w_ends = (game->world.image->height + p_h) / 2.0;
	ray->img.x = game->world.image->width - ray->id - 1;
	ray->img.y = fmax(p_w_start, 0.0);
	col = get_txt_pix_col(game, ray);
	while (ray->img.y < game->world.image->height)
	{
		row = ((double)(ray->img.y - p_w_start) * (ray->texture->height)) / p_h;
		if (row >= 0 && row < ray->texture->height)
		{
			ray->img.color = get_pixel_txt(ray->texture, col, row);
			mlx_put_pixel(game->world.image, ray->img.x,
				ray->img.y, ray->img.color);
		}
		ray->img.y++;
	}
}
