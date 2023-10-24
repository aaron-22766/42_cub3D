
#include "../../include/cub3D.h"

static void	set_projection_values(t_game *game, t_render *render, t_ray *ray)
{
	double	dx;
	double	dy;
	int		p_w;
	int		p_h;

	dx = cos(ray->angle);
	dy = sin(ray->angle);
	p_h = floor(ray->pos.x);
	p_w = floor(ray->pos.y);
	while (fmin(p_w, p_h) >= 0 && p_h < game->map.height && p_w < game->map.widths[p_w] &&
		(game->map.map[p_h][p_w] != '1' || game->map.map[p_h][p_w] != ' '))
	{
		ray->pos.x += dx;
		ray->pos.y += dy;
		p_h = floor(ray->pos.x);
		p_w = floor(ray->pos.y);
	}
	ray->pos.x -= dx;
	ray->pos.y -= dy;
	p_h = fmin(floor(ray->pos.x), game->map.height - 1);
	p_w = fmin(floor(ray->pos.y), game->map.widths[p_h] - 1);
	ray->distance = sqrt(pow((double)fabs(game->player.pos.x - ray->pos.x), 2.0) +
						pow((double)(game->player.pos.y - ray->pos.y), 2.0));
	ray->pw_height = (ray->distance / (double) TEXTURE_HEIGHT) * (double) WINDOW_HEIGHT;
	// ray->pw_width = (ray->distance / (double) TEXTURE_WIDTH) * (double) WINDOW_WIDTH; // game->image->width
	ray->pw_width = ray->pw_height;
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

void    render_raycast(t_game *game, t_render *render, t_ray *ray)
{
	uint32_t	color;
	static uint32_t	p_x;
	static uint32_t	p_y;

	set_projection_values(game, render, ray);
	ray->texture = get_texture(game, render, ray);
	// if (render->ray_index > 0 && render->rays[render->ray_index - 1].texture == ray->texture)
	// 	p_y = fmin(p_y + 1, TEXTURE_HEIGHT - 1);
	// else
		p_y = 32;
	render->img_col = ray->pw_top;
	render->img_row = render->ray_index;
	while (render->img_col < (uint32_t)ray->pw_bottom)
	{
		// p_x = ((render->img_col - ray->pw_top) * TEXTURE_HEIGHT) / ray->pw_height;
		p_x = 32;
		color = get_pixel_color(ray->texture, p_x, p_y);
		mlx_put_pixel(game->image, render->img_row, render->img_col, color);
		render->img_col++;
	}
}

// TODO: Check if the x corresponds to the column and the y to the row
