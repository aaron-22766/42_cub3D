#include "../../include/cub3D.h"

uint32_t	get_color(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint8_t	red(uint32_t color)
{
	return ((color >> 24) & 0xFF);
}

uint8_t	green(uint32_t color)
{
	return ((color >> 16) & 0xFF);
}

uint8_t	blue(uint32_t color)
{
	return ((color >> 8) & 0xFF);
}

uint8_t	alpha(uint32_t color)
{
	return (color & 0xFF);
}
