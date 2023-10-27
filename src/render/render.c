
#include "../../include/cub3D.h"

t_render	init_render(t_game *game)
{
	t_render	render;

	render.ray_index = 0;
	render.theta = game->player.orientation + (game->player.fov / 2);
	if (render.theta > 2 * M_PI)
		render.theta -= 2 * M_PI;
	render.delta = game->player.fov / (double) game->image->width;
	render.img_pixel.x = 0;
	render.img_pixel.y = 0;
	render.img_pixel.color = 0;
	render.distance = (game->image->width / 2) / tan(game->player.fov / 2) * TILE_SIZE;
	render.pov = init_vector(game->player.pos.x, game->player.pos.y, game->player.pos.z);
	return (render);
}

void	update_render(t_render *render)
{
	render->ray_index++;
	render->theta -= render->delta;
	if (render->theta < 0)
		render->theta += 2 * M_PI;
	render->img_pixel.x++;
	render->img_pixel.y = 0;
	// Maybe also update render->distance?
}

void	print_render(t_render *render)
{
	printf("\nRENDER:\n");
	printf(" ray_index: %zu\n", render->ray_index);
	printf(" theta: %f\n", render->theta);
	printf(" delta: %f\n", render->delta);
	printf("  img.x: %d\n", render->img_pixel.x);
	printf("  img.y: %d\n", render->img_pixel.y);
	printf("  img.color: %d\n", render->img_pixel.color);
	printf(" distance (from POV to Projection Plane): %f\n", render->distance);
	print_vector(&render->pov, "  pov:", true);
}
