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
		set_config(parser, &parser->no_path);
	else if (!ft_strcmp(parser->split[0], "EA"))
		set_config(parser, &parser->ea_path);
	else if (!ft_strcmp(parser->split[0], "SO"))
		set_config(parser, &parser->so_path);
	else if (!ft_strcmp(parser->split[0], "WE"))
		set_config(parser, &parser->we_path);
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
	check_path(parser, parser->no_path, "NO");
	check_path(parser, parser->ea_path, "EA");
	check_path(parser, parser->so_path, "SO");
	check_path(parser, parser->we_path, "WE");
	if (!parser->ea_path)
		parser_fail(parser, CUB_MISSCONFIG, "F");
	if (!parser->ceiling_color)
		parser_fail(parser, CUB_MISSCONFIG, "C");
}
