
#include "../../include/cub3D.h"

static void	init_map_transform(t_map *map)
{
	int		i;
	int		j;

	map->map = (char **)malloc(sizeof(char *) * (map->height + 1));
	map->widths = (size_t *)malloc(sizeof(size_t) * map->height);
	if (!map->map || !map->widths)
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
				// player->orientation = get_radian(map->map[i][j]);
			}
			j++;
		}
		new_map->widths[i] = map->max_width;
		i++;
	}
}

void	transform_map(t_game *game)
{
	t_map	new_map;

	init_map(&new_map);
	new_map.height = game->map.max_width;
	new_map.max_width = game->map.height;
	// game->player.pos.x = game->map.max_width - 1 - game->player.pos.x;
	// game->player.pos.y = game->map.height - 1 - game->player.pos.y;
	init_map_transform(&new_map);
	rotate_map(&new_map, &game->map, &game->player);
	free_map(&game->map);
	game->map = new_map;
}
