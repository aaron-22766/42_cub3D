#ifndef CUB3D_H
# define CUB3D_H

/* ************************************************************************** */
/*                                  INCLUDES                                  */
/* ************************************************************************** */

# include "utils.h"
# include "parser.h"

/* ************************************************************************** */
/*                                  DEFINES                                   */
/* ************************************************************************** */

# define HEIGHT 720
# define WIDTH 1080
# define SPEED 0.1

/* ************************************************************************** */
/*                                  TYPEDEFS                                  */
/* ************************************************************************** */

typedef struct s_map	t_map;
typedef struct s_pos	t_pos;
typedef struct s_player	t_player;

/* ************************************************************************** */
/*                                  STRUCTS                                   */
/* ************************************************************************** */

typedef struct s_game
{
	mlx_t			*mlx;
	t_map			map;
	mlx_texture_t	*no_texture;
	mlx_texture_t	*so_texture;
	mlx_texture_t	*we_texture;
	mlx_texture_t	*ea_texture;
	uint32_t		floor_color;
	uint32_t		ceiling_color;
	t_player		player;
}	t_game;

/* ************************************************************************** */
/*                                 FUNCTIONS                                  */
/* ************************************************************************** */

// init_game.c
void	init_settings(t_game *game);
void	init_game(t_game *game);

// free_game.c
void	free_game(t_game *game);

// debug.c
void	print_game(t_game *game);//DEBUG

#endif
