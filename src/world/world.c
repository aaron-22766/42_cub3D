#include "../../include/cub3D.h"

void	draw_texture(t_game *game)
{
	t_pixel		pixel;

	pixel.y = 0;
	while (pixel.y < game->world.image->height)
	{
		pixel.x = 0;
		while (pixel.x < game->world.image->width)
		{
			pixel.color = get_pixel_txt(game->wall_textures[NORTH],
				pixel.x, pixel.y);
			mlx_put_pixel(game->world.image, pixel.x, pixel.y, pixel.color);
			pixel.x++;
		}
		pixel.y++;
	}
}

void	draw_world(t_game *game)
{
	init_world(game);
	draw_background(game);
	while (game->world.ray_index < game->world.image->width)
	{
		init_ray(&game->world);
		find_ray_intersection(game, &game->world.rays[game->world.ray_index]);
		draw_wall_slice(game, &game->world.rays[game->world.ray_index]);
		game->world.ray_index++;
	}
}
