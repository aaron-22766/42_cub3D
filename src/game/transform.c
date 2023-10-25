
#include "../../include/cub3D.h"

static void	init_new_map(t_map *map)
{
	int		i;
	int		j;

	map->map = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->map)
		ft_perror(CUB_MEMFAIL, "Failed to allocate memory for map");
	i = 0;
	while (i < map->height)
	{
		map->map[i] = (char *)malloc(sizeof(char) * (map->max_width + 1));
		if (!map->map[i])
			ft_perror(CUB_MEMFAIL, "Failed to allocate memory for map");
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
	int		i;
	int		j;

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
			}
			j++;
		}
		i++;
	}
}

static void	print_new_map(t_map *map)
{
	size_t	i;

	printf("Map (height: %zu, max_width: %zu)\n", map->height, map->max_width);
	i = map->height;
	while (i > 0)
	{
		i--;
		printf("%*zu|%-*s|w%zu\n", (int)log10(map->height) + 1, i,
			(int)map->max_width, map->map[i], map->max_width);
	}
	printf("%*s_", (int)log10(map->height) + 1, "");
	i = 0;
	while (i < map->max_width)
	{
		printf("%c", (char) ('0' + i % 10));
		i++;
	}
	printf("_\n");
}

void	transform_map(t_game *game)
{
	t_map	new_map;

	init_map(&new_map);
	new_map.height = game->map.max_width;
	new_map.max_width = game->map.height;
	// game->player.pos.x = game->map.max_width - 1 - game->player.pos.x;
	// game->player.pos.y = game->map.height - 1 - game->player.pos.y;
	init_new_map(&new_map);
	rotate_map(&new_map, &game->map, &game->player);
	printf("\nMAP Before:\n");	// DEBUG
	print_map(&game->map);		// DEBUG
	printf("\nMAP After:\n");	// DEBUG
	print_new_map(&new_map);	// DEBUG
	print_player(&game->player);	// DEBUG
	free_map(&game->map);
	game->map = new_map;
}
