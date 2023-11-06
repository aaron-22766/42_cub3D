#include "../../include/cub3D.h"

static void	set_config(t_parser *parser, char **config)
{
	if (*config)
		parser_fail(parser, CUB_DUPCONFIG, parser->split[0]);
	*config = ft_strdup(parser->split[1]);
}

static bool	create_config(t_parser *parser)
{
	if (!ft_strcmp(parser->split[0], "NO"))
		set_config(parser, &parser->texture_paths[NORTH]);
	else if (!ft_strcmp(parser->split[0], "EA"))
		set_config(parser, &parser->texture_paths[EAST]);
	else if (!ft_strcmp(parser->split[0], "SO"))
		set_config(parser, &parser->texture_paths[SOUTH]);
	else if (!ft_strcmp(parser->split[0], "WE"))
		set_config(parser, &parser->texture_paths[WEST]);
	else if (!ft_strcmp(parser->split[0], "F"))
		set_config(parser, &parser->floor_color);
	else if (!ft_strcmp(parser->split[0], "C"))
		set_config(parser, &parser->ceiling_color);
	else
		return (false);
	return (true);
}

bool	configs(t_parser *parser)
{
	bool	ret;

	ret = true;
	if (!is_empty_line(parser->line))
	{
		parser->split = ft_split(parser->line, ' ');
		ret = (ft_count_2d_array((void **)parser->split) == 2
				&& create_config(parser));
		ft_free_2d_array((void **)parser->split);
		parser->split = NULL;
	}
	return (ret);
}

static void	check_path(t_parser *parser, char *path, char *type)
{
	if (!path)
		parser_fail(parser, CUB_MISSCONFIG, type);
	if (!ft_strends(path, ".png"))
		parser_fail(parser, CUB_INVTEXTEXT, type);
}

void	check_configs(t_parser *parser)
{
	check_path(parser, parser->texture_paths[NORTH], "NO");
	check_path(parser, parser->texture_paths[EAST], "EA");
	check_path(parser, parser->texture_paths[SOUTH], "SO");
	check_path(parser, parser->texture_paths[WEST], "WE");
	if (!parser->floor_color)
		parser_fail(parser, CUB_MISSCONFIG, "F");
	if (!parser->ceiling_color)
		parser_fail(parser, CUB_MISSCONFIG, "C");
}
