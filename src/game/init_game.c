#include "../../include/cub3D.h"

void	init_settings(t_game *game)
{
	game->mlx = NULL;
	init_map(&game->map);
	game->no_texture = NULL;
	game->so_texture = NULL;
	game->we_texture = NULL;
	game->ea_texture = NULL;
	game->ceiling_color = 0;
	game->floor_color = 0;
	game->orientation = 0;
}
