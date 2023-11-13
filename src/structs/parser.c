#include "../../include/cub3D.h"

void	init_parser(t_parser *parser)
{
	t_textures	i;

	i = NORTH;
	while (i <= DOOR)
		parser->texture_paths[i++] = NULL;
	parser->floor_color = NULL;
	parser->ceiling_color = NULL;
	parser->scene_file = -1;
	parser->line = NULL;
	parser->split = NULL;
	parser->vis = NULL;
	parser->torch_sprite_sheet = NULL;
	parser->game = NULL;
}

void	free_parser(t_parser *parser)
{
	t_textures	i;

	i = NORTH;
	while (i <= DOOR)
		free(parser->texture_paths[i++]);
	free(parser->floor_color);
	free(parser->ceiling_color);
	close(parser->scene_file);
	free(parser->line);
	ft_free_2d_array((void **)parser->split);
	ft_free_2d_array((void **)parser->vis);
	delete_texture(parser->torch_sprite_sheet);
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
	printf("north: %s\n", parser->texture_paths[NORTH]);
	printf("east: %s\n", parser->texture_paths[EAST]);
	printf("south: %s\n", parser->texture_paths[SOUTH]);
	printf("west: %s\n", parser->texture_paths[WEST]);
	printf("floor: %s\n", parser->floor_color);
	printf("ceiling: %s\n", parser->ceiling_color);
	print_player(&parser->game->player);
	print_map(&parser->game->fix_map);
}
