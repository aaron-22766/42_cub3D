#include "../../include/cub3D.h"

void	init_pos(t_pos *pos)
{
	pos->x = 0;
	pos->y = 0;
	pos->z = 0;
}

void	set_pos(t_pos *pos, double x, double y, double z)
{
	pos->x = x;
	pos->y = y;
	pos->z = z;
}

void	print_pos(t_pos *pos)
{
	printf("(x, y, z) = (%f, %f, %f)\n", pos->x, pos->y, pos->z);
}
