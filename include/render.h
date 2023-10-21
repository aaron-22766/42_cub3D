

typedef struct s_ray
{
	double		angle;
	double		distance;
	double		wall_height;
}	t_ray;

typedef struct s_render
{
	t_ray		rays[WINDOW_WIDTH];
}	t_render;

void	render_background(t_game *game);

void	generate_render(t_game *game);
