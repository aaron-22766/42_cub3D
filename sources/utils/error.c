#include "cub3D.h"

void	ft_perror(int err, char *context)
{
	ft_eprintf("Error\n");
	if (err == ERR_ARGS)
		perror(context);
	else if (err == ERR_MEM)
		ft_eprintf("memory allocation failed while %s", context);
	ft_eprintf("\n");
	exit(1);
}
