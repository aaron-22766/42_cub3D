#include "../../include/cub3D.h"

void	draw_texture(t_game *game, mlx_texture_t *texture)
{
	t_pixel	pixel;

	pixel.y = 0;
	while (pixel.y < texture->height)
	{
		pixel.x = 0;
		while (pixel.x < texture->width)
		{
			pixel.color = get_pixel_txt(texture,
					pixel.x, pixel.y);
			mlx_put_pixel(game->world.image, pixel.x, pixel.y, pixel.color);
			pixel.x++;
		}
		pixel.y++;
	}
}

void	draw_world(t_game *game)
{
	reset_world(game);
	draw_background(game);
	while (game->world.ray_index < game->world.image->width)
	{
		init_ray(&game->world);
		find_ray_intersection(game, &game->world.rays[game->world.ray_index]);
		draw_wall_slice(game, &game->world.rays[game->world.ray_index]);
		game->world.ray_index++;
	}
}
