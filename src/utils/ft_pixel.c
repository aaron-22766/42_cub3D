#include "../../include/utils.h"

/* ************************************************************************** */
/*             NEEDED BY GAME? OTHERWISE ONLY PUT IN PARSER UTILS             */
/* ************************************************************************** */

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
