#include "../../include/parser.h"

static void	determine_element_type(t_parser *parser)
{
	parser->element_type = ELEMENT_INVALID;
	if (!parser->split || !parser->split[0])
		return ;
	if (!strcmp(parser->split[0], "NO"))
		parser->element_type = ELEMENT_NORTH;
	else if (!strcmp(parser->split[0], "SO"))
		parser->element_type = ELEMENT_SOUTH;
	else if (!strcmp(parser->split[0], "WE"))
		parser->element_type = ELEMENT_WEST;
	else if (!strcmp(parser->split[0], "EA"))
		parser->element_type = ELEMENT_EAST;
	else if (!strcmp(parser->split[0], "F"))
		parser->element_type = ELEMENT_FLOOR;
	else if (!strcmp(parser->split[0], "C"))
		parser->element_type = ELEMENT_CEILING;
}

static bool	is_valid_map_line(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
		if (!ft_strchr(MAP_CHARACTERS, line[i++]))
			return (false);
	return (true);
}

static void	create_element(t_parser *parser)
{
	if (parser->element_type == ELEMENT_NORTH && !parser->no_path)
		parser->no_path = ft_strdup(parser->split[1]);
	else if (parser->element_type == ELEMENT_SOUTH && !parser->so_path)
		parser->so_path = ft_strdup(parser->split[1]);
	else if (parser->element_type == ELEMENT_WEST && !parser->we_path)
		parser->we_path = ft_strdup(parser->split[1]);
	else if (parser->element_type == ELEMENT_EAST && !parser->ea_path)
		parser->ea_path = ft_strdup(parser->split[1]);
	else if (parser->element_type == ELEMENT_FLOOR && !parser->floor_color)
		parser->floor_color = ft_strdup(parser->split[1]);
	else if (parser->element_type == ELEMENT_CEILING && !parser->ceiling_color)
		parser->ceiling_color = ft_strdup(parser->split[1]);
	else
		parser_fail(parser, CUB_DUPCONFIG, parser->split[0]);
}

static void	read_map(t_parser *parser)
{
	(void)parser;
}

void	handle_line(t_parser *parser)
{
	size_t	nb_elements;
	char	*nl;

	if (parser->line[0] == '\n')
		return ;
	nl = ft_strrchr(parser->line, '\n');
	if (nl)
		*nl = '\0';
	parser->split = ft_split(parser->line, ' ');
	nb_elements = count_arr(parser->split);
	determine_element_type(parser);
	if (nb_elements == 2 && parser->element_type != ELEMENT_INVALID)
		create_element(parser);
	else if (nb_elements != 0 && is_valid_map_line(parser->line))
		read_map(parser);
	else if (nb_elements != 0)
		parser_fail(parser, CUB_INVLINE, parser->line);
	free_arr(parser->split);
	parser->split = NULL;
}
