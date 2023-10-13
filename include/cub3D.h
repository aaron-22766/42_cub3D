
#ifndef CUB3D_H
# define CUB3D_H

/* ************************************************************************** */
/*                                  INCLUDES                                  */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/errno.h>
# include <math.h>
# include "../libraries/libft/include/libft.h"
# include "../libraries/MLX42/include/MLX42/MLX42.h"
# include "utils.h"
# include "parser.h"

/* ************************************************************************** */
/*                                  DEFINES                                   */
/* ************************************************************************** */

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

# ifndef SPEED
#  define SPEED 0.1
# endif

/* ************************************************************************** */
/*                                  TYPEDEFS                                  */
/* ************************************************************************** */

typedef struct s_map		t_map;
typedef struct s_position	t_position;

/* ************************************************************************** */
/*                                  STRUCTS                                   */
/* ************************************************************************** */

/**
 * @brief Game structure
 * 
 */

typedef struct s_game
{
	mlx_t			*mlx;
	t_map			*map;
	mlx_texture_t	*no_texture;
	mlx_texture_t	*so_texture;
	mlx_texture_t	*we_texture;
	mlx_texture_t	*ea_texture;
	uint32_t		floor_color;
	uint32_t		ceiling_color;
	double			orientation;
	t_position		player_pos;
}	t_game;

/* ************************************************************************** */
/*                                 FUNCTIONS                                  */
/* ************************************************************************** */


/* debug.c */
void		print_game(t_game *game);

/* free_game.c */
void		free_game(t_game *game);

/* hook.c */
void		key_hook(t_game *game);

/* init_game.c */
// void		key_hook(t_game *game);
void		init_settings(t_game *game);
// int		init_game(t_game *game);

#endif
