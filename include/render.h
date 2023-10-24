
#ifndef RENDER_H
# define RENDER_H

/* ************************************************************************** */
/*                                  TYPEDEFS                                  */
/* ************************************************************************** */

typedef struct s_game	t_game;
# define WINDOW_WIDTH 1080


/* ************************************************************************** */
/*                                  STRUCTS                                   */
/* ************************************************************************** */

/**
 * @brief Ray structure
 * 
 * @param angle Angle of the ray in radians (0 is right or east,
 * positive angles are counter-clockwise)
 * @param distance Distance between the player and the wall
 * @param pw_height	Height of the projected wall in the IMAGE
 * @param pw_width Width of the projected wall in the IMAGE
 * @param pw_top Top of the projected wall in the IMAGE
 * @param pw_bottom	Bottom of the projected wall in the IMAGE
 * @param texture Texture of the wall
 * @param pos Position where the RAY hits a wall
 */

typedef struct s_ray
{
	double			angle;
	double			distance;
	double			pw_height;
	double			pw_width;
	double			pw_top;
	double			pw_bottom;
	mlx_texture_t	*texture;
	t_pos			pos;
}	t_ray;

/**
 * @brief Render structure
 * 
 * @param rays Array of rays
 * @param ray_index Index of the current ray
 * @param angle Angle of the first (leftmost) ray in radians
 * @param angle_increment Angle increment between two rays
 * @param pos PLAYER position
 */

typedef struct s_render
{
	t_ray		rays[WINDOW_WIDTH];
	size_t		ray_index;
	double		angle;
	double		angle_increment;
	t_pos		pos;
}	t_render;

/* ************************************************************************** */
/*                                 FUNCTIONS                                  */
/* ************************************************************************** */

/* background.c */
void	render_background(t_game *game);

/* init_ray_cast.c */
void	init_raycast_frame(t_game *game, t_render *render);
void	init_single_ray(t_render *render, t_ray *ray);

/* ray_casting.c */
void    render_raycast(t_game *game, t_render *render, t_ray *ray);

/* render.c */
void	generate_render(t_game *game);

#endif
