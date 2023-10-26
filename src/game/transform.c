
#include "../../include/cub3D.h"

static void	init_new_map(t_map *map)
{
	size_t	i;
	size_t	j;

	map->map = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->map)
		ft_perror(CUB_MEMFAIL, "transforming map");
	i = 0;
	while (i < map->height)
	{
		map->map[i] = (char *)malloc(sizeof(char) * (map->max_width + 1));
		if (!map->map[i])
			ft_perror(CUB_MEMFAIL, "transforming map");
		j = 0;
		while (j < map->max_width)
		{
			map->map[i][j] = ' ';
			j++;
		}
		map->map[i][j] = '\0';
		i++;
	}
	map->map[i] = NULL;
}

static void	rotate_map(t_map *new_map, t_map *map, t_player *player)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->widths[i])
		{
			new_map->map[map->max_width - 1 - j][i] = map->map[i][j];
			if (ft_strchr(PLAYER_ORIENTATIONS, map->map[i][j]))
			{
				player->pos.x = map->max_width - 1 - j;
				player->pos.y = i;
				new_map->map[map->max_width - 1 - j][i] = '0';
			}
			j++;
		}
		i++;
	}
}

void	transform_map(t_game *game)
{
	t_map	new_map;

	init_map(&new_map);
	new_map.height = game->map.max_width;
	new_map.max_width = game->map.height;
	init_new_map(&new_map);
	rotate_map(&new_map, &game->map, &game->player);
	// printf("\nMAP Before:\n");	// DEBUG
	// print_map(&game->map);		// DEBUG
	// printf("\nMAP After:\n");	// DEBUG
	// print_rotated_map(&new_map);	// DEBUG
	// print_player(&game->player);	// DEBUG
	free_map(&game->map);
	game->map = new_map;
}
