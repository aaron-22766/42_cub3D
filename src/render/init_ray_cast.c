
#include "../../include/cub3D.h"

void	init_raycast_frame(t_game *game, t_render *render)
{
	render->angle = game->player.orientation - (game->player.fov / 2);
	render->angle_increment = game->player.fov / (double) game->image->width;
	render->ray_index = 0;
	render->wall_height = TEXTURE_HEIGHT;
	render->wall_width = TEXTURE_WIDTH;
}

void	init_single_ray(t_game *game, t_render *render, t_ray *ray)
{
	ray->angle = render->angle;
	ray->eyes.x = game->player.pos.x;
	ray->eyes.y = game->player.pos.y;
	ray->eyes.z = render->wall_height / 2;			// TODO: change this to a define
	ray->distance = 0;			//	TODO:	determine_ray_distance(game, ray);
	ray->wall_top = 69;			//			determine_wall_top(game, ray);
	ray->wall_bottom = 420;		//		  	determine_wall_bottom(game, ray);
}
