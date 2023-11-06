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
	mlx_image_t		*image;//put inside of render struct
	t_hud			hud;
	t_map			fix_map;
	t_map			flex_map;
	t_player		player;
	mlx_texture_t	*wall_textures[4];
	uint32_t		floor_color;
	uint32_t		ceiling_color;
	bool			update;
	double			time;
	uint8_t			fps;
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
