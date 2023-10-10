
#ifndef PARSER_H
# define PARSER_H

# include "cub3D.h"
typedef struct s_position	t_position;

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

/**
 * @brief Parser structure
 * 
 */

typedef struct s_parser
{
	t_map			*map;
	mlx_texture_t	wall_n_txt;
	mlx_texture_t	wall_s_txt;
	mlx_texture_t	wall_w_txt;
	mlx_texture_t	wall_e_txt;
	uint32_t		floor_color;
	uint32_t		ceiling_color;
	double			orientation;
	t_position		player;
}	t_parser;

t_parser	*parser(int argc, char **argv);

#endif
