
#include "../../include/cub3D.h"

void	init_raycast_frame(t_game *game, t_render *render)
{
	render->angle = game->player.orientation - (game->player.fov / 2);
	render->angle_increment = game->player.fov / (double) game->image->width;
	render->ray_index = 0;
	render->pos = game->player.pos;
}

void	init_single_ray(t_game *game, t_render *render, t_ray *ray)
{
	ray->angle = render->angle;
	ray->pos.x = render->pos.x + 0; // Change to	cos(orientation) * something
	ray->pos.y = render->pos.y + 0; // 			sin(orientation) * something
	ray->pos.z = 0;					// 
	ray->distance = 0;
}
