#include "../../include/cub3D.h"

static void	set_hud(t_parser *parser)
{
	// *torch[TORCH_AMOUNT] & torch sprite sheet loop
	load_texture(parser, &parser->game->hud.torch_texture[0], TORCH1, false);
	load_texture(parser, &parser->game->hud.torch_texture[1], TORCH2, false);
	load_texture(parser, &parser->game->hud.torch_texture[2], TORCH3, false);
	load_texture(parser, &parser->game->hud.torch_texture[3], TORCH4, false);
	if ((((parser->game->ceiling_color >> 24) & 0xFF)
		+ ((parser->game->ceiling_color >> 16) & 0xFF)
		+ ((parser->game->ceiling_color >> 8) & 0xFF)) < (255 * 3) / 2)
		parser->game->hud.minimap_color = WHITE;
	parser->game->hud.torch_pos.y = WINDOW_HEIGHT
		- parser->game->hud.torch_texture[0]->height;
}

void	set_game(t_parser *parser)
{
	// *textures[4] & *path[4]
	load_texture(parser, &parser->game->no_texture, parser->no_path, true);
	load_texture(parser, &parser->game->ea_texture, parser->ea_path, true);
	load_texture(parser, &parser->game->so_texture, parser->so_path, true);
	load_texture(parser, &parser->game->we_texture, parser->we_path, true);
	load_color(parser, &parser->game->floor_color, parser->floor_color);
	load_color(parser, &parser->game->ceiling_color, parser->ceiling_color);
	parser->game->player.pos.x += 0.5;
	parser->game->player.pos.y += 0.5;
	set_hud(parser);
}
