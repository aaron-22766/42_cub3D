
#include "../../include/cub3D.h"

/**
 * @attention t_vector (x, y, z)
*/

void	init_ray(t_render *render)
{
	t_ray	*ray;

	ray = &render->rays[render->ray_index];
	ray->id = render->ray_index;
	ray->angle = render->theta;
	ray->hit = init_vector(0, 0, TILE_SIZE / 2);
	ray->origin = copy_vector(render->pov);
	ray->length = 0;
	ray->hor_in = init_vector(0, 0, TILE_SIZE / 2);
	ray->ver_in = init_vector(0, 0, TILE_SIZE / 2);
	if (ray->angle < M_PI_2 || ray->angle > 3 * M_PI_2)
		ray->d_ver = init_vector(TILE_SIZE, TILE_SIZE * tan(ray->angle), 0);
	else
		ray->d_ver = init_vector(-TILE_SIZE, -TILE_SIZE * tan(ray->angle), 0);
		if (ray->angle < M_PI)
		ray->d_hor = init_vector(TILE_SIZE / tan(ray->angle), TILE_SIZE, 0);
	else
		ray->d_hor = init_vector(-TILE_SIZE / tan(ray->angle), -TILE_SIZE, 0);
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
