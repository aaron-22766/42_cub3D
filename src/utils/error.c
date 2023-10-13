#include "cub3D.h"

static void	print_error(t_cub_errno err, char *context)
{
	if (err == CUB_MEMFAIL)
		ft_eprintf("Memory allocation failed while %s", context);
	else if (err == CUB_INVARGS)
		ft_eprintf("Too %s arguments.\nUsage: ./cub3D [filename].cub", context);
	else if (err == CUB_INVEXT)
		ft_eprintf("Invalid file extension. Expected: *.cub");
	else if (err == CUB_INVLINE)
		ft_eprintf("Invalid line in scene file: %s", context);
	else if (err == CUB_DUPCONFIG)
		ft_eprintf("Duplicate elements in scene file: %s", context);
	ft_eprintf("\n");
}

t_cub_errno	ft_perror(t_cub_errno err, char *context)
{
	ft_eprintf("Error\n");
	if (err == CUB_ERRNO)
		return (perror(context), errno);
	if (err == CUB_MLXFAIL)
		return (ft_eprintf("%s\n", mlx_strerror(mlx_errno)), \
				(t_cub_errno)mlx_errno);
	print_error(err, context);
	return (err);
}
