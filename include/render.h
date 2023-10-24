
#ifndef RENDER_H
# define RENDER_H

# define WINDOW_HEIGHT 720
# define WINDOW_WIDTH 1080

typedef struct s_game	t_game;

typedef struct s_ray
{
	double			angle;
	t_pos			pos;		// Projection position
	double			distance;
	double			p_wall_top;
	double			p_wall_bottom;
	double			p_wall_height;
	mlx_texture_t	*texture;

}	t_ray;

typedef struct s_render
{
	t_ray		rays[WINDOW_WIDTH];
	double		angle;
	double		angle_increment;
	size_t		ray_index;
	double		wall_height;
	double		wall_width;
	t_pos		pos;	// player position
}	t_render;


/* background.c */
void	render_background(t_game *game);

/* init_ray_cast.c */
void	init_raycast_frame(t_game *game, t_render *render);
void	init_single_ray(t_game *game, t_render *render, t_ray *ray);

/* render.c */
void	generate_render(t_game *game);

#endif
