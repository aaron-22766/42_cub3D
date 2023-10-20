#include "../../include/parser.h"

bool	is_empty_line(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
		if (!ft_strchr(WHITESPACE, line[i++]))
			return (false);
	return (true);
}

bool	is_valid_map_line(char *line)
{
	size_t	i;

	i = 0;
	while (line && line[i])
		if (!ft_strchr(MAP_CHARACTERS, line[i++]))
			return (false);
	return (!is_empty_line(line));
}

void	trim_newline(char *line)
{
	char	*nl;

	nl = ft_strrchr(line, '\n');
	if (nl && !nl[1])
		*nl = '\0';
}

void	print_parser(t_parser *parser)//DEBUG
{
	printf("\nPARSER\n");
	printf("file: %d\n", parser->scene_file);
	printf("line: %s\n", parser->line);
	printf("split: %p\n", parser->split);
	printf("north: %s\n", parser->no_path);
	printf("east: %s\n", parser->ea_path);
	printf("south: %s\n", parser->so_path);
	printf("west: %s\n", parser->we_path);
	printf("floor: %s\n", parser->floor_color);
	printf("ceiling: %s\n", parser->ceiling_color);
	print_map(&parser->game->map);
}
