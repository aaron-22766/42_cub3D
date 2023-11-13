#include "../../include/cub3D.h"

void	init_player(t_player *player)
{
	set_pos(&player->pos, -1, -1, 0.5);
	player->orientation = 0.0;
	player->default_fov = PLAYER_DEFAULT_FOV / 180.0 * M_PI;
	player->min_fov = PLAYER_MIN_FOV / 180.0 * M_PI;
	player->max_fov = PLAYER_MAX_FOV / 180.0 * M_PI;
	player->fov = player->default_fov;
	player->speed = PLAYER_NORMAL_SPEED;
}

void	print_player(t_player *player)
{
	printf("PLAYER:\n");
	printf("  - Orientation: %lf\n  - ", player->orientation);
	print_pos(&player->pos);
	printf("  - Field of View: %.5f rad ~ %.1f rad\n",
		player->fov, player->fov * 180 / M_PI);
}
