#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/errno.h>
# include "../libraries/libft/include/libft.h"
# include "../libraries/MLX42/include/MLX42/MLX42.h"
# include "utils.h"
# include "parser.h"


/**
 * @brief Window height & width in pixels
 * 
 * @note Default values are 720p (1280x720)
 * 
 * 
 */

# ifndef HEIGHT
#  define HEIGHT 720
# endif

# ifndef WIDTH
#  define WIDTH 1280
# endif


typedef struct s_map	t_map;
typedef struct s_parser	t_parser;
typedef struct s_position	t_position;


/**
 * @brief Game structure
 * 
 */

typedef struct s_game
{
	mlx_t		*mlx;
	t_parser	*parser;
	void		*win;
}	t_game;

void	key_hook(t_game *game);

#endif
