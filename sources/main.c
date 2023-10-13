#include "../include/cub3D.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = init_settings();
	if (game == NULL)
		ft_perror(CUB_MEMFAIL, "Error\nMalloc failed\n");
	parse(game, argc, argv);
	// print_game(&game);
	// free_game(&game);
	return (EXIT_SUCCESS);
}
