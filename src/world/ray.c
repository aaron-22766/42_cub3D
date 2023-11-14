#include "../../include/cub3D.h"

static void	init_wall_tools(t_ray *ray)
{
	ray->hor_inter = init_vector(0, 0, 0);
	ray->ver_inter = init_vector(0, 0, 0);
	ray->d_hor = init_vector(0, 0, 0);
	ray->d_ver = init_vector(0, 0, 0);
	ray->hor_length = 0;
	ray->ver_length = 0;
}

void	init_ray(t_world *world)
{
	t_ray	*ray;

	ray = &world->rays[world->ray_index];
	ray->id = world->ray_index;
	ray->angle = world->theta;
	ray->origin = copy_vector(world->pov);
	ray->hit = init_vector(0, 0, 0);
	ray->length = 0;
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
