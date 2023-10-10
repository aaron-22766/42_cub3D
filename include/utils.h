
/**
 * @brief Here are all the includes and defines that are used in the project.
 * 
 * 
 */

#ifndef UTILS_H
# define UTILS_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <sys/errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "cub3D.h"

typedef struct s_game		t_game;
typedef struct s_map		t_map;
typedef struct s_parser		t_parser;
typedef struct s_position	t_position;

/**
 * @brief Error codes.
 * 
 * @enum e_error_codes
 * ERR_ARGS	= Invalid arguments
 * ERR_EXT	= Invalid file extension
 * ERR_MAP	= Invalid map
 * ERR_RGB	= Invalid RGB color
 * ERR_MEM	= Memory allocation error
 * 
 * TODO: Add more error codes as needed				@Aaron
 */

typedef struct s_position
{
	double	x;
	double	y;
}	t_position;

typedef enum e_error_codes
{
	ERR_ARGS,
	ERR_EXT,
	ERR_MAP,
	ERR_RGB,
	ERR_MEM
}	t_error_codes;


void	ft_perror(int err, char *context);

#endif
