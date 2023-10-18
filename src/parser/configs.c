#include "../../include/parser.h"

static void	set_config(t_parser *parser, char **config)
{
	if (*config)
		exit_parser(parser, CUB_DUPCONFIG, parser->split[0]);
	*config = ft_strdup(parser->split[1]);
}

static bool	create_config(t_parser *parser)
{
	if (!strcmp(parser->split[0], "NO"))
		set_config(parser, &parser->no_path);
	else if (!strcmp(parser->split[0], "EA"))
		set_config(parser, &parser->ea_path);
	else if (!strcmp(parser->split[0], "SO"))
		set_config(parser, &parser->so_path);
	else if (!strcmp(parser->split[0], "WE"))
		set_config(parser, &parser->we_path);
	else if (!strcmp(parser->split[0], "F"))
		set_config(parser, &parser->floor_color);
	else if (!strcmp(parser->split[0], "C"))
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
		ret = (count_arr(parser->split) == 2 && create_config(parser));
		free_arr(parser->split);
		parser->split = NULL;
	}
	return (ret);
}

static void	texture_extension(t_parser *parser, char *path)
{
	if (ft_strncmp(path + ft_strlen(path) - 4, ".png", 4))
		exit_parser(parser, CUB_INVTEXTEXT, NULL);
}

void	check_configs(t_parser *parser)
{
	if (!parser->no_path)
		exit_parser(parser, CUB_MISSCONFIG, "NO");
	if (!parser->so_path)
		exit_parser(parser, CUB_MISSCONFIG, "EA");
	if (!parser->floor_color)
		exit_parser(parser, CUB_MISSCONFIG, "SO");
	if (!parser->we_path)
		exit_parser(parser, CUB_MISSCONFIG, "WE");
	if (!parser->ea_path)
		exit_parser(parser, CUB_MISSCONFIG, "F");
	if (!parser->ceiling_color)
		exit_parser(parser, CUB_MISSCONFIG, "C");
	texture_extension(parser, parser->no_path);
	texture_extension(parser, parser->ea_path);
	texture_extension(parser, parser->so_path);
	texture_extension(parser, parser->we_path);
}
