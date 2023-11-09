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

typedef enum e_keys_down
{
	KEY_NONE = 0b0,
	KEY_W = 0b1,
	KEY_A = 0b10,
	KEY_S = 0b100,
	KEY_D = 0b1000,
	KEY_LEFT = 0b10000,
	KEY_RIGHT = 0b100000,
	KEY_PLAYER = 0b111111,
	KEY_ESCAPE = 0b1000000,
	KEY_LEFT_SHIFT = 0b10000000,
	KEY_F = 0b100000000
}	t_keys_down;

typedef enum e_textures
{
	NORTH,
	EAST,
	SOUTH,
	WEST,
	DOOR
}	t_textures;

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
uint32_t	get_pixel_txt(mlx_texture_t *txt, uint32_t x, uint32_t y);
uint32_t	get_pixel_img(mlx_image_t *img, uint32_t x, uint32_t y);
void		print_pixel_rgba(uint32_t pixel);
void		print_pixel_hex(uint32_t pixel);

/* color.c */
uint32_t	get_color(uint32_t r, uint32_t g, uint32_t b, uint32_t a);
uint8_t		red(uint32_t color);
uint8_t		green(uint32_t color);
uint8_t		blue(uint32_t color);
uint8_t		alpha(uint32_t color);

/* mlx_delete.c */
void		delete_texture(mlx_texture_t *texture);
void		delete_image(mlx_t *mlx, mlx_image_t *image);

#endif
