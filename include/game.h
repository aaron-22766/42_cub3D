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
	double			time;
	uint8_t			fps;
	int32_t			mouse_x;
}	t_game;

/* ************************************************************************** */
/*                                 FUNCTIONS                                  */
/* ************************************************************************** */

/* setup.c */
void	setup_game(t_game *game);

/* hook.c */
void	hook(void *param);

/* action.c */
void	rotate_player(t_game *game, double dir);
void	do_player_action(t_game *game, t_keys_down keys);

#endif
