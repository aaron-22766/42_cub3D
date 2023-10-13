
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
/*                                   ENUMS                                    */
/* ************************************************************************** */

typedef enum e_element_type
{
	ELEMENT_INVALID,
	ELEMENT_NORTH,
	ELEMENT_SOUTH,
	ELEMENT_EAST,
	ELEMENT_WEST,
	ELEMENT_FLOOR,
	ELEMENT_CEILING
}	t_element_type;

/* ************************************************************************** */
/*                                  TYPEDEFS                                  */
/* ************************************************************************** */

typedef struct s_game		t_game;
typedef struct s_position	t_position;
typedef enum e_cub_errno	t_cub_errno;

/* ************************************************************************** */
/*                                  STRUCTS                                   */
/* ************************************************************************** */

typedef struct s_parser
{
	t_game			*game;
	int				scene_file;
	char			*line;
	char			**split;
	t_element_type	element_type;
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	char			*floor_color;
	char			*ceiling_color;
}	t_parser;

/* ************************************************************************** */
/*                                 FUNCTIONS                                  */
/* ************************************************************************** */

// parser.c
void	parse(t_game *game, int argc, char **argv);
void	parser_fail(t_parser *parser, t_cub_errno err, char *context);

// line.c
void	handle_line(t_parser *parser);

// set_game.c
void	set_game(t_parser *parser);

// utils.c
size_t	count_arr(char **arr);
void	free_arr(char **arr);
void	print_parser(t_parser *parser);

#endif
