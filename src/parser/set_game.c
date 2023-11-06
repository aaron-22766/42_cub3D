#include "../../include/cub3D.h"

void	set_game(t_parser *parser)
{
	t_cardinal_point	i;

	i = NORTH;
	while (i <= WEST)
	{
		load_texture(parser, &parser->game->wall_textures[i],
			parser->texture_paths[i], true);
		i++;
	}
	load_color(parser, &parser->game->floor_color, parser->floor_color);
	load_color(parser, &parser->game->ceiling_color, parser->ceiling_color);
	set_hud(parser);
}
