
#include "../../include/cub3D.h"

/**
 * @brief Find the ray first vertical and horizontal intersections.
 * 
 * @param game 
 * @param ray 
 */

void	find_first_intersections(t_game *game, t_ray *ray)
{
	if (ray->angle < M_PI_2 || ray->angle > 3 * M_PI_2)
	{
		// Vertical intersection (facing right)
		ray->ver_inter.x = TILE_SIZE - (ray->origin.x % TILE_SIZE);
		ray->ver_inter.y = ray->ver_inter.x * tan(ray->angle);
	} else {
		// Vertical intersection (facing left)
		ray->ver_inter.x = -(ray->origin.x % TILE_SIZE);
		ray->ver_inter.y = ray->ver_inter.x * tan(ray->angle);
	}
	if (ray->angle < M_PI)
	{
		// Horizontal intersection (facing up)
		ray->hor_inter.y = TILE_SIZE - (ray->origin.y % TILE_SIZE);
		ray->hor_inter.x = ray->hor_inter.y / tan(ray->angle);
	} else {
		// Horizontal intersection (facing down)
		ray->hor_inter.y = -(ray->origin.y % TILE_SIZE);
		ray->hor_inter.x = ray->hor_inter.y / tan(ray->angle);
	}
	// ray->hor_inter = vector_sum(ray->origin, ray->hor_inter);
	// ray->ver_inter = vector_sum(ray->origin, ray->ver_inter);
}

bool	update_horizontal_inter(t_game *game, t_ray *ray)
{
	ray->hor_inter = vector_sum(ray->hor_inter, ray->d_hor);
	ray->hor_length = vector_length(ray->hor_inter);
	if (is_wall(game, ray->hor_inter))
	{
		ray->hit = ray->hor_inter;
		ray->length = ray->hor_length;
		ray->texture = get_texture(game, ray->hor_inter, ray->d_hor);
		return (true);
	}
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
	find_first_intersections(game, ray);
	ray->hor_length = vector_length(ray->hor_inter);
	ray->ver_length = vector_length(ray->ver_inter);
	while (!wall_inter_found)
	{
		if (ray->hor_length < ray->ver_length)
		{
			wall_inter_found = up
			ray->hor_inter = vector_sum(ray->hor_inter, ray->d_hor);
			ray->hor_length = vector_length(ray->hor_inter);
			if (is_wall(game, vector_sum(ray->origin, ray->hor_inter)))
			{
				ray->hit = ray->hor_inter;
				ray->length = ray->hor_length;
				ray->texture = get_texture(game, ray->hor_inter, ray->d_hor);
				break ;
			}
		} else {
			ray->ver_inter = vector_sum(ray->ver_inter, ray->d_ver);
			ray->ver_length = vector_length(ray->ver_inter, ray->origin);
			if (ray->ver_length > game->map->height * TILE_SIZE)
				break ;
			if (is_wall(game, ray->ver_inter))
			{
				ray->hit = ray->ver_inter;
				ray->length = ray->ver_length;
				ray->texture = get_texture(game, ray->ver_inter, ray->d_ver);
				break ;
			}
		}
		// if (ray->hor_length < ray->ver_length)
		// {
		// 	ray->hor_inter = vector_sum(ray->hor_inter, ray->d_hor);
		// 	ray->hor_length = vector_length(ray->hor_inter, ray->origin);
		// 	// if (ray->hor_length > game->map->width * TILE_SIZE)
		// 	// 	break ;
		// 	// if (is_wall(game, ray->hor_inter))
		// 	// {
		// 	// 	ray->hit = ray->hor_inter;
		// 	// 	ray->length = hor_inter_length;
		// 	// 	ray->texture = get_texture(game, ray->hor_inter, ray->d_hor);
		// 	// 	break ;
		// 	// }
		// 	// ray->hor_length = hor_inter_length;
		// } else {
		// 	ray->ver_inter = vector_sum(ray->ver_inter, ray->d_ver);
		// 	ver_inter_length = vector_length(ray->ver_inter, ray->origin);
		// 	if (ver_inter_length > game->map->height * TILE_SIZE)
		// 		break ;
		// 	if (is_wall(game, ray->ver_inter))
		// 	{
		// 		ray->hit = ray->ver_inter;
		// 		ray->length = ver_inter_length;
		// 		ray->texture = get_texture(game, ray->ver_inter, ray->d_ver);
		// 		break ;
		// 	}
		// 	ray->ver_length = ver_inter_length;
		// }
	}
}
