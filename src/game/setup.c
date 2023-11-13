#include "../../include/cub3D.h"

static void	resize_texture(t_game *game, mlx_texture_t *texture)
{
	mlx_image_t	*temp;
	size_t		text_size;

	temp = mlx_texture_to_image(game->mlx, texture);
	if (!temp || !mlx_resize_image(temp, TILE_SIZE, TILE_SIZE))
		game_fail(game, CUB_MLXFAIL, "resizing texture");
	free(texture->pixels);
	text_size = TILE_SIZE * TILE_SIZE * sizeof(int32_t);
	texture->pixels = malloc(text_size);
	if (!texture->pixels)
		game_fail(game, CUB_MEMFAIL, "resizing texture");
	ft_memcpy(texture->pixels, temp->pixels, text_size);
	mlx_delete_image(game->mlx, temp);
	texture->width = TILE_SIZE;
	texture->height = TILE_SIZE;
}

static void	resize_textures(t_game *game)
{
	t_textures	i;

	i = NORTH;
	while (i <= DOOR - !game->fix_map.has_door)
		resize_texture(game, game->wall_textures[i++]);
}

void	setup_pause_screen(t_game *game)
{
	game->pause_screen = mlx_new_image(game->mlx, game->mlx->width,
			game->mlx->height);
	if (!game->pause_screen)
		game_fail(game, CUB_MLXFAIL, "Failed to create image");
	render_pause_screen(game);
	if (mlx_image_to_window(game->mlx, game->pause_screen, 0, 0) == -1)
		game_fail(game, CUB_MLXFAIL, "Failed to render image");
	mlx_set_instance_depth(game->pause_screen->instances, 3);
}

void	setup_game(t_game *game)
{
	game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D", true);
	if (!game->mlx)
		game_fail(game, CUB_MLXFAIL, "Failed to initialize MLX");
	game->too_small_image = mlx_put_string(game->mlx, "Window too small", 0, 0);
	if (!game->too_small_image)
		game_fail(game, CUB_MLXFAIL, "Failed to create image");
	mlx_set_instance_depth(game->too_small_image->instances, 0);
	resize_textures(game);
	game->player.pos.x += 0.5;
	game->player.pos.y += 0.5;
	setup_world(game);
	setup_hud(game);
	setup_pause_screen(game);
}
