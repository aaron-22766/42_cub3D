
#ifndef PARSER_H
# define PARSER_H

/* ************************************************************************** */
/*                                  INCLUDES                                  */
/* ************************************************************************** */

# include "cub3D.h"
# include "utils.h"

/* ************************************************************************** */
/*                                  DEFINES                                   */
/* ************************************************************************** */

# define MAP_CHARACTERS " 01NESW"

/* ************************************************************************** */
/*                                  TYPEDEFS                                  */
/* ************************************************************************** */

typedef struct s_game		t_game;
typedef struct s_position	t_position;
typedef struct s_map		t_map;
typedef enum e_cub_errno	t_cub_errno;

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
	t_map	map;
	int		scene_file;
	char	*line;
	char	**split;
	bool	read;
	t_game	*game;
}	t_parser;

/* ************************************************************************** */
/*                                 FUNCTIONS                                  */
/* ************************************************************************** */

// parser.c
void	parse(t_game *game, int argc, char **argv);
void	parser_fail(t_parser *parser, t_cub_errno err, char *context);
void	print_parser(t_parser *parser);

// read.c
int		get_scene_file(char *path);
void	read_file(t_parser *parser, void (*f)(t_parser *));

// configs.c
void	configs(t_parser *parser);
void	check_configs(t_parser *parser);

// map.c
void	map(t_parser *parser);

// set_game.c
void	set_game(t_parser *parser);

// utils.c
size_t	count_arr(char **arr);
void	free_arr(char **arr);

#endif
