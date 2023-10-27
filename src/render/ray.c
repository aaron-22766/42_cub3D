
#include "../../include/cub3D.h"

// void	init_ray(t_render *render, t_ray *ray)
// {
// 	ray->angle = render->theta;
// 	ray->length = 0;
// 	ray->pw_height = 0;
// 	ray->pw_width = 0;
// 	ray->pw_top = 0;
// 	ray->pw_bottom = 0;
// 	ray->texture = NULL;
// 	ray->pos.x = render->pos.x + 0; // Change to	cos(orientation) * something
// 	ray->pos.y = render->pos.y + 0; // 			sin(orientation) * something
// 	ray->pos.z = 0;					// 
// }

void	init_ray(t_render *render)
{
	t_ray	*ray;

	ray = &render->rays[render->ray_index];
	ray->id = render->ray_index;
	ray->alpha = render->theta;
	ray->hit = init_vector(0, 0, 0);
	ray->origin = copy_vector(render->pov);
	ray->length = 0;
	ray->hor_in = init_vector(0, 0, 0);
	ray->ver_in = init_vector(0, 0, 0);
	ray->texture = NULL;
}

void	print_ray(t_ray *ray)
{
	printf("\nRAY:\n");
	printf(" id: %zu\n", ray->id);
	printf(" alpha: %f\n", ray->alpha);
	printf(" origin: ");
	print_vector(&ray->origin, "origin", true);

}
