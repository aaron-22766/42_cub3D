#include "../../include/cub3D.h"

static void	init_wall_tools(t_ray *ray)
{
	ray->hit = zero_vector();
	ray->length = 0;
	ray->hor_inter = zero_vector();
	ray->ver_inter = zero_vector();
	ray->d_hor = zero_vector();
	ray->d_ver = zero_vector();
	ray->hor_length = 0;
	ray->ver_length = 0;
}

void	init_ray(t_world *world)
{
	t_ray	*ray;

	ray = &world->rays[world->ray_index];
	ray->id = world->ray_index;
	ray->angle = world->theta;
	if (ray->id > 0)
		ray->angle = world->rays[ray->id - 1].angle + world->delta;
	if (ray->angle > 2 * M_PI)
		ray->angle -= 2 * M_PI;
	ray->origin = copy_vector(world->pov);
	init_wall_tools(ray);
	ray->img.x = 0;
	ray->img.y = 0;
	ray->img.color = 0;
	ray->txt_id = 0;
	ray->texture = NULL;
}

void	print_ray(t_ray *ray)
{
	printf("\nRAY:\n");
	printf(" id: %zu\n", ray->id);
	printf(" angle: %f\n", ray->angle);
	print_vector(&ray->origin, "origin", true);
	print_vector(&ray->hit, "hit", true);
	printf(" length: %lld\n", ray->length);
	print_vector(&ray->hor_inter, "hor_inter", true);
	print_vector(&ray->ver_inter, "ver_inter", true);
	print_vector(&ray->d_hor, "d_hor", true);
	print_vector(&ray->d_ver, "d_ver", true);
}
