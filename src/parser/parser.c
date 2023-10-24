#include "../../include/parser.h"

static void	check_args(int argc)
{
	if (argc < 2)
		exit(ft_perror(CUB_INVARGS, "few"));
	else if (argc > 2)
		exit(ft_perror(CUB_INVARGS, "many"));
}

static void	get_scene_file(t_parser *parser, char *path)
{
	if (!ft_strends(path, ".cub"))
		exit(ft_perror(CUB_INVFILEEXT, NULL));
	parser->scene_file = open(path, O_RDONLY);
	if (parser->scene_file == -1)
		exit(ft_perror(CUB_ERRNO, path));
}

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

void	exit_parser(t_parser *parser, t_cub_errno err, char *context)
{
	ft_perror(err, context);
	if (err != CUB_SUCCESS)
		free_game(parser->game);
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
	if (err != CUB_SUCCESS)
		exit(err);
}

void	parse(t_game *game, int argc, char **argv)
{
	t_parser	parser;

	check_args(argc);
	init_parser(&parser);
	parser.game = game;
	get_scene_file(&parser, argv[1]);
	read_file(&parser);
	check_configs(&parser);
	check_map(&parser);
	// print_parser(&parser);
	set_game(&parser);
	exit_parser(&parser, CUB_SUCCESS, NULL);
	// print_game(game);
}
