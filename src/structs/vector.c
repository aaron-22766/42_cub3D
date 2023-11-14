#include "../../include/cub3D.h"

t_vector	init_vector(int64_t x, int64_t y, int64_t z)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

t_vector	zero_vector(void)
{
	return (init_vector(0, 0, 0));
}

t_vector	copy_vector(t_vector vector)
{
	t_vector	copy;

	copy.x = vector.x;
	copy.y = vector.y;
	copy.z = vector.z;
	return (copy);
}

t_vector	vector_sum(t_vector v1, t_vector v2)
{
	t_vector	sum;

	sum.x = v1.x + v2.x;
	sum.y = v1.y + v2.y;
	sum.z = v1.z + v2.z;
	return (sum);
}

void	print_vector(t_vector *vector, char *name, bool with_map_coords)
{
	if (name)
		printf("%s: ", name);
	else
		printf("(x, y, z) = ");
	printf(" (%lld, %lld, %lld)", vector->x, vector->y, vector->z);
	if (with_map_coords)
	{
		printf(" -> (%.2f, %.2f, %.2f)", (double)vector->x / TILE_SIZE,
			(double)vector->y / TILE_SIZE, (double)vector->z / TILE_SIZE);
	}
	printf("\n");
}
