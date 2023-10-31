#include "../../include/cub3D.h"

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->image = NULL;
	game->foreground = NULL;
	init_map(&game->map);
	game->no_texture = NULL;
	game->so_texture = NULL;
	game->we_texture = NULL;
	game->ea_texture = NULL;
	game->ceiling_color = 0;
	game->floor_color = 0;
	init_player(&game->player);
	game->torch[0] = NULL;
	game->torch[1] = NULL;
	game->torch[2] = NULL;
	game->torch[3] = NULL;
}

static void	delete_texture(mlx_texture_t *texture)
{
	if (texture)
		mlx_delete_texture(texture);
}

void	free_game(t_game *game)
{
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game->image)
		mlx_delete_image(game->mlx, game->image);
	if (game->foreground)
		mlx_delete_image(game->mlx, game->foreground);
	delete_texture(game->no_texture);
	delete_texture(game->so_texture);
	delete_texture(game->we_texture);
	delete_texture(game->ea_texture);
	delete_texture(game->torch[0]);
	delete_texture(game->torch[1]);
	delete_texture(game->torch[2]);
	delete_texture(game->torch[3]);
	free_map(&game->map);
}

void	game_fail(t_game *game, t_cub_errno err, char *context)
{
	ft_perror(err, context);
	free_game(game);
	exit(err);
}

void	print_game(t_game *game)
{
	printf("\nGAME:\n");
	if (game->image)
		printf("Image - w: %d, h: %d\n",
			game->image->width, game->image->height);
	printf("No texture - w: %d, h: %d\n",
		game->no_texture->width, game->no_texture->height);
	printf("So texture - w: %d, h: %d\n",
		game->so_texture->width, game->so_texture->height);
	printf("We texture - w: %d, h: %d\n",
		game->we_texture->width, game->we_texture->height);
	printf("Ea texture - w: %d, h: %d\n",
		game->ea_texture->width, game->ea_texture->height);
	printf("Ceiling color: %X\n", game->ceiling_color);
	printf("Floor color: %X\n", game->floor_color);
	print_player(&game->player);
	print_map(&game->map);
}
