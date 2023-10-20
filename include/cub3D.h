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
# define MOVE_SPEED 0.1
# define ROTATE_SPEED M_PI / 180 * 5

/* ************************************************************************** */
/*                                  TYPEDEFS                                  */
/* ************************************************************************** */

typedef struct s_map	t_map;
typedef struct s_pos	t_pos;
/* ************************************************************************** */
/*                                  STRUCTS                                   */
/* ************************************************************************** */

typedef struct s_player
{
	double	orientation;
	t_pos	pos;
}	t_player;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*image;
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

// init.c
void	init_settings(t_game *game);
void	init_game(t_game *game);

// free.c
void	free_game(t_game *game);

// run.c
void	run_game(t_game *game);

// debug.c
void	print_game(t_game *game);//DEBUG

// render_background.c
void	render_background(t_game *game);

// hook.c
int		key_hook(int keycode, t_game *game);

#endif
