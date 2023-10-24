
#include "../../include/cub3D.h"

void	init_raycast_frame(t_game *game, t_render *render)
{
	render->ray_index = 0;
	render->angle = game->player.orientation - (game->player.fov / 2);
	render->angle_increment = game->player.fov / (double) game->image->width;
	render->pos = game->player.pos;
	render->img_col = 0;
	render->img_row = 0;
}

void	init_single_ray(t_render *render, t_ray *ray)
{
	ray->angle = render->angle;
	ray->distance = 0;
	ray->pw_height = 0;
	ray->pw_width = 0;
	ray->pw_top = 0;
	ray->pw_bottom = 0;
	ray->texture = NULL;
	ray->pos.x = render->pos.x + 0; // Change to	cos(orientation) * something
	ray->pos.y = render->pos.y + 0; // 			sin(orientation) * something
	ray->pos.z = 0;					// 
}

void	print_ray(t_ray *ray)
{
	printf("\nRAY:\n");
	printf(" Angle: %f\n", ray->angle);
	printf(" Distance: %f\n", ray->distance);
	printf(" pw_height: %f\n", ray->pw_height);
	printf(" pw_width: %f\n", ray->pw_width);
	printf(" pw_top: %f\n", ray->pw_top);
	printf(" pw_bottom: %f\n", ray->pw_bottom);
	print_pos(&ray->pos);
}

void	print_render(t_render *render)
{
	printf("\nRENDER:\n");
	printf(" ray_index: %zu\n", render->ray_index);
	printf(" angle: %f\n", render->angle);
	printf(" angle_increment: %f\n", render->angle_increment);
	print_pos(&render->pos);
}
