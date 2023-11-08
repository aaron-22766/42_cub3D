
#include "../../include/cub3D.h"

static void	init_intersections(t_ray *ray)
{
	if (ray->angle > 0 && ray->angle < M_PI)
		ray->hor_inter.y = TILE_SIZE - (ray->origin.y % TILE_SIZE);
	else if (ray->angle > M_PI && ray->angle < 2.0 * M_PI)
		ray->hor_inter.y = -(ray->origin.y % TILE_SIZE);
	ray->hor_inter.x = round(((double) ray->hor_inter.y) / tan(ray->angle));
	if (ray->angle < M_PI_2 || ray->angle > 3.0 * M_PI_2)
		ray->ver_inter.x = TILE_SIZE - (ray->origin.x % TILE_SIZE);
	else if (ray->angle > M_PI_2 && ray->angle < 3.0 * M_PI_2)
		ray->ver_inter.x = -(ray->origin.x % TILE_SIZE);
	ray->ver_inter.y = round(((double) ray->ver_inter.x) * tan(ray->angle));
	ray->ver_inter = vector_sum(ray->origin, ray->ver_inter);
	ray->hor_inter = vector_sum(ray->origin, ray->hor_inter);
}

static void	init_auxiliary_variables(t_ray *ray)
{
	if (ray->angle > 0 && ray->angle < M_PI)
		ray->d_hor = init_vector(TILE_SIZE / tan(ray->angle), TILE_SIZE, 0);
	else if (ray->angle > M_PI && ray->angle < 2.0 * M_PI)
		ray->d_hor = init_vector(-TILE_SIZE / tan(ray->angle), -TILE_SIZE, 0);
	if (ray->angle < M_PI_2 || ray->angle > 3.0 * M_PI_2)
		ray->d_ver = init_vector(TILE_SIZE, TILE_SIZE * tan(ray->angle), 0);
	else if (ray->angle > M_PI_2 && ray->angle < 3.0 * M_PI_2)
		ray->d_ver = init_vector(-TILE_SIZE, -(TILE_SIZE * tan(ray->angle)), 0);
	ray->ver_length = get_distance_between(ray->ver_inter, ray->origin);
	ray->hor_length = get_distance_between(ray->hor_inter, ray->origin);
}

static void	intersect_wall(t_game *game, t_ray *ray)
{
	while (!is_wall(game, ray->hor_inter))
	{
		ray->hor_inter = vector_sum(ray->hor_inter, ray->d_hor);
		ray->hor_length = get_distance_between(ray->hor_inter, ray->origin);
	}
	while (!is_wall(game, ray->ver_inter))
	{
		ray->ver_inter = vector_sum(ray->ver_inter, ray->d_ver);
		ray->ver_length = get_distance_between(ray->ver_inter, ray->origin);
	}
}

static void	set_hit_vector(t_game *game, t_ray *ray)
{
	if (is_wall(game, ray->hor_inter) && (!is_wall(game, ray->ver_inter)
		|| (is_wall(game, ray->ver_inter) && ray->hor_length < ray->ver_length)))
	{
		ray->hit = copy_vector(ray->hor_inter);
		ray->length = ray->hor_length;
		if (ray->angle > 0 && ray->angle < M_PI)
			ray->texture = game->wall_textures[EAST];
		else
			ray->texture = game->wall_textures[WEST];
	}
	else
	{
		ray->hit = copy_vector(ray->ver_inter);
		ray->length = ray->ver_length;
		if (ray->angle < M_PI_2 || ray->angle > 3.0 * M_PI_2)
			ray->texture = game->wall_textures[SOUTH];
		else
			ray->texture = game->wall_textures[NORTH];
	}
}

void	find_ray_intersection(t_game *game, t_ray *ray)
{
	init_intersections(ray);
	init_auxiliary_variables(ray);
	intersect_wall(game, ray);
	set_hit_vector(game, ray);
}
