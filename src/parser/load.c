#include "../../include/cub3D.h"

static bool	crop_texture(mlx_texture_t **texture)
{
	mlx_texture_t	*new;
	uint32_t		size;
	uint32_t		i;

	new = malloc(sizeof(mlx_texture_t));
	if (!new)
		return (false);
	size = fmin((*texture)->width, (*texture)->height);
	new->bytes_per_pixel = (*texture)->bytes_per_pixel;
	new->pixels = malloc(new->bytes_per_pixel * size * size);
	if (!new->pixels)
		return (free(new), false);
	i = 0;
	while (i < size)
	{
		ft_memcpy(&new->pixels[i * new->bytes_per_pixel * size],
			&(*texture)->pixels[i * new->bytes_per_pixel * (*texture)->width],
			new->bytes_per_pixel * size);
		i++;
	}
	mlx_delete_texture(*texture);
	new->width = size;
	new->height = size;
	*texture = new;
	return (true);
}

void	load_texture(t_parser *parser, mlx_texture_t **texture,
	char *path, bool square)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		parser_fail(parser, CUB_ERRNO, path);
	close(fd);
	*texture = mlx_load_png(path);
	if (!(*texture))
		parser_fail(parser, CUB_MLXFAIL, path);
	if (square && (*texture)->width != (*texture)->height)
		if (!crop_texture(texture))
			parser_fail(parser, CUB_MEMFAIL, "cropping texture");
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

void	load_color(t_parser *parser, uint32_t *color, char *rgb)
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
		parser_fail(parser, CUB_INVCOLOR, rgb);
	}
	red = ft_atoi(elements[0]);
	green = ft_atoi(elements[1]);
	blue = ft_atoi(elements[2]);
	ft_free_2d_array((void **)elements);
	if (red > 255 || green > 255 || blue > 255)
		parser_fail(parser, CUB_INVCOLOR, rgb);
	*color = get_color(red, green, blue, 255);
}
