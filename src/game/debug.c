#include "../../include/cub3D.h"

void	print_game(t_game *game)			//DEBUG
{
	printf("\nGAME:\n");
	printf("Resolution: %dx%d\n", WINDOW_HEIGHT, WINDOW_WIDTH);
	// printf("North texture: %p\n", game->no_texture);
	// printf("East texture: %p\n", game->ea_texture);
	// printf("South texture: %p\n", game->so_texture);
	// printf("West texture: %p\n", game->we_texture);
	printf("Floor color: %x\n", game->floor_color);
	printf("Ceiling color: %x\n", game->ceiling_color);
	printf("Player orientation: %f\n", game->player.orientation);
	printf("Player pos: %f, %f\n", game->player.pos.x, game->player.pos.y);
	// print_map(&game->map);
}

void	print_player(t_player *player)		//DEBUG
{
	printf("\nPLAYER:\n");
	printf("Orientation: %f\n", player->orientation);
	printf("Pos: %f, %f\n", player->pos.x, player->pos.y);
}
