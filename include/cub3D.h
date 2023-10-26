
#ifndef CUB3D_H
# define CUB3D_H

/* ************************************************************************** */
/*                                  INCLUDES                                  */
/* ************************************************************************** */

# include "utils.h"
# include "parser.h"
# include "render.h"

/* ************************************************************************** */
/*                                  DEFINES                                   */
/* ************************************************************************** */

# define WINDOW_HEIGHT 720
# define WINDOW_WIDTH 1080
# define MOVE_SPEED 0.1
# define ROTATE_SPEED M_PI / 180 * 15
# define TILE_SIZE 64
# define FOV M_PI / 3

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

/* hook.c */
void	hook(void* param);
// void	exit_hook(void *param);

/* motions.c */
// void	move_forward(t_game *game);
// void	move_backward(t_game *game);
// void	move_left(t_game *game);
// void	move_right(t_game *game);
void	move_player(t_game *game, t_player_action action);

/* rotations.c */
void	rotate_clockwise(t_game *game);
void	rotate_counterclockwise(t_game *game);
void	rotate_player(t_game *game, t_player_action action);

/* run.c */
void	run_game(t_game *game);

#endif
