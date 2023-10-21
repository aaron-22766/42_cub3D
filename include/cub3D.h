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

# define WINDOW_HEIGHT 720
# define WINDOW_WIDTH 1080
# define MOVE_SPEED 0.1
# define ROTATE_SPEED M_PI / 180 * 5

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
void	print_game(t_game *game);			//DEBUG
void	print_player(t_player *player);		//DEBUG

// render_background.c
void	render_background(t_game *game);

// hook.c
void	key_hook(mlx_key_data_t keydata, void* param);
// void	key_hook(void* param);

// move
void	move_player_forward(t_game *game);
void	move_player_backward(t_game *game);
void	move_player_left(t_game *game);
void	move_player_right(t_game *game);
void	rotate_player_left(t_game *game);
void	rotate_player_right(t_game *game);


#endif
