

#ifndef UTILS_H
# define UTILS_H

/* ************************************************************************** */
/*                                  INCLUDES                                  */
/* ************************************************************************** */

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <sys/errno.h>
// # include <sys/types.h>
// # include <sys/stat.h>
# include "../lib/libft/include/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
// # include "cub3D.h"
// # include "parser.h"

/* ************************************************************************** */
/*                                   ENUMS                                    */
/* ************************************************************************** */

/**
 * @brief Error codes.
 * 
 * @enum e_error_codes
 * ERR_ERRNO = Error specified in errno
 * ERR_MLX   = Error specified in mlx_errno
 * ERR_MEM	 = Memory allocation error
 * ERR_ARGS	 = Invalid arguments
 * ERR_EXT	 = Invalid file extension
 * 
 * TODO: Add more error codes as needed				@Aaron
 */
typedef enum e_cub_errno
{
	CUB_SUCCESS = 0,
	CUB_MLXFAIL = MLX_ERRMAX,
	CUB_ERRNO,
	CUB_MEMFAIL,
	CUB_INVARGS,
	CUB_INVEXT,
	CUB_INVLINE,
	CUB_DUPCONFIG
}	t_cub_errno;

/* ************************************************************************** */
/*                                  STRUCTS                                   */
/* ************************************************************************** */

/**
 * @brief Map structure
 * 
 */
typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
}	t_map;

typedef struct s_position
{
	double	x;
	double	y;
}	t_position;

/* ************************************************************************** */
/*                                 FUNCTIONS                                  */
/* ************************************************************************** */

t_cub_errno	ft_perror(t_cub_errno err, char *context);

#endif
