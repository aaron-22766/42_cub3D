
#include "../../include/cub3D.h"

/* ************************************************************************** */
/*           SPLIT THIS FUNCTION INTO 25 LINES ONLY AT THE VERY END           */
/* ************************************************************************** */

static void	print_error(t_cub_errno err, char *context)
{
	if (err == CUB_MEMFAIL)
		ft_eprintf("Memory allocation failed while %s", context);
	else if (err == CUB_INVARGS)
		ft_eprintf("Too %s arguments.\nUsage: ./cub3D [filename].cub", context);
	else if (err == CUB_INVFILEEXT)
		ft_eprintf("Invalid file extension. Expected: *.cub");
	else if (err == CUB_EMPTYFILE)
		ft_eprintf("Empty file");
	else if (err == CUB_INVLINE)
		ft_eprintf("Invalid line in scene file:\n%s", context);
	else if (err == CUB_DUPCONFIG)
		ft_eprintf("Duplicate configuration in scene file: %s", context);
	else if (err == CUB_MISSCONFIG)
		ft_eprintf("Missing configuration in scene file: %s", context);
	else if (err == CUB_INVTEXTEXT)
		ft_eprintf("Invalid texture file extension. Expected: *.png");
	else if (err == CUB_INVCOLOR)
		ft_eprintf("Invalid color: %s", context);
	else if (err == CUB_EMPTYLINE)
		ft_eprintf("Empty line in map");
	else if (err == CUB_NOMAP)
		ft_eprintf("No map found in scene file");
	else if (err == CUB_SMALLMAP)
		ft_eprintf("Map too small. Expected min. 3x3");
	else if (err == CUB_MISSPLAYER)
		ft_eprintf("Missing player starting position in map");
	else if (err == CUB_DUPPLAYER)
		ft_eprintf("Duplicate player starting positions in map");
	else if (err == CUB_INVWALLS)
		ft_eprintf("Map is not entirely surrounded by walls (%s)", context);
	ft_eprintf("\n");
}

t_cub_errno	ft_perror(t_cub_errno err, char *context)
{
	if (err == CUB_SUCCESS)
		return (err);
	ft_eprintf("Error\n");
	if (err == CUB_ERRNO)
		return (perror(context), errno);
	if (err == CUB_MLXFAIL)
		return (ft_eprintf("%s: %s\n", mlx_strerror(mlx_errno), context), \
				(t_cub_errno)mlx_errno);
	print_error(err, context);
	return (err);
}
