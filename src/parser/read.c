#include "../../include/cub3D.h"

static void	read_loop(t_parser *parser, bool (*f)(t_parser *))
{
	while (parser->line)
	{
		trim_newline(parser->line);
		if (f(parser) == false)
			return ;
		free(parser->line);
		parser->line = get_next_line(parser->scene_file);
	}
}

static bool	empty_lines(t_parser *parser)
{
	return (is_empty_line(parser->line));
}

void	read_file(t_parser *parser)
{
	parser->line = get_next_line(parser->scene_file);
	read_loop(parser, empty_lines);
	if (!parser->line)
		parser_fail(parser, CUB_EMPTYFILE, NULL);
	read_loop(parser, configs);
	read_loop(parser, map);
	read_loop(parser, empty_lines);
	if (!parser->line)
		return ;
	if (is_valid_map_line(parser->line))
		parser_fail(parser, CUB_EMPTYLINE, NULL);
	else
		parser_fail(parser, CUB_INVLINE, parser->line);
}
