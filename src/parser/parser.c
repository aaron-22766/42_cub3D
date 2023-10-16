#include "cub3D.h"

static void	init_parser(t_parser *parser, t_game *game)
{
	parser->no_path = NULL;
	parser->so_path = NULL;
	parser->we_path = NULL;
	parser->ea_path = NULL;
	parser->floor_color = NULL;
	parser->ceiling_color = NULL;
	parser->map.height = 0;
	parser->map.width = 0;
	parser->map.map = NULL;
	parser->scene_file = -1;
	parser->line = NULL;
	parser->split = NULL;
	parser->read = true;
	parser->game = game;
}

static void	free_parser(t_parser *parser)
{
	free(parser->no_path);
	free(parser->so_path);
	free(parser->we_path);
	free(parser->ea_path);
	free(parser->floor_color);
	free(parser->ceiling_color);
	free_arr(parser->map.map);
	close(parser->scene_file);
	free(parser->line);
	free_arr(parser->split);
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

	if (argc < 2)
		exit(ft_perror(CUB_INVARGS, "few"));
	else if (argc > 2)
		exit(ft_perror(CUB_INVARGS, "many"));
	init_parser(&parser, game);
	parser.scene_file = get_scene_file(argv[1]);
	read_file(&parser, configs);
	check_configs(&parser);
	read_file(&parser, map);
	// check_map(&parser);
	print_parser(&parser);
	set_game(&parser);
	free_parser(&parser);
	print_game(game);
}

void	print_parser(t_parser *parser)
{
	printf("\nPARSER\n");
	printf("file: %d\n", parser->scene_file);
	printf("line: %s\n", parser->line);
	printf("split: %p\n", parser->split);
	printf("north: %s\n", parser->no_path);
	printf("south: %s\n", parser->so_path);
	printf("west: %s\n", parser->we_path);
	printf("east: %s\n", parser->ea_path);
	printf("floor: %s\n", parser->floor_color);
	printf("ceiling: %s\n", parser->ceiling_color);
}
