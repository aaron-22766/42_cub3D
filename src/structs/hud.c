#include "../../include/hud.h"

void	init_hud(t_hud *hud)
{
	uint8_t		i;

	i = 0;
	while (i < TORCH_AMOUNT)
		hud->torch_textures[i++] = NULL;
	init_pos(&hud->torch_pos);
	hud->torch_time = 0;
	hud->torch_frame = 0;
	hud->torch_speed = 1.0 / TORCH_FPS;
	hud->image = NULL;
	hud->torch_pos.x = (WINDOW_WIDTH / 7) * 5;
	hud->minimap_center = MINIMAP_OFFSET + MINIMAP_RADIUS;
	hud->minimap_half_tile_size = MINIMAP_TILE_SIZE / 2.0;
	hud->minimap_radius_sqrd = MINIMAP_RADIUS * MINIMAP_RADIUS;
	hud->minimap_color = BLACK;
}

void	free_hud(mlx_t *mlx, t_hud *hud)
{
	uint8_t	i;

	i = 0;
	while (i < TORCH_AMOUNT)
		delete_texture(hud->torch_textures[i++]);
	delete_image(mlx, hud->image);
}

void	print_hud(t_hud *hud)
{
	printf("HUD:\ntorch: ");
	print_pos(&hud->torch_pos);
	printf("torch_time: %f\n", hud->torch_time);
	printf("torch_frame: %d\n", hud->torch_frame);
	printf("minimap_center: %u\n", hud->minimap_center);
	printf("minimap_half_tile_size: %f\n", hud->minimap_half_tile_size);
	printf("minimap_radius_sqrd: %u\n", hud->minimap_radius_sqrd);
	print_pixel_hex(hud->minimap_color);
}
