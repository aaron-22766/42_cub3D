#include "../../include/parser.h"

uint32_t	get_color(char *rgb)
{
	// convert
	(void)rgb;
	return (0);
}

void	set_game(t_parser *parser)
{
	parser->game->no_texture = mlx_load_png(parser->no_path);
	parser->game->so_texture = mlx_load_png(parser->so_path);
	parser->game->we_texture = mlx_load_png(parser->we_path);
	parser->game->ea_texture = mlx_load_png(parser->ea_path);
	if (!parser->game->no_texture || !parser->game->so_texture
		|| !parser->game->we_texture || !parser->game->ea_texture)
		parser_fail(parser, CUB_MLXFAIL, "loading textures");
	parser->game->floor_color = get_color(parser->floor_color);
	parser->game->ceiling_color = get_color(parser->ceiling_color);
}
