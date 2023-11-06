
#include "../../include/render.h"

// static void	set_projection_values(t_game *game, t_render *render, t_ray *ray)
// {
// 	double	dx;
// 	double	dy;
// 	int		p_w;
// 	int		p_h;

// 	// dx = cos(ray->angle);
// 	// dy = sin(ray->angle);
// 	// With a 90° counter-clockwise rotation
// 	dx = sin(ray->angle);
// 	dy = -cos(ray->angle);
// 	p_h = floor(ray->pos.x);
// 	p_w = floor(ray->pos.y);
// 	while (fmin(p_w, p_h) >= 0 && p_h < game->map.height && p_w < game->map.widths[p_w] &&
// 		(game->map.map[p_h][p_w] != '1' || game->map.map[p_h][p_w] != ' '))
// 	{
// 		ray->pos.x += dx;
// 		ray->pos.y += dy;
// 		p_h = floor(ray->pos.x);
// 		p_w = floor(ray->pos.y);
// 	}
// 	ray->pos.x -= dx;
// 	ray->pos.y -= dy;
// 	ray->length = sqrt(pow((double)fabs(game->player.pos.x - ray->pos.x), 2.0) +
// 						pow((double)(game->player.pos.y - ray->pos.y), 2.0));
// 	ray->pw_height = (ray->length / (double) TILE_SIZE) * (double) WINDOW_HEIGHT;
// 	// ray->pw_width = (ray->length / (double) TILE_SIZE) * (double) WINDOW_WIDTH; // game->image->width
// 	ray->pw_width = ray->pw_height;
// 	ray->pw_top = ((double)game->image->height - ray->pw_height) / 2;
// 	ray->pw_bottom = ((double)game->image->height + ray->pw_height) / 2;
// }

// static 

// /**
//  * @brief 
//  * 
//  * @param game 
//  * @param render 
//  * @param ray 
//  */

// void    render_raycast(t_game *game, t_render *render, t_ray *ray)
// {
// 	uint32_t	color;
// 	static uint32_t	p_x;
// 	static uint32_t	p_y;

// 	set_projection_values(game, render, ray);
// 	ray->texture = get_texture(game, render, ray);
// 	// if (render->ray_index > 0 && render->rays[render->ray_index - 1].texture == ray->texture)
// 	// 	p_y = fmin(p_y + 1, TILE_SIZE - 1);
// 	// 	p_y = fmin(p_y + 1, TILE_SIZE - 1);
// 	// else
// 		p_y = 32;
// 	render->img_col = ray->pw_top;
// 	render->img_row = render->ray_index;
// 	while (render->img_col < (uint32_t)ray->pw_bottom)
// 	{
// 		// p_x = ((render->img_col - ray->pw_top) * TILE_SIZE) / ray->pw_height;
// 		// p_x = ((render->img_col - ray->pw_top) * TILE_SIZE) / ray->pw_height;
// 		p_x = 32;
// 		color = get_pixel_color(ray->texture, p_x, p_y);
// 		mlx_put_pixel(game->image, render->img_row, render->img_col, color);
// 		render->img_col++;
// 	}
// }

// // TODO: Check if the x corresponds to the column and the y to the row

void	render_raycast(t_game *game, t_ray *ray)
{
	t_pixel		pixel;

	pixel.x = ray->id;
	// uint32_t distance_to_projection_plane =  fabs() + (WINDOW_WIDTH / 2) / tan(M_PI / 6);
	// uint32_t heigth_projection_plane = (TILE_SIZE * distance_to_projection_plane) / ray->length;
    // uint32_t dtpp = sqrt(pow((WINDOW_WIDTH / 2), 2) + pow(ray->id - (WINDOW_WIDTH / 2), 2) / tan(M_PI / 6));
	// uint32_t heigth_projection_plane = (TILE_SIZE * dtpp) / ray->length;
	// pixel.y = (game->image->height - heigth_projection_plane) / 2;
    double omega = fabs(ray->angle - game->player.orientation) ; //+ game->player.fov / 2;
    // uint32_t p2pp =  ((double) WINDOW_WIDTH / 2.0) / tan(omega );
    // uint32_t h = (TILE_SIZE * p2pp) / ray->length;
    printf("omega: %f\n", omega);
    printf("ray->length: %lld\n", ray->length);
    double tile = (double) TILE_SIZE;
    double iw = (double) game->image->width;
    double d = (double) ray->length;
    double h = (tile * ((iw / 2.0) / tan(omega)) / d);
    printf("h: %f\n", h);
    u_int32_t uh = (u_int32_t) h;

    pixel.y = fmin((game->image->height - uh) / 2, 10);
    printf("pixel.y: %d\n", pixel.y);
    printf("pixel.x: %d\n", pixel.x); 
    return;
	while (pixel.y < fmax((game->image->height + uh) / 2, game->image->height-10))
	{
        if (fmin(pixel.x, pixel.y) < 0 || fmax(pixel.x, pixel.y) > game->image->width)
        {
            pixel.y++;
            continue;
        }
		mlx_put_pixel(game->image, pixel.x, pixel.y, get_pixel_color(ray->texture, 1, 1));
		pixel.y++;
	}
}
