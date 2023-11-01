#include "../../include/cub3D.h"

void	init_game(t_game *game)
{
	game->mlx = NULL;
	init_hud(&game->hud);
	game->image = NULL;
	init_map(&game->fix_map);
	init_map(&game->flex_map);
	game->no_texture = NULL;
	game->so_texture = NULL;
	game->we_texture = NULL;
	game->ea_texture = NULL;
	game->floor_color = 0;
	game->ceiling_color = 0;
	init_player(&game->player);
}

void	free_game(t_game *game)
{
	free_map(&game->fix_map);
	free_map(&game->flex_map);
	free_hud(game->mlx, &game->hud);
	delete_image(game->mlx, game->image);
	delete_texture(game->no_texture);
	delete_texture(game->so_texture);
	delete_texture(game->we_texture);
	delete_texture(game->ea_texture);
	if (game->mlx)
		mlx_terminate(game->mlx);
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
	print_map(&game->fix_map);
}
