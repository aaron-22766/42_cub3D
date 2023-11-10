#include "../../include/cub3D.h"

static void	images_set_enabled(t_game *game, bool setting)
{
	game->pause_screen->enabled = setting;
	game->image->enabled = setting;
	game->hud.image->enabled = setting;
}

static bool	too_small(t_game *game)
{
	if ((uint32_t)game->mlx->height >= game->pause_texture->height
		&& (uint32_t)game->mlx->width >= game->pause_texture->width)
		return (false);
	if (game->too_small)
		return (true);
	game->too_small = true;
	images_set_enabled(game, false);
	return (true);
}

void	resize_game(t_game *game)
{
	game->resized = false;
	if (too_small(game))
		return ;
	game->too_small = false;
	images_set_enabled(game, true);
	if (game->pause_screen->width == (uint32_t)game->mlx->width
		&& game->pause_screen->height == (uint32_t)game->mlx->height)
		return ;
	delete_image(game->mlx, game->image);
	delete_image(game->mlx, game->hud.image);
	delete_image(game->mlx, game->pause_screen);
	setup_world(game);
	setup_hud(game);
	setup_pause_screen(game);
}

void	resize_window(int32_t width, int32_t height, void *param)
{
	t_game	*game;

	game = param;
	game->mlx->width = width;
	game->mlx->height = height;
	game->resized = true;
}
