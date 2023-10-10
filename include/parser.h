
#ifndef PARSER_H
# define PARSER_H

# include "cub3d.h"

// # define MAP_CHARS "012NSEW"

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
}	t_map;

typedef struct s_parser
{
	t_map		*map;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	uint32_t	floor;
	uint32_t	ceiling;
}	t_parser;


#endif
