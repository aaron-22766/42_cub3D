/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 00:38:22 by lfiorini          #+#    #+#             */
/*   Updated: 2023/09/21 00:42:22 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		game = init_game(argv[1]);
		if (game.error == 0)
			game_loop(&game);
	}
	else
		printf("Error\nWrong number of arguments\n");
	return (SUCCESS);
}
