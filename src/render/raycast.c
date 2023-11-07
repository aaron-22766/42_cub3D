
#include "../../include/cub3D.h"

// void	render_raycast(t_game *game, t_ray *ray)
// {
// 	t_pixel		pixel;

// 	pixel.x = ray->id;
//     double omega = fabs(ray->angle - game->player.orientation) ;
//     double tile = (double) TILE_SIZE;
//     double iw = (double) game->image->width;
//     double d = (double) ray->length;
//     double h = (tile * ((iw / 2.0) / tan(omega)) / d);
//     printf("h: %f\n", h);
//     u_int32_t uh = (u_int32_t) h;
// // return ;
//     pixel.y = fmin((game->image->height - uh) / 2, 10);
// 	while (pixel.y < fmax((game->image->height + uh) / 2, game->image->height-10))
// 	{
//         if (fmin(pixel.x, pixel.y) < 0 || fmax(pixel.x, pixel.y) > game->image->width)
//         {
//             pixel.y++;
//             continue;
//         }
// 		mlx_put_pixel(game->image, pixel.x, pixel.y, get_pixel_color(ray->texture, 1, 1));
// 		pixel.y++;
// 	}
// }

void	render_raycast(t_game *game, t_ray *ray)
{
    double  tile = (double) TILE_SIZE;
    double  iw_half = (double) WINDOW_WIDTH / 2.0;
    double  d_player_pp = iw_half / tan(game->player.fov / 2.0);
    double  d_player_wall = ray->length;
    double  h = tile * (d_player_pp / d_player_wall);

    // if (!ray->id) {
    //     printf("tile: %f\n", tile);
    //     printf("iw_half: %f\n", iw_half);
    //     printf("d_player_pp: %f\n", d_player_pp);
    //     printf("d_player_wall: %f\n", d_player_wall);
    //     printf("h: %f\n", h);
    // }
    u_int32_t a = (WINDOW_HEIGHT - h) / 2.0;
    u_int32_t b = (WINDOW_HEIGHT + h) / 2.0;
    t_pixel pixel;
    // pixel.x = WINDOW_WIDTH - ray->id - 1;
    pixel.x = ray->id;
    pixel.y = a;
    pixel.color = get_pixel_color(ray->texture, 1, 1);
    while (pixel.y < b)
    {
        mlx_put_pixel(game->image, pixel.x, pixel.y, pixel.color);
        pixel.y++;
    }
}