
#include "../../include/cub3D.h"

/**
 * @brief Find the coordinates of the first intersections of the ray.
 *	The player's position is the origin of the ray.
 * 	1. Find the coordinates of the first vertical intersection.
 * 		1.1. If the ray is pointing to the right, the x coordinate of the
 * 			first vertical intersection is the next multiple of TILE_SIZE
 * 			after the player's x coordinate.
 * 		1.2. If the ray is pointing to the left, the x coordinate of the
 * 			first vertical intersection is the previous multiple of TILE_SIZE
 * 			before the player's x coordinate.
 * 	2. Find the coordinates of the first horizontal intersection.
 * @param game 
 * @param ray 
 */

void	init_intersections(t_game *game, t_ray *ray)
{
	if (ray->angle < M_PI_2 || ray->angle > 3 * M_PI_2)
		ray->ver_inter.x = TILE_SIZE - (ray->origin.x % TILE_SIZE);
	else
		ray->ver_inter.x = -(ray->origin.x % TILE_SIZE);
	ray->ver_inter.y = ray->ver_inter.x * tan(ray->angle);
	if (ray->angle < M_PI)
		ray->hor_inter.y = TILE_SIZE - (ray->origin.y % TILE_SIZE);
	else
		ray->hor_inter.y = -(ray->origin.y % TILE_SIZE);
	ray->hor_inter.x = ray->hor_inter.y / tan(ray->angle);
	ray->ver_inter = vector_sum(ray->origin, ray->ver_inter);
	ray->hor_inter = vector_sum(ray->origin, ray->hor_inter);
}

void	init_auxiliary_variables(t_game *game, t_ray *ray)
{
	if (ray->angle < M_PI_2 || ray->angle > 3 * M_PI_2)
		ray->d_ver = init_vector(TILE_SIZE, TILE_SIZE * tan(ray->angle), 0);
	else
		ray->d_ver = init_vector(-TILE_SIZE, -TILE_SIZE * tan(ray->angle), 0);
	if (ray->angle < M_PI)
		ray->d_hor = init_vector(TILE_SIZE / tan(ray->angle), TILE_SIZE, 0);
	else
		ray->d_hor = init_vector(-TILE_SIZE / tan(ray->angle), -TILE_SIZE, 0);
	ray->ver_length = get_distance_between(ray->ver_inter, ray->origin);
	ray->hor_length = get_distance_between(ray->hor_inter, ray->origin);
}

bool	update_horizontal(t_game *game, t_ray *ray)
{
	ray->hor_inter = vector_sum(ray->hor_inter, ray->d_hor);
	ray->hor_length = get_distance_between(ray->hor_inter, ray->origin);
	if (is_wall(game, ray->hor_inter))
	{
		ray->hit = copy_vector(ray->hor_inter);
		ray->length = ray->hor_length;
		if (ray->angle < M_PI)
			ray->texture = game->so_texture;
		else
			ray->texture = game->no_texture;
		return (true);
	}
	return (false);
}

bool	update_vertical(t_game *game, t_ray *ray)
{
	ray->ver_inter = vector_sum(ray->ver_inter, ray->d_ver);
	ray->ver_length = get_distance_between(ray->ver_inter, ray->origin);
	if (is_wall(game, ray->ver_inter))
	{
		ray->hit = copy_vector(ray->ver_inter);
		ray->length = ray->ver_length;
		if (ray->angle < M_PI_2 || ray->angle > 3 * M_PI_2)
			ray->texture = game->ea_texture;
		else
			ray->texture = game->we_texture;
		return (true);
	}
	return (false);
}

/**
 * @brief Find the ray intersection.
 * 
 * @param game 
 * @param ray 
 */
void	find_ray_intersection(t_game *game, t_ray *ray)
{
	bool	wall_inter_found;

	wall_inter_found = false;
	init_intersections(game, ray);
	init_auxiliary_variables(game, ray);
	while (!wall_inter_found)
	{
		if (ray->hor_length < ray->ver_length)
		{
			wall_inter_found = update_horizontal(game, ray);
		} else
		{
			wall_inter_found = update_vertical(game, ray);
		}
	}
}
