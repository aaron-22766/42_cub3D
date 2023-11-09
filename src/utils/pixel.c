#include "../../include/cub3D.h"

uint32_t	get_pixel_txt(mlx_texture_t *txt, uint32_t x, uint32_t y)
{
	uint32_t	pixel;

	pixel = (y * txt->width + x) * txt->bytes_per_pixel;
	return (get_color(txt->pixels[pixel + 0], txt->pixels[pixel + 1],
			txt->pixels[pixel + 2], txt->pixels[pixel + 3]));
}

uint32_t	get_pixel_img(mlx_image_t *img, uint32_t x, uint32_t y)
{
	uint32_t	pixel;

	pixel = (y * img->width + x) * sizeof(int32_t);
	if (pixel >= img->width * img->height * sizeof(int32_t))
		return (0x0);
	return (get_color(img->pixels[pixel + 0], img->pixels[pixel + 1],
			img->pixels[pixel + 2], img->pixels[pixel + 3]));
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
