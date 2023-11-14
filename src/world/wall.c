#include "../../include/cub3D.h"

static double	get_projection_height(t_game *game, t_ray *ray)
{
	double	tile;
	double	d_player_pp;
	double	d_player_wall;
	double	omega;

	tile = (double) ray->texture->width;
	d_player_wall = ray->length;
	d_player_pp = tile * game->world.distance;
	omega = fabs(ray->angle + 2.0 * M_PI
			- (game->world.theta + game->world.fov_2));
	if (cos(omega) != 0)
		d_player_pp = d_player_pp / cos(omega);
	return (d_player_pp / d_player_wall);
}

static uint32_t	get_txt_slice(t_ray *ray)
{
	uint32_t	tile;

	tile = ray->texture->width;
	if (ray->txt_id == NORTH || ray->txt_id == SOUTH)
		return (tile - (((uint32_t)ray->hit.y) % tile));
	else if (ray->txt_id == EAST || ray->txt_id == WEST)
		return (((uint32_t)ray->hit.x) % tile);
	else if (ray->length == ray->hor_length)
		return (((uint32_t)ray->hit.x) % tile);
	return (tile - (((uint32_t)ray->hit.y) % tile));
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
	col = get_txt_slice(ray);
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
