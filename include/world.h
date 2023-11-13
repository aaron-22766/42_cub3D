#ifndef WORLD_H
# define WORLD_H

/* ************************************************************************** */
/*                                  INCLUDES                                  */
/* ************************************************************************** */

# include "utils.h"

/* ************************************************************************** */
/*                                  TYPEDEFS                                  */
/* ************************************************************************** */

typedef struct s_game	t_game;

/* ************************************************************************** */
/*                                  STRUCTS                                   */
/* ************************************************************************** */

/**
 * @brief Ray structure
 *
 * @param id Index of the ray
 * @param angle Horizontal angle of the ray
 * @param origin Position of the player's eyes
 * @param hit Position of the first wall hit by the ray
 * @param length Distance between the player and the Projection Plane
 * @param hor_inter Horizontal intersection	(parallel to the X axis)
 * @param ver_inter Vertical intersection 		(parallel to the Y axis)
 * @param d_hor Delta of the horizontal intersection
 * @param d_ver Delta of the vertical intersection
 * @param texture Texture of the wall hit by the ray
 *
 * @attention All angles are in radians
 * @attention Angle rotates clockwise. Negative in the cartesian plane
 * @attention HOR_IN <-> TILE_SIZE divides ray Y coordinate
 */

typedef struct s_ray
{
	size_t			id;
	double			angle;
	t_vector		origin;
	t_vector		hit;
	int64_t			length;
	t_vector		hor_inter;
	t_vector		ver_inter;
	t_vector		d_hor;
	t_vector		d_ver;
	int64_t			hor_length;
	int64_t			ver_length;
	mlx_texture_t	*texture;
}	t_ray;

/**
 * @brief Render structure
 *
 * @param rays Array of rays
 * @param ray_index Index of the current ray
 * @param theta Angle of the current ray
 * @param delta Angle between two rays
 * @param distance Distance between the player and the Projection Plane
 * @param pov Point of View of the player
 *
 * @attention All angles are in radians
 * @attention Alpha rotates clockwise (negative in the cartesian plane)
 */

typedef struct s_world
{
	t_ray		*rays;
	size_t		ray_index;
	double		theta;
	double		delta;
	double		distance;
	t_vector	pov;
}	t_world;

/* ************************************************************************** */
/*                                 FUNCTIONS                                  */
/* ************************************************************************** */

/* background.c */
void		render_background(t_game *game);

/* init.c */
void		generate_render(t_game *game);

/* intersection.c */
void		find_ray_intersection(t_game *game, t_ray *ray);

/* ray_casting.c */
void		render_raycast(t_game *game, t_ray *ray);

/* ray.c */
void		init_ray(t_world *world);
void		update_render(t_world *world);
void		print_ray(t_ray *ray);

/* world.c */
void		reset_render(t_game *game, t_world *world);
t_world	init_render(t_game *game);
void		print_render(t_world *world);

/* utils.c */
int64_t		get_distance_between(t_vector vector, t_vector origin);
bool		is_wall(t_game *game, t_vector vector);

#endif
