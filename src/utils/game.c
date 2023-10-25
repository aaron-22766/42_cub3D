

#include "../../include/cub3D.h"

void	init_game(t_game *game)
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

// To-do: free image, mlx, window, ...
// terminate game, then
void	free_game(t_game *game)
{
	free_map(&game->map);
	if (game->image)
		mlx_delete_image(game->mlx, game->image);
	if (game->no_texture)
		mlx_delete_texture(game->no_texture);
	if (game->so_texture)
		mlx_delete_texture(game->so_texture);
	if (game->we_texture)
		mlx_delete_texture(game->we_texture);
	if (game->ea_texture)
		mlx_delete_texture(game->ea_texture);
}

void	print_game(t_game *game)
{
	printf("\nGAME:\n");
	if (game->image)
		printf("Image - w: %d, h: %d\n", game->image->width,
			game->image->height);
	print_map(&game->map);
	printf("No texture - w: %d, h: %d\n", game->no_texture->width, game->no_texture->height);
	printf("So texture - w: %d, h: %d\n", game->so_texture->width, game->so_texture->height);
	printf("We texture - w: %d, h: %d\n", game->we_texture->width, game->we_texture->height);
	printf("Ea texture - w: %d, h: %d\n", game->ea_texture->width, game->ea_texture->height);
	printf("Ceiling color: %X\n", game->ceiling_color);
	printf("Floor color: %X\n", game->floor_color);
	print_player(&game->player);
}
