
#ifndef PARSER_H
# define PARSER_H

/* ************************************************************************** */
/*                                  INCLUDES                                  */
/* ************************************************************************** */

# include "utils.h"

/* ************************************************************************** */
/*                                  DEFINES                                   */
/* ************************************************************************** */

# define MAP_CHARACTERS " 01DNESW"
# define ALLIGN " "
# define PATH '0'
# define WALL '1'
# define DOOR 'D'
# define PLAYER_ORIENTATIONS "NESW"
# define WHITESPACE " \t\v\r\f\n"

/* ************************************************************************** */
/*                                  TYPEDEFS                                  */
/* ************************************************************************** */

typedef struct s_game	t_game;

/* ************************************************************************** */
/*                                  STRUCTS                                   */
/* ************************************************************************** */

typedef struct s_parser
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*floor_color;
	char	*ceiling_color;
	int		scene_file;
	char	*line;
	char	**split;
	char	**vis;
	t_game	*game;
}	t_parser;

/* ************************************************************************** */
/*                                 FUNCTIONS                                  */
/* ************************************************************************** */

// parser.c
void	parse(t_game *game, int argc, char **argv);
void	parser_fail(t_parser *parser, t_cub_errno err, char *context);

// read.c
void	read_file(t_parser *parser);

// configs.c
bool	configs(t_parser *parser);
void	check_configs(t_parser *parser);

// map.c
bool	map(t_parser *parser);

// check_map.c
void	check_map(t_parser *parser);

// check_walls.c
void	check_walls(t_parser *parser);

// transform.c
void	transform_map(t_parser *parser);

// set_game.c
void	set_game(t_parser *parser);

// load.c
void	load_texture(t_parser *parser, mlx_texture_t **texture,
	char *path, bool square);
void	load_color(t_parser *parser, uint32_t *color, char *rgb);

// utils.c
bool	is_empty_line(char *line);
bool	is_valid_map_line(char *line);
void	trim_newline(char *line);
void	print_parser(t_parser *parser);//DEBUG

#endif
