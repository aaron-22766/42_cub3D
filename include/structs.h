#ifndef STRUCTS_H
# define STRUCTS_H

/* ************************************************************************** */
/*                                  TYPEDEFS                                  */
/* ************************************************************************** */

typedef struct s_parser		t_parser;
typedef struct s_game		t_game;
typedef struct s_hud		t_hud;
typedef enum e_cub_errno	t_cub_errno;

/* ************************************************************************** */
/*                                  STRUCTS                                   */
/* ************************************************************************** */

typedef struct s_pos
{
	double	x;
	double	y;
	double	z;
}	t_pos;

typedef struct s_vector
{
	int64_t	x;
	int64_t	y;
	int64_t	z;
}	t_vector;

typedef struct s_pixel
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	color;
}	t_pixel;

typedef struct s_map
{
	char	**map;
	size_t	height;
	size_t	max_width;
	size_t	*widths;
}	t_map;

typedef struct s_player
{
	double	orientation;
	t_pos	pos;
	double	fov;
}	t_player;

/* ************************************************************************** */
/*                                 FUNCTIONS                                  */
/* ************************************************************************** */

/* parser.c */
void		init_parser(t_parser *parser);
void		free_parser(t_parser *parser);
void		parser_fail(t_parser *parser, t_cub_errno err, char *context);
void		print_parser(t_parser *parser);

/* game.c */
void		init_game(t_game *game);
void		free_game(t_game *game);
void		game_fail(t_game *game, t_cub_errno err, char *context);
void		print_game(t_game *game);

/* hud.c */
void		init_hud(t_hud *hud);
void		free_hud(mlx_t *mlx, t_hud *hud);

/* map.c */
void		init_map(t_map *map);
void		free_map(t_map *map);
bool		calc_widths(t_map *map);
void		print_map(t_map *map);

/* player.c */
void		init_player(t_player *player);
void		print_player(t_player *player);

/* position.c */
void		init_pos(t_pos *pos);
void		set_pos(t_pos *pos, double x, double y, double z);
void		print_pos(t_pos *pos);

/* vector.c */
t_vector	init_vector(int64_t x, int64_t y, int64_t z);
t_vector	zero_vector(void);
t_vector	copy_vector(t_vector vector);
t_vector	vector_sum(t_vector v1, t_vector v2);
void		print_vector(t_vector *vector, char *name, bool with_map_coords);


#endif
