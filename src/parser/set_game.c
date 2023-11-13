#include "../../include/cub3D.h"

void	set_game(t_parser *parser)
{
	t_textures	i;

	if (parser->game->fix_map.has_door && !parser->texture_paths[DOOR])
		parser_fail(parser, CUB_MISSCONFIG, "D");
	i = NORTH;
	while (i <= DOOR - !parser->game->fix_map.has_door)
	{
		load_texture(parser, &parser->game->wall_textures[i],
			parser->texture_paths[i], true);
		i++;
	}
	load_texture(parser, &parser->game->pause_texture, PAUSE_PATH, true);
	load_color(parser, &parser->game->floor_color, parser->floor_color);
	load_color(parser, &parser->game->ceiling_color, parser->ceiling_color);
	set_hud(parser);
}
