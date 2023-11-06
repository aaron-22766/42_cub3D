#ifndef UTILS_H
# define UTILS_H

/* ************************************************************************** */
/*                                  INCLUDES                                  */
/* ************************************************************************** */

# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <sys/errno.h>
# include "../lib/libft/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "structs.h"

/* ************************************************************************** */
/*                                  DEFINES                                   */
/* ************************************************************************** */

# define WINDOW_HEIGHT 720
# define WINDOW_WIDTH 1080

# define MOVE_SPEED 3.0
# define ROTATE_SPEED 1.25

# define TILE_SIZE 64

# define BLACK 0x000000FF
# define WHITE 0xFFFFFFFF

# define NORTH 0
# define EAST 1
# define SOUTH 2
# define WEST 3

/* ************************************************************************** */
/*                                   ENUMS                                    */
/* ************************************************************************** */

typedef enum e_cub_errno
{
	CUB_SUCCESS = 0,
	CUB_MLXFAIL = MLX_ERRMAX,
	CUB_ERRNO,
	CUB_MEMFAIL,
	CUB_INVARGS,
	CUB_INVFILEEXT,
	CUB_EMPTYFILE,
	CUB_INVLINE,
	CUB_DUPCONFIG,
	CUB_MISSCONFIG,
	CUB_INVTEXTEXT,
	CUB_INVCOLOR,
	CUB_EMPTYLINE,
	CUB_NOMAP,
	CUB_SMALLMAP,
	CUB_MISSPLAYER,
	CUB_DUPPLAYER,
	CUB_INVWALLS
}	t_cub_errno;

typedef enum e_player_action
{
	MOVE_FORWARD = MLX_KEY_W,
	MOVE_BACKWARD = MLX_KEY_S,
	MOVE_LEFT = MLX_KEY_A,
	MOVE_RIGHT = MLX_KEY_D,
	ROTATE_CCW = MLX_KEY_LEFT,
	ROTATE_CW = MLX_KEY_RIGHT
}	t_player_action;

/* ************************************************************************** */
/*                                  TYPEDEFS                                  */
/* ************************************************************************** */

typedef struct s_game	t_game;

/* ************************************************************************** */
/*                                 FUNCTIONS                                  */
/* ************************************************************************** */

/* error.c */
t_cub_errno	ft_perror(t_cub_errno err, char *context);

/* pixel.c */
uint32_t	get_color(uint32_t r, uint32_t g, uint32_t b, uint32_t a);
uint32_t	get_pixel_color(mlx_texture_t *txt, uint32_t x, uint32_t y);
void		print_pixel_rgba(uint32_t pixel);
void		print_pixel_hex(uint32_t pixel);

/* mlx_delete.c */
void		delete_texture(mlx_texture_t *texture);
void		delete_image(mlx_t *mlx, mlx_image_t *image);

#endif
