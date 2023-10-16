
#include "../../include/parser.h"

int	get_scene_file(char *path)
{
	int	fd;

	if (ft_strncmp(path + ft_strlen(path) - 4, ".cub", 4))
		exit(ft_perror(CUB_INVEXT, NULL));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit(ft_perror(CUB_ERRNO, path));
	return (fd);
}

static void	trim_newline(char *line)
{
	char	*nl;

	nl = ft_strrchr(line, '\n');
	if (nl && !nl[1])
		*nl = '\0';
}

void	read_file(t_parser *parser, void (*f)(t_parser *))
{
	while (parser->read)
	{
		parser->line = get_next_line(parser->scene_file);
		trim_newline(parser->line);
		f(parser);
		free(parser->line);
		parser->line = NULL;
	}
	parser->read = true;
}
