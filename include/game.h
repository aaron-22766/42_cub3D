#ifndef GAME_H
# define GAME_H

/* ************************************************************************** */
/*                                  INCLUDES                                  */
/* ************************************************************************** */

# include "hud.h"
// # include "render.h"

/* ************************************************************************** */
/*                                  STRUCTS                                   */
/* ************************************************************************** */

typedef struct s_game
{
	mlx_t			*mlx;
	// t_render			render; // Also maybe more descriptive name e.g. world
	t_hud			hud;
	mlx_image_t		*image;//put inside of render struct
	t_map			fix_map;
	t_map			flex_map;
	t_player		player;
	mlx_texture_t	*no_texture;//*wall_textures[4] ??
	mlx_texture_t	*so_texture;
	mlx_texture_t	*we_texture;
	mlx_texture_t	*ea_texture;
	uint32_t		floor_color;//wall_textures & colors in separate  struct?
	uint32_t		ceiling_color;//name: scene
	bool			update;
}	t_game;

/* ************************************************************************** */
/*                                 FUNCTIONS                                  */
/* ************************************************************************** */

/* setup.c */
void	setup_game(t_game *game);

/* hook.c */
void	hook(void *param);

/* motions.c */
void	move_player(t_game *game, t_player_action action);

/* rotations.c */
void	rotate_player(t_game *game, t_player_action action);

#endif
