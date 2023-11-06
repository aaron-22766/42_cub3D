#include "../../include/cub3D.h"

bool	is_empty_line(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
		if (!ft_strchr(WHITESPACE, line[i++]))
			return (false);
	return (true);
}

bool	is_valid_map_line(char *line)
{
	size_t	i;

	i = 0;
	while (line && line[i])
		if (!ft_strchr(MAP_CHARACTERS, line[i++]))
			return (false);
	return (!is_empty_line(line));
}

void	trim_newline(char *line)
{
	char	*nl;

	nl = ft_strrchr(line, '\n');
	if (nl && !nl[1])
		*nl = '\0';
}
