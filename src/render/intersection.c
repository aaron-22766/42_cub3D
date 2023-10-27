
#include "../../include/cub3D.h"

/*
Notes:

For the X intersections:
Ray->pixel_position.x = tile_size * floor(player.pos.x) if (player.orientation entre π/2 y 3/2*π) else ceil(player.pos.x) * tile_size;
// Or use remainder 64. p % tile_size
Ray->p_pos.y =[ (ray->pixel_position.x - player.pos.x) * math.tan(player.orientation) + player.pos.y] * tile_sizs
Then transfer from double to int * (tile_size) back and forth to check for coordinate that contains 1. 
 While not blocked cells. while (game->map->map[ray->p_pos.x / tile_size][ray->p_pos.y / 64] == '0')
ray->p_pos.x += tile_size if (player.orientation between π/2 and 3/2π) else -= tile_size
ray 


<file name>
	<function name>
		<incomplete explanation>

Intersection file
	Initialize the first intersections
		Initialise the intersection vectors
		depending on the angle (0,π/2) (π/2, π) . . .
		Use floor() and ceil() times tile_size
		also de delta x and delta y
	Get X axis parallel intersection
	Get Y axis parallel intersection
	Find_ray_intersection
		set the intersection vector
		depending on the angle (0,π/2) (π/2, π) . . .

Ray casting file
	Set ray
		Calculate the distance for each intersection
		If … else …
		Setting distance
		Texture if EW else NS
	Raycast
		Init intersections
		Get X intersection
		Get Y intersection
		Choose the one with the shortest distance 
		mlx_put_pixel

*/

void	find_first_intersections(t_game *game, t_ray *ray)
{
	int64_t		tile = TILE_SIZE;
	int64_t		dx;
	int64_t		dy;

	// ray->d_ver.x = tile;
	// ray->d_ver.y = tile * tan(ray->angle);
	// ray->d_hor.x = tile / tan(ray->angle);
	// ray->d_hor.y = tile;
	if (ray->angle < M_PI_2 || ray->angle > 3 * M_PI_2)
	{
		// Vertical intersection
		ray->ver_in.x = tile - (ray->origin.x % tile);
		ray->ver_in.y = ray->ver_in.x * tan(ray->angle);
	}
	else
	{
		
	}
}
// ray->hor_in.x = TILE_SIZE * ceil(game->player.pos.x);
// ray->hor_in.y = game->player.pos.y + (game->player.pos.x - ray->hor_in.x) * tan(ray->angle);


/**
 * @brief Initialize the values of:
 * 		ray->hor_in		Horizontal intersection	(parallel to the X axis)
 * 		ray->ver_in		Vertical intersection 	(parallel to the Y axis)
 * Based on the angle of the ray.
 * @param game 
 * @param ray 
 */

void	init_intersection_vectors(t_game *game, t_ray *ray)
{
	

}

void	ini

/**
 * @brief Find the ray horizontal intersection.
 * 	Parallel to the X axis!
 * 
 * @param game 
 * @param ray 
 */

void	find_horizontal_intersection(t_game *game, t_ray *ray)
{
	// TODO: Check if the ray is facing up or down
	// vector v = vector_sum(ray->origin, ray->hor_in); // BETTER TO USE (0, 0, 0) AS ORIGIN instead of player.pos
	// while valid_cell(v.x / TILE_SIZE, v.y / TILE_SIZE)
	// 	v = vector_sum(v, ray->d_hor)
}



void	find_ray_intersection(t_game *game, t_ray *ray)
{
	int64_t		hor_inter_length;
	int64_t		ver_inter_length;

	init_intersection_vectors(game, ray);
	find_horizontal_intersection(game, ray);
	find_vertical_intersection(game, ray);
	hor_inter_length = get_vector_length(ray->hor_in);
	if 
}

/**
 * @brief 
 * 
 * Steps of finding intersections with vertical grid lines:

Find coordinate of the first intersection (point B in this example).
The ray is facing right in the picture, so B.x = floor(P.x / TILE_SIZE) * (TILE_SIZE) + TILE_SIZE.
If the ray had been facing left B.x = floor(P.x / TILE_SIZE) * (TILE_SIZE) – 1.
A.y = P.y + (P.x - A.x) * tan(ALPHA);
Find Xa. (Note: Xa is just the width of the grid; however, if the ray is facing right, Xa will be positive, if the ray is facing left, Ya will be negative.)
Find Ya using the equation given above.
Check the grid at the intersection point. If there is a wall on the grid, stop and calculate the distance.
If there is no wall, extend the to the next intersection point. Notice that the coordinate of the next intersection point -call it (Xnew,Ynew) is just Xnew=Xold+Xa, and Ynew=YOld+Ya.
 */
// t_vector	get_vertical_intersection(t_game *game, t_ray *ray)
// {
// 	t_vector	intersection;
// 	double		x;
// 	double		y;

// 	x = floor(ray->pos.x / TILE_SIZE) * TILE_SIZE;
// 	if (ray->angle > 0 && ray->angle < M_PI)
// 		x += TILE_SIZE;
// 	y = ray->pos.y + (ray->pos.x - x) * tan(ray->angle);
// 	intersection = init_vector(x, y, 0);
// 	return (intersection);
// }
