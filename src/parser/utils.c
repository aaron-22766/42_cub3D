#include "../../include/parser.h"

size_t	count_arr(char **arr)
{
	size_t	i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	free_arr(char **arr)
{
	size_t	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	print_parser(t_parser *parser)
{
	printf("\nPARSER\n");
	printf("file: %d\n", parser->scene_file);
	printf("line: %s\n", parser->line);
	printf("split: %p\n", parser->split);
	printf("element type: %d\n", parser->element_type);
	printf("north: %s\n", parser->no_path);
	printf("south: %s\n", parser->so_path);
	printf("west: %s\n", parser->we_path);
	printf("east: %s\n", parser->ea_path);
	printf("floor: %s\n", parser->floor_color);
	printf("ceiling: %s\n", parser->ceiling_color);
}
