
#include "../../include/cub3D.h"

t_render	init_render(t_game *game)
{
	t_render	render;

	render.ray_index = 0;
	render.alpha = game->player.orientation - (game->player.fov / 2);
	render.delta = game->player.fov / (double) game->image->width;
	render.img_pixel.x = 0;
	render.img_pixel.y = 0;
	render.img_pixel.color = 0;
	render.pov = init_vector(game->player.pos.x, game->player.pos.y, game->player.pos.z);
	return (render);
}

void	print_render(t_render *render)
{
	printf("\nRENDER:\n");
	printf(" ray_index: %zu\n", render->ray_index);
	printf(" alpha: %f\n", render->alpha);
	printf(" delta: %f\n", render->delta);
	printf("  img.x: %d\n", render->img_pixel.x);
	printf("  img.y: %d\n", render->img_pixel.y);
	printf("  img.color: %d\n", render->img_pixel.color);
	print_vector(&render->pov, "  pov:", true);
}
