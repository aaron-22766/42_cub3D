
#include "../../include/cub3D.h"





void	init_ray(t_render *render, t_ray *ray)
{
	ray->angle = render->alpha;
	ray->length = 0;
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

}
