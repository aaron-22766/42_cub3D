#include "../include/cub3D.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		ft_perror(ERR_ARGS, "Invalid argument.\nUsage: ./cub3D [filename].cub");
	game.parser = parser(argc, argv);
	init_game(&game);
	return (0);
}
