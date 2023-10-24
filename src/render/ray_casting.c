
#include "../../include/cub3D.h"

static void	set_projection_values(t_game *game, t_render *render, t_ray *ray)
{
	double	dx;
	double	dy;

	dx = cos(ray->angle);
	dy = sin(ray->angle);
	while (game->map.map[(int)ray->pos.y][(int)ray->pos.x] != '1')
	{
		ray->pos.x += dx;
		ray->pos.y += dy;
	}
	ray->distance = sqrt(pow(render->pos.x - ray->pos.x, 2) + pow(render->pos.y - ray->pos.y, 2));
	ray->pw_height = TEXTURE_HEIGHT / ray->distance * (double) game->image->height;
	ray->pw_width = TEXTURE_WIDTH / ray->distance * (double) game->image->width;
	ray->pw_top = ((double)game->image->height - ray->pw_height) / 2;
	ray->pw_bottom = ((double)game->image->height + ray->pw_height) / 2;
}

static mlx_texture_t	*get_texture(t_game *game, t_render *render, t_ray *ray)
{
	if (fabs(ray->pos.x - (int)ray->pos.x) < fabs(ray->pos.y - (int)ray->pos.y))
	{
		if (ray->angle > 0 && ray->angle < M_PI)
			return (game->no_texture);
		else
			return (game->so_texture);
	}
	else
	{
		if (ray->angle > M_PI / 2 && ray->angle < 3 * M_PI / 2)
			return (game->we_texture);
		else
			return (game->ea_texture);
	}	
}

/**
 * @brief 
 * 
 * @param game 
 * @param render 
 * @param ray 
 */

void    cast_single_ray(t_game *game, t_render *render, t_ray *ray)
{
	int		color;
	int32_t	img_col;
	int32_t	img_row;
	int 	p_x;
	int		p_y;

	set_projection_values(game, render, ray);
	ray->texture = get_texture(game, render, ray);
	img_col = ray->pw_top;
	img_row = render->ray_index;
	p_y = (img_row - 0) * TEXTURE_WIDTH / ray->pw_width; // todo
	while (img_col < ray->pw_bottom)
	{
		p_x = (img_col - ray->pw_top) * TEXTURE_HEIGHT / ray->pw_height;
		color = get_pixel_color(ray->texture, p_x, p_y);
		mlx_put_pixel(game->image, img_col, img_row, color);
		img_col++;
	}
}

// TODO: Check if the x corresponds to the column and the y to the row
