#include "../include/cub3D.h"

int	main(int argc, char **argv)
{
	t_game	game;

	init_settings(&game);
	parse(&game, argc, argv);
	// init_mlx(&game);
	// run_game(&game);
	// free_game(&game);
	return (EXIT_SUCCESS);
}
