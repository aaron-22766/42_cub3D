
#include "../../include/cub3D.h"

/**
 * @brief Initialize a t_vector struct with the given values
 * 
 * @param x 
 * @param y 
 * @param z 
 * @return t_vector 
 */

t_vector	init_vector(int64_t x, int64_t y, int64_t z)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

/**
 * @brief Initialize a t_vector struct with zeros
 * 
 * @param x 
 * @param y 
 * @param z 
 * @return t_vector 
 */

t_vector	zero_vector(void)
{
	t_vector	vector;

	vector.x = 0;
	vector.y = 0;
	vector.z = 0;
	return (vector);
}

/**
 * @brief Copy the given vector
 * 
 * @param vector
 * @return t_vector 
 */

t_vector	copy_vector(t_vector vector)
{
	t_vector	copy;

	copy.x = vector.x;
	copy.y = vector.y;
	copy.z = vector.z;
	return (copy);
}

/**
 * @brief Print the given vector
 * 
 * @param vector 
 * @param name 
 * @param with_map_coords 
 */

void	print_vector(t_vector *vector, char *name, bool with_map_coords)
{
	if (name)
		printf("\n%s:\t", name);
	printf("\n(x, y, z) =\t");
	printf(" (%lld, %lld, %lld)", vector->x, vector->y, vector->z);
	if (with_map_coords)
		printf(" -> (%lld, %lld, %lld)",
			vector->x / TILE_SIZE, vector->y / TILE_SIZE, vector->z / TILE_SIZE);
	printf("\n");
}
