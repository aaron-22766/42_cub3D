#include "../../include/parser.h"

static void	load_texture(t_parser *parser, mlx_texture_t **texture, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_parser(parser, CUB_ERRNO, path);
	close(fd);
	*texture = mlx_load_png(path);
	if (!(*texture))
		exit_parser(parser, CUB_MLXFAIL, path);
}

static bool	is_valid_rgb(char *rgb)
{
	size_t	i;
	size_t	comma;

	comma = 0;
	i = 0;
	while (rgb[i])
	{
		if (!ft_isdigit(rgb[i]) && rgb[i] != ',')
			return (false);
		if (rgb[i] == ',')
			comma++;
		i++;
	}
	return (i < 12 && comma == 2);
}

static void	load_color(t_parser *parser, uint32_t *color, char *rgb)
{
	char	**elements;
	int		red;
	int		green;
	int		blue;

	elements = ft_split(rgb, ',');
	if (!is_valid_rgb(rgb) || ft_count_2d_array((void **)elements) != 3
		|| ft_strlen(elements[0]) > 3 || ft_strlen(elements[1]) > 3
		|| ft_strlen(elements[2]) > 3)
	{
		ft_free_2d_array((void **)elements);
		exit_parser(parser, CUB_INVCOLOR, rgb);
	}
	red = ft_atoi(elements[0]);
	green = ft_atoi(elements[1]);
	blue = ft_atoi(elements[2]);
	ft_free_2d_array((void **)elements);
	if (red > 255 || green > 255 || blue > 255)
		exit_parser(parser, CUB_INVCOLOR, rgb);
	*color = ft_pixel(red, green, blue, 255);
}

static size_t	remove_excess_allign(t_map *map)
{
	size_t	min;
	size_t	max;
	size_t	i;
	size_t	temp;

	min = -1;
	max = 0;
	i = 0;
	while (i < map->height)
	{
		temp = ft_strspn(map->map[i], ALLIGN);
		if (temp < min)
			min = temp;
		temp = ft_strrspn(map->map[i], ALLIGN);
		if (temp > max)
			max = temp;
		map->map[i++][temp + 1] = '\0';
	}
	i = 0;
	while (i < map->height)
	{
		ft_memmove(map->map[i], &map->map[i][min], max - min + 2);
		i++;
	}
	return (min);
}

void	set_game(t_parser *parser)
{
	load_texture(parser, &parser->game->no_texture, parser->no_path);
	load_texture(parser, &parser->game->ea_texture, parser->ea_path);
	load_texture(parser, &parser->game->so_texture, parser->so_path);
	load_texture(parser, &parser->game->we_texture, parser->we_path);
	load_color(parser, &parser->game->floor_color, parser->floor_color);
	load_color(parser, &parser->game->ceiling_color, parser->ceiling_color);
	parser->game->player.pos.y -= remove_excess_allign(&parser->game->map);
	calc_widths(&parser->game->map);
}
