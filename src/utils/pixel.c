
#include "../../include/cub3D.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int32_t	get_pixel_color(mlx_texture_t *txt, int x, int y)
{
	int32_t	r;
	int32_t	g;
	int32_t	b;
	int32_t	a;

	r = txt->pixels[(y * txt->width + x) * txt->bytes_per_pixel + 0];
	g = txt->pixels[(y * txt->width + x) * txt->bytes_per_pixel + 1];
	b = txt->pixels[(y * txt->width + x) * txt->bytes_per_pixel + 2];
	a = txt->pixels[(y * txt->width + x) * txt->bytes_per_pixel + 3];
	return (ft_pixel(r, g, b, a));
}

void	print_pixel_rgba(int32_t pixel)
{
	int32_t	r;
	int32_t	g;
	int32_t	b;
	int32_t	a;

	r = pixel >> 24 & 0xFF;
	g = pixel >> 16 & 0xFF;
	b = pixel >> 8 & 0xFF;
	a = pixel & 0xFF;
	printf("Pixel: %d, %d, %d, %d\n", r, g, b, a);
}

void	print_pixel_hex(int32_t pixel)
{
	printf("Pixel: %X\n", pixel);
}
