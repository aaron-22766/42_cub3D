#include "../../include/cub3D.h"

void	init_game(t_game *game)
{
	t_cardinal_point	i;

	game->mlx = NULL;
	init_hud(&game->hud);
	game->image = NULL;
	init_map(&game->fix_map);
	init_map(&game->flex_map);
	init_player(&game->player);
	i = NORTH;
	while (i <= WEST)
		game->wall_textures[i++] = NULL;
	game->floor_color = 0;
	game->ceiling_color = 0;
	game->time = 0;
	game->fps = 0;
	game->mouse_x = 0;
	game->collision = MINIMAP_PLAYER_RADIUS / MINIMAP_TILE_SIZE;
}

void	free_game(t_game *game)
{
	t_cardinal_point	i;

	free_map(&game->fix_map);
	free_map(&game->flex_map);
	free_hud(game->mlx, &game->hud);
	delete_image(game->mlx, game->image);
	i = NORTH;
	while (i <= WEST)
		delete_texture(game->wall_textures[i++]);
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
		game->wall_textures[NORTH]->width, game->wall_textures[NORTH]->height);
	printf("Ea texture - w: %d, h: %d\n",
		game->wall_textures[EAST]->width, game->wall_textures[EAST]->height);
	printf("So texture - w: %d, h: %d\n",
		game->wall_textures[SOUTH]->width, game->wall_textures[SOUTH]->height);
	printf("We texture - w: %d, h: %d\n",
		game->wall_textures[WEST]->width, game->wall_textures[WEST]->height);
	printf("Ceiling color: %X\n", game->ceiling_color);
	printf("Floor color: %X\n", game->floor_color);
	print_player(&game->player);
	print_map(&game->fix_map);
}
