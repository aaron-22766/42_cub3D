#include "../../include/cub3D.h"

uint32_t	get_color(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t	get_pixel_txt(mlx_texture_t *txt, uint32_t x, uint32_t y)
{
	return (get_color(
			txt->pixels[(y * txt->width + x) * txt->bytes_per_pixel + 0],
			txt->pixels[(y * txt->width + x) * txt->bytes_per_pixel + 1],
			txt->pixels[(y * txt->width + x) * txt->bytes_per_pixel + 2],
			txt->pixels[(y * txt->width + x) * txt->bytes_per_pixel + 3]));
}

uint32_t	get_pixel_img(mlx_image_t *img, uint32_t x, uint32_t y)
{
	return (get_color(
			img->pixels[(y * img->width + x) * sizeof(int32_t) + 0],
			img->pixels[(y * img->width + x) * sizeof(int32_t) + 1],
			img->pixels[(y * img->width + x) * sizeof(int32_t) + 2],
			img->pixels[(y * img->width + x) * sizeof(int32_t) + 3]));
}

void	print_pixel_rgba(uint32_t pixel)
{
	printf("Pixel: %d, %d, %d, %d\n",
		(pixel >> 24 & 0xFF), (pixel >> 16 & 0xFF),
		(pixel >> 8 & 0xFF), (pixel & 0xFF));
}

void	print_pixel_hex(uint32_t pixel)
{
	printf("Pixel: %X\n", pixel);
}
