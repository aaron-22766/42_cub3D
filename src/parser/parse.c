#include "../../include/cub3D.h"

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
