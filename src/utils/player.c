#include "../../include/utils.h"

void	init_player(t_player *player)
{
	set_pos(&player->pos, -1, -1, 0);
	player->orientation = 0.0;
	player->fov = M_PI / 3;
}

void	print_player(t_player *player)
{
	printf("Player orientation: %f\n", player->orientation);
	// printf("Player pos: %f, %f\n", player->pos.x, player->pos.y);
	print_pos(&player->pos);
	printf("Player Field of View: %.5f rad ~ %.1f rad\n",
		player->fov, player->fov * 180 / M_PI);
}
