#include "../../include/utils.h"

void	init_player(t_player *player)
{
	player->orientation = 0.0;
	// player->pos.x = -1;
	// player->pos.y = -1;
	// player->pos.z = 0;
	set_pos(&player->pos, -1, -1, 0);
	player->fov = M_PI / 3;
}

void	print_player(t_player *player)
{
	printf("Player orientation: %f\n", player->orientation);
	printf("Player pos: %f, %f\n", player->pos.x, player->pos.y);
}
