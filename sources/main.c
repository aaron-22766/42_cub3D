#include "../include/cub3D.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game.parser = parser(argc, argv);
	key_hook(&game);
	// if (argc == 2)
	// {
	// 	game = init_game(argv[1]);
	// 	if (game.error == 0)
	// 		game_loop(&game);
	// }
	// else
	// 	printf("Error\nWrong number of arguments\n");
	return (0);
}
