#include "../../include/parser.h"

static void	load_texture(t_parser *parser, mlx_texture_t **texture, char *path)
{
	*texture = mlx_load_png(path);
	if (!(*texture))
		parser_fail(parser, CUB_MLXFAIL, "loading textures");
}

static bool	is_valid_rgb(char *rgb)
{
	size_t	i;

	i = 0;
	while (rgb[i])
	{
		if (!ft_isdigit(rgb[i]) && rgb[i] != ',')
			return (false);
		i++;
	}
	return (i < 12);
}

static void	load_color(t_parser *parser, uint32_t *color, char *rgb)
{
	char	**split;
	int		red;
	int		green;
	int		blue;

	split = ft_split(rgb, ',');
	if (!is_valid_rgb(rgb) || count_arr(split) != 3 || ft_strlen(split[0]) > 3
		|| ft_strlen(split[1]) > 3 || ft_strlen(split[2]) > 3)
	{
		free_arr(split);
		parser_fail(parser, CUB_INVCOLOR, rgb);
	}
	red = ft_atoi(split[0]);
	green = ft_atoi(split[1]);
	blue = ft_atoi(split[2]);
	free_arr(split);
	if (red > 255 || green > 255 || blue > 255)
		parser_fail(parser, CUB_INVCOLOR, rgb);
	*color = ft_pixel(red, green, blue, 0);
}

static void	copy_map(t_parser *parser)
{
	size_t	i;

	parser->game->map.map = ft_calloc(parser->map.height, sizeof(char *));
	if (!parser->game->map.map)
		parser_fail(parser, CUB_MEMFAIL, "copying map");
	i = 0;
	while (i < parser->map.height)
	{
		parser->game->map.map[i] = ft_strdup(parser->map.map[i]);
		if (!parser->game->map.map[i])
			parser_fail(parser, CUB_MEMFAIL, "copying map");
		i++;
	}
}

void	set_game(t_parser *parser)
{
	load_texture(parser, &parser->game->no_texture, parser->no_path);
	load_texture(parser, &parser->game->so_texture, parser->so_path);
	load_texture(parser, &parser->game->we_texture, parser->we_path);
	load_texture(parser, &parser->game->ea_texture, parser->ea_path);
	load_color(parser, &parser->game->floor_color, parser->floor_color);
	load_color(parser, &parser->game->ceiling_color, parser->ceiling_color);
	copy_map(parser);
}
