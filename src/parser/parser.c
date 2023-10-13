#include "cub3D.h"

static void	init_parser(t_parser *parser, t_game *game)
{
	parser->game = game;
	parser->scene_file = -1;
	parser->line = NULL;
	parser->split = NULL;
	parser->no_path = NULL;
	parser->so_path = NULL;
	parser->we_path = NULL;
	parser->ea_path = NULL;
	parser->floor_color = NULL;
	parser->ceiling_color = NULL;
}

static void	free_parser(t_parser *parser)
{
	close(parser->scene_file);
	free(parser->line);
	free(parser->no_path);
	free(parser->so_path);
	free(parser->we_path);
	free(parser->ea_path);
	free(parser->floor_color);
	free(parser->ceiling_color);
	free_arr(parser->split);
}

void	parser_fail(t_parser *parser, t_cub_errno err, char *context)
{
	ft_perror(err, context);
	free_game(parser->game);
	free_parser(parser);
	exit(err);
}

static int	get_scene_file(char *path)
{
	int	fd;

	if (ft_strncmp(path + ft_strlen(path) - 4, ".cub", 4))
		exit(ft_perror(CUB_INVEXT, NULL));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit(ft_perror(CUB_ERRNO, path));
	return (fd);
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
		handle_line(&parser);
		free(parser.line);
	}
	print_parser(&parser);
	set_game(&parser);
	free_parser(&parser);
}
