
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
# define ROTATE_SPEED M_PI / 180 * 15
# define TILE_SIZE 64
# define MOVE_SPEED 0.1
# define FOV M_PI / 3

# define TORCH_AMOUNT 4
# define TORCH_HEIGHT 350
# define TORCH_WIDTH 307
# define TORCH_X WINDOW_WIDTH / 5 * 3
# define TORCH_Y WINDOW_HEIGHT - TORCH_HEIGHT
# define TORCH_SPEED 0.1

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
	mlx_texture_t	*torch[TORCH_AMOUNT];
}	t_game;

/* ************************************************************************** */
/*                                 FUNCTIONS                                  */
/* ************************************************************************** */

/* hook.c */
void	hook(void* param);

/* motions.c */
void	move_player(t_game *game, t_player_action action);

/* rotations.c */
void	rotate_player(t_game *game, t_player_action action);

/* run.c */
void	run_game(t_game *game);

/* foreground.c */
void	draw_foreground(t_game *game);

/* utils.c	*/
void	print_rotated_map(t_map *map);

#endif
