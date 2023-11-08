#include "../../include/cub3D.h"

static void	render_black_screen(t_game *game)
{
	uint32_t	x;
	uint32_t	y;

	y = 0;
	while (y < game->pause_screen->height)
	{
		x = 0;
		while (x < game->pause_screen->width)
			mlx_put_pixel(game->pause_screen, x++, y, BLACK);
		y++;
	}
	delete_image(game->mlx, game->pause_text);
	game->pause_text = mlx_put_string(game->mlx, "Window too small", 0, 0);
	mlx_set_instance_depth(game->pause_text->instances, 4);
}

void	resize(int32_t width, int32_t height, void *param)
{
	t_game	*game;

	game = param;
	if ((uint32_t)height < game->hud.minimap_center * 2
		|| (uint32_t)height < game->hud.torch_textures[0]->height
		|| (uint32_t)width < game->hud.minimap_center * 2
		|| ((uint32_t)width / 7) * 5 > (uint32_t)width
		- game->hud.torch_textures[0]->width)
	{
		game->too_small = true;
		render_black_screen(game);
		return ;
	}
	game->too_small = false;
	game->mlx->width = width;
	game->mlx->height = height;
	game->hud.torch_pos.x = (game->mlx->width / 7) * 5;
	game->hud.torch_pos.y = game->mlx->height
		- game->hud.torch_textures[0]->height;
	reset_game(game);
}
