#include "../../include/parser.h"

static void	set_config(t_parser *parser, char **config)
{
	if (*config)
		parser_fail(parser, CUB_DUPCONFIG, parser->split[0]);
	*config = ft_strdup(parser->split[1]);
}

static bool	create_config(t_parser *parser)
{
	if (!strcmp(parser->split[0], "NO"))
		set_config(parser, &parser->no_path);
	else if (!strcmp(parser->split[0], "SO"))
		set_config(parser, &parser->so_path);
	else if (!strcmp(parser->split[0], "WE"))
		set_config(parser, &parser->we_path);
	else if (!strcmp(parser->split[0], "EA"))
		set_config(parser, &parser->ea_path);
	else if (!strcmp(parser->split[0], "F"))
		set_config(parser, &parser->floor_color);
	else if (!strcmp(parser->split[0], "C"))
		set_config(parser, &parser->ceiling_color);
	else
		return (false);
	return (true);
}

void	configs(t_parser *parser)
{
	size_t	count;

	if (!parser->line[0])
		return ;
	parser->split = ft_split(parser->line, ' ');
	count = count_arr(parser->split);
	if (count == 2)
		parser->read = create_config(parser);
	else if (count != 0)
		parser->read = false;
	free_arr(parser->split);
	parser->split = NULL;
}

void	check_configs(t_parser *parser)
{
	if (!parser->no_path)
		parser_fail(parser, CUB_MISSCONFIG, "NO");
	if (!parser->so_path)
		parser_fail(parser, CUB_MISSCONFIG, "SO");
	if (!parser->we_path)
		parser_fail(parser, CUB_MISSCONFIG, "WE");
	if (!parser->ea_path)
		parser_fail(parser, CUB_MISSCONFIG, "EA");
	if (!parser->floor_color)
		parser_fail(parser, CUB_MISSCONFIG, "F");
	if (!parser->ceiling_color)
		parser_fail(parser, CUB_MISSCONFIG, "C");
}
