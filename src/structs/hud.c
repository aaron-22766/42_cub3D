#include "../../include/hud.h"

void	init_hud(t_hud *hud)
{
	uint8_t	i;

	i = 0;
	while (i < TORCH_AMOUNT)
		hud->torch_texture[i++] = NULL;
	init_pos(&hud->torch_pos);
	hud->image = NULL;
	hud->minimap_color = BLACK;
	hud->minimap_size = MINIMAP_TILE_AMOUNT * MINIMAP_TILE_SIZE
		+ MINIMAP_FRAME_WIDTH * 2;
	hud->minimap_center = MINIMAP_OFFSET + MINIMAP_FRAME_WIDTH
		+ (MINIMAP_TILE_SIZE * MINIMAP_TILE_AMOUNT) / 2;
	hud->torch_pos.x = (WINDOW_WIDTH / 7) * 5;
}

void	free_hud(mlx_t *mlx, t_hud *hud)
{
	uint8_t	i;

	i = 0;
	while (i < TORCH_AMOUNT)
		delete_texture(hud->torch_texture[i++]);
	delete_image(mlx, hud->image);
}
