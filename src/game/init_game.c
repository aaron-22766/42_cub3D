#include "../../include/cub3D.h"

void	init_settings(t_game *game)
{
	game->mlx = NULL;
	game->no_texture = NULL;
	game->so_texture = NULL;
	game->we_texture = NULL;
	game->ea_texture = NULL;
	game->ceiling_color = 0;
	game->floor_color = 0;
	init_map(&game->map);
	init_player(&game->player);
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!game->mlx)
		ft_perror(CUB_MLXFAIL, "Failed to initialize MLX");
	
}
