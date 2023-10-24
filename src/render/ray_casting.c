
#include "../../include/cub3D.h"

void    cast_single_ray(t_game *game, t_render *render, t_ray *ray)
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
	ray->distance = sqrt(pow(game->player.pos.x - ray->pos.x, 2) + pow(game->player.pos.y - ray->pos.y, 2));
	
}
