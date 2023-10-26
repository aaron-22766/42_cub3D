
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
 * @param length Distance between the player and the wall
 * @param pw_height	Height of the projected wall in the IMAGE
 * @param pw_width Width of the projected wall in the IMAGE
 * @param pw_top Top of the projected wall in the IMAGE
 * @param pw_bottom	Bottom of the projected wall in the IMAGE
 * @param texture Texture of the wall
 * @param pos Position where the RAY hits a wall
 */

typedef struct s_ray
{
	int				id;
	mlx_texture_t	*texture;
	double			angle;
	double			length;
	double			pw_height;	//  To be replaced
	double			pw_width;	//  To be replaced
	double			pw_top;		//  To be replaced
	double			pw_bottom;	//  To be replaced
	t_vector		wall_hit;
	t_pos			pos;
}	t_ray;

/**
 * @brief Render structure
 * 
 * @param rays Array of rays
 * @param ray_index Index of the current ray
 * @param angle Angle of the first (leftmost) ray in radians
 * @param delta Angle increment between two rays
 * @param pos PLAYER position
 */

typedef struct s_render
{
	t_ray		rays[WINDOW_WIDTH];
	size_t		ray_index;
	double		alpha;
	double		delta;
	uint32_t	img_row;	// To be replaced by img_pixel
	uint32_t	img_col;	// To be replaced by img_pixel
	t_pixel		img_pixel;
	t_pos		pos; 		// To be replaced by p
	t_vector	player;	// PLAYER position
}	t_render;

/* ************************************************************************** */
/*                                 FUNCTIONS                                  */
/* ************************************************************************** */

/* background.c */
void	render_background(t_game *game);

/* init_ray_cast.c */
void	init_raycast_frame(t_game *game, t_render *render);
void	init_ray(t_render *render, t_ray *ray);
void	print_ray(t_ray *ray);
void	print_render(t_render *render);

/* ray_casting.c */
void    render_raycast(t_game *game, t_render *render, t_ray *ray);

/* render.c */
void	generate_render(t_game *game);

#endif
