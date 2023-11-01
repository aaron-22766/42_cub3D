#include "../../include/cub3D.h"

void	init_parser(t_parser *parser)
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

void	free_parser(t_parser *parser)
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

void	print_parser(t_parser *parser)
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
	print_player(&parser->game->player);
	print_map(&parser->game->fix_map);
}
