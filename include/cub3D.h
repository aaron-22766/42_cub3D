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
# define ROTATE_SPEED (M_PI / 180 * 15)
# define TILE_SIZE 64
# define MOVE_SPEED 0.1
# define FOV (M_PI / 3)

# define TORCH_AMOUNT 4
# define TORCH_SPEED 0.125
# define TORCH_X (WINDOW_WIDTH / 7 * 5)

# define MINIMAP_OFFSET 10
# define MINIMAP_FRAME_WIDTH 3
# define MINIMAP_TILE_SIZE 21
# define MINIMAP_TILE_AMOUNT 11
# define MINIMAP_SIZE (MINIMAP_TILE_AMOUNT \
		* MINIMAP_TILE_SIZE + MINIMAP_FRAME_WIDTH * 2)
# define MINIMAP_WALL_COLOR 0x0000006F
# define MINIMAP_PATH_COLOR 0x6666666F
# define MINIMAP_RAY_COLOR 0xDDDDDDDF

# define BLACK 0x000000FF
# define WHITE 0xFFFFFFFF

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
	mlx_image_t		*foreground;
	t_map			fix_map;
	t_map			flex_map;
	t_player		player;
	mlx_texture_t	*no_texture;
	mlx_texture_t	*so_texture;
	mlx_texture_t	*we_texture;
	mlx_texture_t	*ea_texture;
	mlx_texture_t	*torch[TORCH_AMOUNT];
	uint32_t		floor_color;
	uint32_t		ceiling_color;
	uint32_t		minimap_color;
}	t_game;

/* ************************************************************************** */
/*                                 FUNCTIONS                                  */
/* ************************************************************************** */

/* init.c */
void	init_mlx(t_game *game);

/* hook.c */
void	hook(void *param);

/* motions.c */
void	move_player(t_game *game, t_player_action action);

/* rotations.c */
void	rotate_player(t_game *game, t_player_action action);

/* foreground.c */
void	generate_foreground(t_game *game);

/* minimap.c */
void	draw_minimap(t_game *game);

#endif
