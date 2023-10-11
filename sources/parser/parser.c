#include "cub3D.h"

static int	get_scene_file(char *path)
{
	int	fd;

	if (ft_strncmp(path + ft_strlen(path) - 4,  ".cub", 4))
		exit(ft_perror(CUB_INVEXT, NULL));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit(ft_perror(CUB_ERRNO, "Failed to open file"));
	return (fd);
}

static void	handle_line(t_game *game, char *line)
{
	printf("%s", line);
	(void)game;
}

void	init_parser(t_parser *parser, t_game *game)
{
	parser->game = game;
	parser->scene_file = -1;
	parser->line = NULL;
	parser->error = CUB_SUCCESS;
}

void	parse(t_game *game, int argc, char **argv)
{
	t_parser	parser;

	if (argc < 2)
		exit(ft_perror(CUB_INVARGS, "few"));
	else if (argc > 2)
		exit(ft_perror(CUB_INVARGS, "many"));
	init_parser(&parser, game);
	parser.scene_file = get_scene_file(argv[1]);
	while (true)
	{
		parser.line = get_next_line(parser.scene_file);
		if (!parser.line)
			break ;
		handle_line(game, parser.line);
		free(parser.line);
	}
	close(parser.scene_file);
	if (parser.error)
		exit(parser.error);
}
