#include "../../include/parser.h"

static void	init_parser(t_parser *parser)
{
	parser->no_path = NULL;
	parser->so_path = NULL;
	parser->we_path = NULL;
	parser->ea_path = NULL;
	parser->floor_color = NULL;
	parser->ceiling_color = NULL;
	parser->scene_file = -1;
	parser->line = NULL;
	parser->split = NULL;
	parser->vis = NULL;
	parser->game = NULL;
}

static int	get_input(int argc, char **argv)
{
	int	fd;

	if (argc < 2)
		exit(ft_perror(CUB_INVARGS, "few"));
	else if (argc > 2)
		exit(ft_perror(CUB_INVARGS, "many"));
	if (!ft_strends(argv[1], ".cub"))
		exit(ft_perror(CUB_INVFILEEXT, NULL));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(ft_perror(CUB_ERRNO, argv[1]));
	return (fd);
}

static void	free_parser(t_parser *parser)
{
	free(parser->no_path);
	free(parser->so_path);
	free(parser->we_path);
	free(parser->ea_path);
	free(parser->floor_color);
	free(parser->ceiling_color);
	close(parser->scene_file);
	free(parser->line);
	ft_free_2d_array((void **)parser->split);
	ft_free_2d_array((void **)parser->vis);
}

void	parser_fail(t_parser *parser, t_cub_errno err, char *context)
{
	ft_perror(err, context);
	free_game(parser->game);
	free_parser(parser);
	exit(err);
}

void	parse(t_game *game, int argc, char **argv)
{
	t_parser	parser;

	init_parser(&parser);
	parser.game = game;
	parser.scene_file = get_input(argc, argv);
	read_file(&parser);
	check_configs(&parser);
	// print_parser(&parser);
	check_map(&parser);
	transform_map(&parser);
	set_game(&parser);
	free_parser(&parser);
}
