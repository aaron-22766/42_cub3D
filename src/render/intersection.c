// #include "../../include/cub3D.h"

// /**
//  * @brief Find the coordinates of the first intersections of the ray.
//  *	The player's position is the origin of the ray.
//  * 	1. Find the coordinates of the first vertical intersection.
//  * 		1.1. If the ray is pointing to the right, the x coordinate of the
//  * 			first vertical intersection is the next multiple of TILE_SIZE
//  * 			after the player's x coordinate.
//  * 		1.2. If the ray is pointing to the left, the x coordinate of the
//  * 			first vertical intersection is the previous multiple of TILE_SIZE
//  * 			before the player's x coordinate.
//  * 	2. Find the coordinates of the first horizontal intersection.
//  * @param game 
//  * @param ray 
//  */

// void	init_intersections(t_ray *ray)
// {
// 	if (ray->angle > 0 && ray->angle < M_PI)
// 		ray->hor_inter.y = TILE_SIZE - (ray->origin.y % TILE_SIZE);
// 	else if (ray->angle > M_PI && ray->angle < 2.0 * M_PI)
// 		ray->hor_inter.y = -(ray->origin.y % TILE_SIZE);
// 	// if (ray->hor_inter.y != 0)
// 		ray->hor_inter.x = round(((double) ray->hor_inter.y) / tan(ray->angle));
// 	if (ray->angle < M_PI_2 || ray->angle > 3.0 * M_PI_2)
// 		ray->ver_inter.x = TILE_SIZE - (ray->origin.x % TILE_SIZE);
// 	else if (ray->angle > M_PI_2 && ray->angle < 3.0 * M_PI_2)
// 		ray->ver_inter.x = -(ray->origin.x % TILE_SIZE);
// 	// if (ray->ver_inter.x != 0)
// 		ray->ver_inter.y = round(((double) ray->ver_inter.x) * tan(ray->angle));
// 	ray->ver_inter = vector_sum(ray->origin, ray->ver_inter);
// 	ray->hor_inter = vector_sum(ray->origin, ray->hor_inter);
// }

// void	init_auxiliary_variables(t_ray *ray)
// {
// 	if (ray->angle > 0 && ray->angle < M_PI)
// 		ray->d_hor = init_vector(TILE_SIZE / tan(ray->angle), TILE_SIZE, 0);
// 	else if (ray->angle > M_PI && ray->angle < 2.0 * M_PI)
// 		ray->d_hor = init_vector(-TILE_SIZE / tan(ray->angle), -TILE_SIZE, 0);
// 	if (ray->angle < M_PI_2 || ray->angle > 3.0 * M_PI_2)
// 		ray->d_ver = init_vector(TILE_SIZE, TILE_SIZE * tan(ray->angle), 0);
// 	else if (ray->angle > M_PI_2 && ray->angle < 3.0 * M_PI_2)
// 		ray->d_ver = init_vector(-TILE_SIZE, -(TILE_SIZE * tan(ray->angle)), 0);
// 	ray->ver_length = get_distance_between(ray->ver_inter, ray->origin);
// 	ray->hor_length = get_distance_between(ray->hor_inter, ray->origin);
// }

// // bool	update_horizontal(t_game *game, t_ray *ray)
// // {
// // 	ray->hor_inter = vector_sum(ray->hor_inter, ray->d_hor);
// // 	ray->hor_length = get_distance_between(ray->hor_inter, ray->origin);
// // 	if (!is_wall(game, ray->hor_inter))
// // 		return (false);
// // 	ray->hit = copy_vector(ray->hor_inter);
// // 	ray->length = ray->hor_length;
// // 	if (ray->angle < M_PI)
// // 		ray->texture = game->wall_textures[SOUTH];
// // 	else
// // 		ray->texture = game->wall_textures[NORTH];
// // 	return (true);
// // }

// // bool	update_vertical(t_game *game, t_ray *ray)
// // {
// // 	ray->ver_inter = vector_sum(ray->ver_inter, ray->d_ver);
// // 	// ray->ver_inter.y = ray->ver_inter.x * tan(ray->angle);
// // 	ray->ver_length = get_distance_between(ray->ver_inter, ray->origin);
// // 	if (!is_wall(game, ray->ver_inter))
// // 		return (false);
// // 	ray->hit = copy_vector(ray->ver_inter);
// // 	ray->length = ray->ver_length;
// // 	if (ray->angle < M_PI_2 || ray->angle > 3.0 * M_PI_2)
// // 		ray->texture = game->wall_textures[EAST];
// // 	else
// // 		ray->texture = game->wall_textures[WEST];
// // 	return (true);
// // }

// // void	find_ray_intersection(t_game *game, t_ray *ray)
// // {
// // 	bool	wall_inter_found;

// // 	wall_inter_found = false;
// // 	init_intersections(ray);
// // 	init_auxiliary_variables(ray);
// // 	if (ray->id % (WINDOW_WIDTH / 2) == 0) print_ray(ray); // Debug
// // 	if (ray->id % (WINDOW_WIDTH / 2) == 0) print_vector(&ray->hit, "BEFORE: hit", true); // Debug
// // 	if (ray->id % (WINDOW_WIDTH / 2) == 0) print_vector(&ray->hor_inter, " hor_inter", true); // Debug
// // 	if (ray->id % (WINDOW_WIDTH / 2) == 0) print_vector(&ray->ver_inter, " ver_inter", true); // Debug

// // 	while (!wall_inter_found)
// // 	{
// // 		if (ray->hor_length < ray->ver_length)
// // 			wall_inter_found = update_horizontal(game, ray);
// // 		else
// // 			wall_inter_found = update_vertical(game, ray);
// // 	}
// // 	if (ray->id % (WINDOW_WIDTH / 2) == 0) print_vector(&ray->hit, "AFTER: hit", true); // Debug
// // 	if (ray->id % (WINDOW_WIDTH / 2) == 0) print_vector(&ray->hor_inter, " hor_inter", true); // Debug
// // 	if (ray->id % (WINDOW_WIDTH / 2) == 0) print_vector(&ray->ver_inter, " ver_inter", true); // Debug
// // }

// static void	set_hit_vector(t_game *game, t_ray *ray)
// {
// 	if (is_wall(game, ray->hor_inter))
// 	{
// 		ray->hit = copy_vector(ray->hor_inter);
// 		ray->length = ray->hor_length;
// 		if (ray->angle > 0 && ray->angle < M_PI)
// 			ray->texture = game->wall_textures[SOUTH];
// 		else
// 			ray->texture = game->wall_textures[NORTH];
// 	}
// 	else
// 	{
// 		ray->hit = copy_vector(ray->ver_inter);
// 		ray->length = ray->ver_length;
// 		if (ray->angle < M_PI_2 || ray->angle > 3.0 * M_PI_2)
// 			ray->texture = game->wall_textures[EAST];
// 		else
// 			ray->texture = game->wall_textures[WEST];
// 	}
// }

// static void intersect_wall(t_game *game, t_ray *ray)
// {
// 	if (ray->id % (WINDOW_WIDTH / 2) == 0) printf("Intersect wall\n"); // Debug
// 	while (!is_wall(game, ray->hor_inter))
// 	{
// 		if (ray->id % (WINDOW_WIDTH / 2) == 0) print_vector(&ray->hor_inter, "   hor_inter", true); // Debug
// 		ray->hor_inter = vector_sum(ray->hor_inter, ray->d_hor);
// 		if (ray->id % (WINDOW_WIDTH / 2) == 0) print_vector(&ray->hor_inter, " hor_inter", true); // Debug
// 		ray->hor_length = get_distance_between(ray->hor_inter, ray->origin);
// 		if (ray->hor_inter.x < 0 || ray->hor_inter.y < 0
// 			|| ray->hor_inter.x >= (int64_t) game->flex_map.height * TILE_SIZE
// 			|| ray->hor_inter.y >= (int64_t) game->flex_map.max_width * TILE_SIZE)
// 			break;
// 	}
// 	while (!is_wall(game, ray->ver_inter))
// 	{
// 		ray->ver_inter = vector_sum(ray->ver_inter, ray->d_ver);
// 		ray->ver_length = get_distance_between(ray->ver_inter, ray->origin);
// 		if (ray->ver_inter.x < 0 || ray->ver_inter.y < 0
// 			|| ray->ver_inter.x >= (int64_t) game->flex_map.height * TILE_SIZE
// 			|| ray->ver_inter.y >= (int64_t) game->flex_map.max_width * TILE_SIZE)
// 			break;
// 	}

// 	if (ray->id % (WINDOW_WIDTH / 2) == 0) print_vector(&ray->hor_inter, " hor_inter", true); // Debug
// 	if (ray->id % (WINDOW_WIDTH / 2) == 0) print_vector(&ray->ver_inter, " ver_inter", true); // Debug
// }

// void	find_ray_intersection(t_game *game, t_ray *ray)
// {
// 	init_intersections(ray);
// 	init_auxiliary_variables(ray);
// 	if (ray->id % (WINDOW_WIDTH / 2) == 0) print_ray(ray); // Debug
// 	if (ray->id % (WINDOW_WIDTH / 2) == 0) print_vector(&ray->hit, "BEFORE: hit", true); // Debug
// 	if (ray->id % (WINDOW_WIDTH / 2) == 0) print_vector(&ray->hor_inter, " hor_inter", true); // Debug
// 	if (ray->id % (WINDOW_WIDTH / 2) == 0) print_vector(&ray->ver_inter, " ver_inter", true); // Debug
// 	// while (is_wall(game, ray->hor_inter) == false && is_wall(game, ray->ver_inter) == false)
// 	// {
// 	// 	if (ray->hor_length < ray->ver_length)
// 	// 	{
// 	// 		ray->hor_inter = vector_sum(ray->hor_inter, ray->d_hor);
// 	// 		ray->hor_length = get_distance_between(ray->hor_inter, ray->origin);
// 	// 	}
// 	// 	else
// 	// 	{
// 	// 		ray->ver_inter = vector_sum(ray->ver_inter, ray->d_ver);
// 	// 		ray->ver_length = get_distance_between(ray->ver_inter, ray->origin);
// 	// 	}
// 	// }
// 	intersect_wall(game, ray);
// 	set_hit_vector(game, ray);
// 	if (ray->id % (WINDOW_WIDTH / 2) == 0) print_vector(&ray->hit, "AFTER: hit", true); // Debug
// 	if (ray->id % (WINDOW_WIDTH / 2) == 0) print_vector(&ray->hor_inter, " hor_inter", true); // Debug
// 	if (ray->id % (WINDOW_WIDTH / 2) == 0) print_vector(&ray->ver_inter, " ver_inter", true); // Debug
// }
