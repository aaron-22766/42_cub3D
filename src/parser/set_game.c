#include "../../include/cub3D.h"

void	set_game(t_parser *parser)
{
	uint8_t	cardinal_point;

	cardinal_point = NORTH;
	while (cardinal_point <= WEST)
	{
		load_texture(parser, &parser->game->wall_textures[cardinal_point],
			parser->texture_paths[cardinal_point], true);
		cardinal_point++;
	}
	load_color(parser, &parser->game->floor_color, parser->floor_color);
	load_color(parser, &parser->game->ceiling_color, parser->ceiling_color);
	set_hud(parser);
}
