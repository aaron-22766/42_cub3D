#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/errno.h>
# include "../libraries/libft/include/libft.h"


# ifndef HEIGHT
#  define HEIGHT 720
# endif

# ifndef WIDTH
#  define WIDTH 1280
# endif

enum e_errors
{
	ERR_ERRNO,
	ERR_MEM
};

void	parser(int argc, char **argv);

void	ft_perror(int err, char *context);

#endif
