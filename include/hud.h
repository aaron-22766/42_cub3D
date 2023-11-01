#ifndef HUD_H
# define HUD_H

/* ************************************************************************** */
/*                                  INCLUDES                                  */
/* ************************************************************************** */

# include "utils.h"

/* ************************************************************************** */
/*                                  TYPEDEFS                                  */
/* ************************************************************************** */

typedef struct s_game	t_game;
typedef struct s_pos	t_pos;

/* ************************************************************************** */
/*                                  DEFINES                                   */
/* ************************************************************************** */

# define TORCH1 "./textures/torch/torch1.png"
# define TORCH2 "./textures/torch/torch2.png"
# define TORCH3 "./textures/torch/torch3.png"
# define TORCH4 "./textures/torch/torch4.png"

# define TORCH_AMOUNT 4
# define TORCH_SPEED 0.125

# define MINIMAP_OFFSET 10
# define MINIMAP_FRAME_WIDTH 3
# define MINIMAP_TILE_SIZE 21
# define MINIMAP_TILE_AMOUNT 11
# define MINIMAP_WALL_COLOR 0x0000006F
# define MINIMAP_PATH_COLOR 0x6666666F
# define MINIMAP_RAY_COLOR 0xDDDDDDDF

/* ************************************************************************** */
/*                                  STRUCTS                                   */
/* ************************************************************************** */

typedef struct	s_hud
{
	mlx_image_t		*image;
	mlx_texture_t	*torch_texture[TORCH_AMOUNT];
	t_pos			torch_pos;
	uint32_t		minimap_color;
	size_t			minimap_size;
	size_t			minimap_center;
}	t_hud;

/* ************************************************************************** */
/*                                 FUNCTIONS                                  */
/* ************************************************************************** */

/* hud.c */
void	generate_hud(t_game *game);

/* torch.c */
void	animate_torch(t_game *game);

/* minimap.c */
void	draw_minimap(t_game *game);

#endif
