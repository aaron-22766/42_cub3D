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

/* ************************************************************************** */
/*                                  TYPEDEFS                                  */
/* ************************************************************************** */

typedef struct s_game	t_game;

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

/* ************************************************************************** */
/*                                  STRUCTS                                   */
/* ************************************************************************** */

typedef struct s_map
{
	char	**map;
	size_t	height;
	size_t	max_width;
	size_t	*widths;
}	t_map;

typedef struct s_pos
{
	double	x;
	double	y;
	double	z;
}	t_pos;

typedef struct s_player
{
	double	orientation;
	t_pos	pos;
	double	fov;
}	t_player;

/* ************************************************************************** */
/*                                 FUNCTIONS                                  */
/* ************************************************************************** */

// error.c
t_cub_errno	ft_perror(t_cub_errno err, char *context);

// game.c
void		init_game(t_game *game);
void		free_game(t_game *game);
void		print_game(t_game *game);

// map.c
void		init_map(t_map *map);
void		free_map(t_map *map);
bool		calc_widths(t_map *map);
void		print_map(t_map *map);

// pixel.c
uint32_t	ft_pixel(uint32_t r, uint32_t g, uint32_t b, uint32_t a);
uint32_t	get_pixel_color(mlx_texture_t *txt, uint32_t x, uint32_t y);
void		print_pixel_rgba(uint32_t pixel);
void		print_pixel_hex(uint32_t pixel);

// player.c
void		init_player(t_player *player);
void		print_player(t_player *player);

// position.c
void		init_pos(t_pos *pos);
void		set_pos(t_pos *pos, double x, double y, double z);
void		print_pos(t_pos *pos);

#endif
