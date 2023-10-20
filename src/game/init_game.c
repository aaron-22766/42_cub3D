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
	game->player.orientation = 0.0;
	game->player.pos.x = -1;
	game->player.pos.y = -1;
	
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!game->mlx)
		ft_perror(CUB_MLXFAIL, "Failed to initialize MLX");
	
}
