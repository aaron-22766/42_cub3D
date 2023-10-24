
#include "../../include/cub3D.h"

static void	set_projection_values(t_game *game, t_render *render, t_ray *ray)
{
	double  dx;
    double  dy;

    dx = cos(ray->angle);
    dy = sin(ray->angle);
    while (game->map.map[(int)ray->pos.y][(int)ray->pos.x] != '1')
    {
        ray->pos.x += dx;
		ray->pos.y += dy;
    }
	ray->distance = sqrt(pow(ray->eyes.x - ray->pos.x, 2) + pow(ray->eyes.y - ray->pos.y, 2));
	ray->p_wall_height = render->wall_height / ray->distance * (double) game->image->height;
	ray->wall_top = ((double)game->image->height - ray->p_wall_height) / 2;
	ray->wall_bottom = ((double)game->image->height + ray->p_wall_height) / 2;
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

static int32_t	get_pixel_color(mlx_texture_t *txt, int x, int y)
{
	int32_t	r;
	int32_t	g;
	int32_t	b;

	r = txt->pixels[(y * txt->width + x) * txt->bytes_per_pixel + 0];
	g = txt->pixels[(y * txt->width + x) * txt->bytes_per_pixel + 1];
	b = txt->pixels[(y * txt->width + x) * txt->bytes_per_pixel + 2];
	return (ft_pixel(r, g, b, 128));
}

void    cast_single_ray(t_game *game, t_render *render, t_ray *ray)
{
	int32_t	row;
	int32_t	col;

    set_projection_values(game, render, ray);
	ray->texture = get_texture(game, render, ray);
	set_projection_values(game, render, ray);
	row = 0;
	col = 0;
	// while (row < game->image->height)
		
	// 	if (col >= ray->wall_top && col <= ray->wall_bottom)
	// 		mlx_pixel_put(game->mlx, game->image, x, y, get_pixel_color(ray->texture, x, y));
	// 	// TODO:	-	Loop through all pixels that are part of the wall
	// 	// 			-	For each pixel:
	// 	// 				-	Get pixel color
	// 	// 				-	Render pixel
	// }

}
