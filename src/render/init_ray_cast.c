
#include "../../include/cub3D.h"

void	init_raycast_frame(t_game *game, t_render *render)
{
	render->camera_x = 2 * render->x / (double)game->image->width - 1;
	render->ray_dir_x = game->player.dir_x + game->player.plane_x * render->camera_x;
	render->ray_dir_y = game->player.dir_y + game->player.plane_y * render->camera_x;
	render->map_x = (int)game->player.pos_x;
	render->map_y = (int)game->player.pos_y;
	render->delta_dist_x = fabs(1 / render->ray_dir_x);
	render->delta_dist_y = fabs(1 / render->ray_dir_y);
	render->hit = 0;
}
