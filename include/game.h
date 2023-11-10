#ifndef GAME_H
# define GAME_H

/* ************************************************************************** */
/*                                  INCLUDES                                  */
/* ************************************************************************** */

# include "hud.h"
// # include "render.h"

/* ************************************************************************** */
/*                                  DEFINES                                   */
/* ************************************************************************** */

# define WINDOW_WIDTH 1080
# define WINDOW_HEIGHT 720

# define PLAYER_NORMAL_SPEED 3
# define PLAYER_SNEAK_SPEED 1
# define PLAYER_SPRINT_SPEED 5
# define PLAYER_DEFAULT_FOV 60
# define PLAYER_MIN_FOV 30
# define PLAYER_MAX_FOV 90
# define ROTATE_SPEED 1.25
# define MOUSE_DIVISOR 21
# define COLLISION 0.15

# define TILE_SIZE 64

# define BLUR_RADIUS 20
# define PAUSE_NO_BLUR 0x030303D0

# define BLACK 0x000000FF
# define WHITE 0xFFFFFFFF

/* ************************************************************************** */
/*                                  STRUCTS                                   */
/* ************************************************************************** */

typedef struct s_game
{
	mlx_t			*mlx;
	// t_render			render; // Also maybe more descriptive name e.g. world
	mlx_image_t		*image;//put inside of render struct
	mlx_image_t		*pause_screen;
	mlx_image_t		*pause_text;
	t_hud			hud;
	t_map			fix_map;
	t_map			flex_map;
	t_player		player;
	mlx_texture_t	*wall_textures[5];
	uint32_t		floor_color;
	uint32_t		ceiling_color;
	double			time;
	uint8_t			fps;
	int32_t			mouse_x;
	uint32_t		nb_tiles;
	t_rgb			**blur_table;
	uint32_t		blur_area;
	bool			paused;
	bool			too_small;
	bool			resized;
}	t_game;

/* ************************************************************************** */
/*                                 FUNCTIONS                                  */
/* ************************************************************************** */

/* setup.c */
void	setup_world(t_game *game); // move to render/world folder
void	setup_pause_screen(t_game *game);
void	setup_game(t_game *game);

/* hook.c */
void	hook(void *param);

/* action.c */
void	do_player_action(t_game *game, t_keys_down *keys);

/* player.c */
void	rotate_player(t_game *game, double dir);
void	move_player(t_game *game, double x, double y);

/* mouse.c */
void	zoom_minimap(double xdelta, double ydelta, void *param);
void	reset_minimap(mouse_key_t button, action_t action, \
			modifier_key_t mods, void *param);

/* pause.c */
void	render_pause_screen(t_game *game);
void	pause_key(mlx_key_data_t keydata, void *param);

/* blur.c */
bool	render_blur(t_game *game);

/* blur_table.c */
void	make_table(t_game *game);

/* resize.c */
void	resize_game(t_game *game);
void	resize_window(int32_t width, int32_t height, void *param);

/* utils.c */
int8_t	sign(double x);

#endif
