#include "../../include/cub3D.h"

static void	draw_frame(t_hud *hud)
{
	uint8_t	offset;
	size_t	i;

	offset = 0;
	while (offset < MINIMAP_FRAME_WIDTH)
	{
		i = 0;
		while (i < (size_t)(hud->minimap_size - offset))
		{
			mlx_put_pixel(hud->image, MINIMAP_OFFSET + offset + i,
				MINIMAP_OFFSET + offset, hud->minimap_color);
			mlx_put_pixel(hud->image, MINIMAP_OFFSET + offset,
				MINIMAP_OFFSET + offset + i, hud->minimap_color);
			mlx_put_pixel(hud->image, MINIMAP_OFFSET + offset + i,
				MINIMAP_OFFSET + hud->minimap_size - offset - 1,
				hud->minimap_color);
			mlx_put_pixel(hud->image, MINIMAP_OFFSET + hud->minimap_size
				- offset - 1, MINIMAP_OFFSET + offset + i, hud->minimap_color);
			i++;
		}
		offset++;
	}
}

void	setup_hud(t_game *game)
{
	game->hud.image = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->hud.image)
		game_fail(game, CUB_MLXFAIL, "Failed to create image");
	draw_minimap(game);
	draw_frame(&game->hud);
	animate_torch(game);
	if (mlx_image_to_window(game->mlx, game->hud.image, 0, 0) == -1)
		game_fail(game, CUB_MLXFAIL, "Failed to render hud");
	mlx_set_instance_depth(game->hud.image->instances, 2);
}
