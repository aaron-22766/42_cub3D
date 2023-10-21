
#include "../../include/cub3D.h"

void	init_settings(t_game *game)
{
	game->mlx = NULL;
	game->image = NULL;
	init_map(&game->map);
	game->no_texture = NULL;
	game->so_texture = NULL;
	game->we_texture = NULL;
	game->ea_texture = NULL;
	game->ceiling_color = 0;
	game->floor_color = 0;
	init_player(&game->player);
}

void	init_game(t_game *game)
{
	printf("Initializing game\n");			// DEBUG
	game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D", false);
	if (!game->mlx)
		ft_perror(CUB_MLXFAIL, "Failed to initialize MLX");
	game->image = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->image)
		ft_perror(CUB_MLXFAIL, "Failed to create image");
	if (mlx_image_to_window(game->mlx, game->image, 0, 0))
		ft_perror(CUB_MLXFAIL, "Failed to create window");
	// game->no_texture = mlx_xpm_file_to_image(game->mlx, game->map.no_texture_path, &game->map.no_texture_width, &game->map.no_texture_height);
	printf("Game initialized\n");			// DEBUG
}
