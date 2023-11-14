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

# define TORCH_PATH "./textures/torch.png"
# define TORCH_AMOUNT 6
# define TORCH_FPS 8

# define MINIMAP_OFFSET 10
# define MINIMAP_FRAME_WIDTH 3
# define MINIMAP_RADIUS 120
# define MINIMAP_MIN_TILE_SIZE 7
# define MINIMAP_MAX_TILE_SIZE 59
# define MINIMAP_DEFAULT_TILE_SIZE 21
# define MINIMAP_PLAYER_SIZE_DIVISOR 6.0
# define MINIMAP_MIN_PLAYER_SIZE 2

# define MINIMAP_PATH_COLOR 0x666666AF
# define MINIMAP_WALL_COLOR 0x000000AF
# define MINIMAP_DOOR_CLOSED_COLOR 0x222222AF
# define MINIMAP_DOOR_OPEN_COLOR 0x444444AF
# define MINIMAP_FOV_COLOR 0x606060AF
# define MINIMAP_RAY_COLOR 0x505050AF

/* ************************************************************************** */
/*                                  STRUCTS                                   */
/* ************************************************************************** */

typedef struct s_hud
{
	mlx_image_t		*image;
	mlx_texture_t	*torch_textures[TORCH_AMOUNT];
	t_pos			torch_pos;
	double			torch_time;
	uint8_t			torch_frame;
	double			torch_speed;
	uint32_t		minimap_color;
	uint32_t		minimap_center;
	uint32_t		minimap_tile_size;
	double			minimap_half_tile_size;
	uint32_t		minimap_radius_sqrd;
	double			minimap_player_radius;
}	t_hud;

/* ************************************************************************** */
/*                                 FUNCTIONS                                  */
/* ************************************************************************** */

/* setup.c */
void		set_hud(t_parser *parser);
void		setup_hud(t_game *game);

/* torch.c */
void		animate_torch(t_game *game, bool force);

/* minimap.c */
void		draw_minimap(t_game *game);

/* fov.c */
void		draw_fov(t_game *game);

/* map.c */
void		draw_doors(t_game *game);
void		draw_walls(t_game *game);

/* tile.c */
void		draw_tile(t_game *game, uint32_t x, uint32_t y, uint32_t color);

/* utils.c */
void		draw_circle(t_hud *hud, double radius, uint32_t color);
uint32_t	rotate(t_game *game, double a, double b, uint8_t scale);
uint32_t	sqrd_distance(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2);
void		put_pixel(t_hud *hud, uint32_t x, uint32_t y, uint32_t color);

#endif
