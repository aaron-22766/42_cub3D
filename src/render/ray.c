#include "../../include/render.h"

void	init_ray(t_render *render)
{
	t_ray	*ray;

	ray = &render->rays[render->ray_index];
	ray->id = render->ray_index;
	ray->angle = render->theta;
	ray->hit = init_vector(0, 0, 0);
	ray->origin = copy_vector(render->pov);
	ray->length = 0;
	ray->hor_inter = init_vector(0, 0, 0);
	ray->ver_inter = init_vector(0, 0, 0);
	ray->d_hor = init_vector(0, 0, 0);
	ray->d_ver = init_vector(0, 0, 0);
	ray->hor_length = 0;
	ray->ver_length = 0;
	ray->texture = NULL;
}

void	print_ray(t_ray *ray)
{
	printf("\nRAY:\n");
	printf(" id: %zu\n", ray->id);
	printf(" angle: %f\n", ray->angle);
	printf(" origin: ");
	print_vector(&ray->origin, "origin", true);

}
