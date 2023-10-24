
#include "../../include/cub3D.h"

uint32_t	ft_pixel(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t	get_pixel_color(mlx_texture_t *txt, uint32_t x, uint32_t y)
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
	uint32_t	a;

	if (x < 0 || x >= txt->width || y < 0 || y >= txt->height)
	{
		printf("x: %d, y: %d\n", x, y);
		// printf("Error: get_pixel_color: Out of bounds\n");
		// return (0);
	}
	// x = fmax(0, fmin(x, txt->width - 1));
	// y = fmax(0, fmin(y, txt->height - 1));
	r = txt->pixels[(y * txt->width + x) * txt->bytes_per_pixel + 0];
	g = txt->pixels[(y * txt->width + x) * txt->bytes_per_pixel + 1];
	b = txt->pixels[(y * txt->width + x) * txt->bytes_per_pixel + 2];
	a = txt->pixels[(y * txt->width + x) * txt->bytes_per_pixel + 3];
	return (ft_pixel(r, g, b, a));
}

void	print_pixel_rgba(uint32_t pixel)
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
	uint32_t	a;

	r = pixel >> 24 & 0xFF;
	g = pixel >> 16 & 0xFF;
	b = pixel >> 8 & 0xFF;
	a = pixel & 0xFF;
	printf("Pixel: %d, %d, %d, %d\n", r, g, b, a);
}

void	print_pixel_hex(uint32_t pixel)
{
	printf("Pixel: %X\n", pixel);
}
