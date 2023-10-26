
#include "../../include/cub3D.h"

void	init_raycast_frame(t_game *game, t_render *render)
{
	render->ray_index = 0;
	render->alpha = game->player.orientation - (game->player.fov / 2);
	render->delta = game->player.fov / (double) game->image->width;
	// render->pos = set_pos(game->map.max_width - game->player.pos.y, game->player.pos.x, 0);
	set_pos(&render->pos, game->player.pos.x, game->player.pos.y, 0);
	render->img_col = 0;
	render->img_row = 0;
}

void	print_render(t_render *render)
{
	printf("\nRENDER:\n");
	printf(" ray_index: %zu\n", render->ray_index);
	printf(" angle: %f\n", render->alpha);
	printf(" delta: %f\n", render->delta);
	print_pos(&render->pos);
}
