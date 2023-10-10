
#include "cub3D.h"

static void	game_loop(t_game *game)
{
	// Render Background
	// Render Map
	// Render Minimap
	mlx_key_hook(game->mlx, key_hook, game);
	mlx_loop(game->mlx);
}

static init_settings(t_game *game)
{
	game->speed = SPEED;
	game->window_height = HEIGHT;
	game->window_width = WIDTH;
	game->map = game->parser->map->map;
	game->player_pos = game->parser->player;
	game->no_texture = game->parser->wall_n_txt;
	game->so_texture = game->parser->wall_s_txt;
	game->we_texture = game->parser->wall_w_txt;
	game->ea_texture = game->parser->wall_e_txt;
}

int	init_game(t_game *game)
{
	init_settings(game);
	game->mlx = mlx_init(game->window_width, game->window_height, "Cub3d", false);
	game_loop(game);
	return (0);
}