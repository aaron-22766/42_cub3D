
#include "../../include/cub3D.h"

// static double	get_distance(t_pos *pos1, t_pos *pos2, int debug)
// {
// 	double	tmp_x;
// 	double	tmp_y;
// 	double	a,b;
// 	double	ans;

// 	tmp_x = pos1->x - pos2->x;
// 	tmp_y = pos1->y - pos2->y;
// 	if (debug) printf("Diff x: %lf\t Diff y: %lf\n", tmp_x, tmp_y); // Debug
// 	tmp_x = fabs(tmp_x);
// 	tmp_y = fabs(tmp_y);
// 	if (debug) printf("Abs x: %lf\t Abs y: %lf\n", tmp_x, tmp_y); // Debug
// 	tmp_x = tmp_x * tmp_x;
// 	a = tmp_y; // Debug
// 	b = tmp_y; // Debug
// 	if (debug) printf("a: %lf\t b: %lf\n", a, b); // Debug
// 	if (debug) printf("a * b: %lf\n", a * b); // Debug
// 	// tmp_y = (double) (a) * (double) (b);
// 	tmp_y = fma(a, b, 0.0);
// 	if (debug) printf("(dx)^2: %lf\t (dy)^2: %lf\n", tmp_x, tmp_y); // Debug
// 	ans = sqrt(tmp_x + tmp_y);
// 	if (debug) printf("Distance: %lf\n", ans); // Debug
// 	return (ans);
// }

static void	set_projection_values(t_game *game, t_render *render, t_ray *ray)
{
	double	dx;
	double	dy;
	int		p_w;
	int		p_h;

	dx = cos(ray->angle);
	dy = sin(ray->angle);
	p_h = floor(ray->pos.x);
	p_w = floor(ray->pos.y);
	if (!render->ray_index) printf("dx: %lf\n", dx); // Debug
	if (!render->ray_index) printf("dy: %lf\n", dy); // Debug
	if (!render->ray_index) printf("Before ray->pos.y: %lf\n", ray->pos.y); // Debug
	if (!render->ray_index) printf("Before ray->pos.x: %lf\n", ray->pos.x); // Debug
	while (fmin(p_w, p_h) >= 0 && p_h < game->map.height && p_w < game->map.widths[p_w] &&
		(game->map.map[p_h][p_w] != '1' || game->map.map[p_h][p_w] != ' '))
	{
		ray->pos.x += dx;
		ray->pos.y += dy;
		p_h = floor(ray->pos.x);
		p_w = floor(ray->pos.y);
	}
	if (!render->ray_index) printf("p_w: %d\n", p_w); // Debug
	if (!render->ray_index) printf("p_h: %d\n", p_h); // Debug
	// if (!render->ray_index) printf("Map[%d][%d]: %c\n", p_w, p_h, game->map.map[p_w][p_h]); // Debug
	ray->pos.x -= dx;
	ray->pos.y -= dy;
	ray->distance = sqrt(pow((double)fabs(game->player.pos.x - ray->pos.x), 2.0) +
						pow((double)(game->player.pos.y - ray->pos.y), 2.0));
	ray->pw_height = (ray->distance / (double) TEXTURE_HEIGHT) * (double) WINDOW_HEIGHT; // game->image->height
	// ray->pw_width = (ray->distance / (double) TEXTURE_WIDTH) * (double) WINDOW_WIDTH; // game->image->width
	ray->pw_width = ray->pw_height;
	ray->pw_top = ((double)game->image->height - ray->pw_height) / 2;
	ray->pw_bottom = ((double)game->image->height + ray->pw_height) / 2;
}

static mlx_texture_t	*get_texture(t_game *game, t_render *render, t_ray *ray)
{
	if (fabs(ray->pos.x - (int)ray->pos.x) < fabs(ray->pos.y - (int)ray->pos.y))
	{
		if (ray->angle > 0 && ray->angle < M_PI)
			return (game->no_texture);
		else
			return (game->so_texture);
	}
	else
	{
		if (ray->angle > M_PI / 2 && ray->angle < 3 * M_PI / 2)
			return (game->we_texture);
		else
			return (game->ea_texture);
	}	
}

/**
 * @brief 
 * 
 * @param game 
 * @param render 
 * @param ray 
 */

void    render_raycast(t_game *game, t_render *render, t_ray *ray)
{
	int		color;
	int32_t	img_col;
	int32_t	img_row;
	int 	p_x;
	int		p_y;

	set_projection_values(game, render, ray);
	ray->texture = get_texture(game, render, ray);
	// Debug
	if (render->ray_index % 1000 == 0) {
		printf("\nTexture: %p\n", ray->texture);
		printf("No: %p\n", game->no_texture);
		printf("So: %p\n", game->so_texture);
		printf("We: %p\n", game->we_texture);
		printf("Ea: %p\n", game->ea_texture);
		print_player(&game->player);
		print_render(render);
		print_ray(ray);
		print_map(&game->map); // Debug
	}
	img_col = ray->pw_top;
	img_row = render->ray_index;
	// p_y = (img_row - 0) * TEXTURE_WIDTH / ray->pw_width; // todo
	p_y = 32;
	while (img_col < (int)ray->pw_bottom)
	{
		p_x = (double)((img_col - ray->pw_top) * TEXTURE_HEIGHT) / ray->pw_height;
		// if (render->ray_index == 0) printf("p_x: %d\t p_y: %d\n", p_x, p_y); // Debug
		color = get_pixel_color(ray->texture, p_x, p_y);
		// if (render->ray_index == 0) print_pixel_rgba(color); // Debug
		mlx_put_pixel(game->image, img_col, img_row, color);
		img_col++;
	}
	if (render->ray_index == 0) print_pixel_rgba(color); // Debug
	if (render->ray_index == 0) printf("img_col: %d\t img_row: %d\n", img_col, img_row); // Debug
	if (render->ray_index == 0) printf("p_x: %d\t p_y: %d\n", p_x, p_y); // Debug
}

// TODO: Check if the x corresponds to the column and the y to the row
