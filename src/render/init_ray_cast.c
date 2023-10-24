
#include "../../include/cub3D.h"

void	init_raycast_frame(t_game *game, t_render *render)
{
	render->angle = game->player.orientation - (game->player.fov / 2);
	render->angle_increment = game->player.fov / (double) game->image->width;
	render->ray_index = 0;
	// render->wall_height = TEXTURE_HEIGHT;
	// render->wall_width = TEXTURE_WIDTH;
	render->pos = game->player.pos;
}

void	init_single_ray(t_game *game, t_render *render, t_ray *ray)
{
	ray->angle = render->angle;
	ray->eyes = render->pos;
	ray->pos.x = render->pos.x + 0; // Change to	cos(orientation) * something
	ray->pos.y = render->pos.y + 0; // 			sin(orientation) * something
	ray->pos.z = 0;
	ray->distance = 0;
	ray->wall_top = 69;
	ray->wall_bottom = 420;
}

/*
 TODO: change this to a define
	TODO:	determine_ray_distance(game, ray);
			determine_wall_top(game, ray);
		  	determine_wall_bottom(game, ray);

*/
