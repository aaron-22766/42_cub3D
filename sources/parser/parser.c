#include "cub3D.h"

t_parser	*parser(int argc, char **argv)
{
	t_parser	*p;
	(void)argv;
	if (argc < 2)
	{
		ft_perror(ERR_MEM, "creating main struct");
	}
	p = (t_parser *)malloc(sizeof(t_parser));
	if (!p)
		ft_perror(ERR_MEM, "creating main struct");
	return (p);
}
