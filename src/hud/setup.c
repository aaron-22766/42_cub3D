#include "../../include/cub3D.h"

static mlx_texture_t	*new_torch_texture(mlx_texture_t *sprite_sheet)
{
	mlx_texture_t	*new;

	new = malloc(sizeof(mlx_texture_t));
	if (!new)
		return (NULL);
	new->bytes_per_pixel = sprite_sheet->bytes_per_pixel;
	new->height = sprite_sheet->height;
	new->width = sprite_sheet->width / TORCH_AMOUNT;
	new->pixels = ft_calloc(new->height * new->width * new->bytes_per_pixel,
			sizeof(uint8_t));
	if (!new->pixels)
		return (free(new), NULL);
	return (new);
}

static void	copy_texture_portion(mlx_texture_t *dst,
	mlx_texture_t *src, uint32_t start_x)
{
	uint32_t	y;

	y = 0;
	while (y < dst->height)
	{
		ft_memcpy(&dst->pixels[y * dst->width * dst->bytes_per_pixel],
			&src->pixels[(y * src->width + start_x) * dst->bytes_per_pixel],
			dst->width * dst->bytes_per_pixel);
		y++;
	}
}

static void	load_torch_textures(t_parser *parser)
{
	t_hud	*hud;
	uint8_t	i;

	hud = &parser->game->hud;
	i = 0;
	while (i < TORCH_AMOUNT)
	{
		hud->torch_textures[i] = new_torch_texture(parser->torch_sprite_sheet);
		if (!hud->torch_textures[i])
			parser_fail(parser, CUB_MEMFAIL, "creating torch textures");
		copy_texture_portion(hud->torch_textures[i], parser->torch_sprite_sheet,
			i * hud->torch_textures[0]->width);
		i++;
	}
}

void	set_hud(t_parser *parser)
{
	load_texture(parser, &parser->torch_sprite_sheet, TORCH_PATH, false);
	load_torch_textures(parser);
	if ((((parser->game->ceiling_color >> 24) & 0xFF)
			+ ((parser->game->ceiling_color >> 16) & 0xFF)
			+ ((parser->game->ceiling_color >> 8) & 0xFF)) < (255 * 3) / 2)
		parser->game->hud.minimap_color = WHITE;
	parser->game->hud.torch_pos.y = WINDOW_HEIGHT
		- parser->torch_sprite_sheet->height;
}

void	setup_hud(t_game *game)
{
	game->hud.image = mlx_new_image(game->mlx, game->mlx->width,
			game->mlx->height);
	if (!game->hud.image)
		game_fail(game, CUB_MLXFAIL, "Failed to create image");
	draw_circle(&game->hud, MINIMAP_RADIUS + MINIMAP_FRAME_WIDTH,
		game->hud.minimap_color);
	draw_minimap(game);
	game->hud.torch_pos.x = (game->mlx->width / 7) * 5;
	game->hud.torch_pos.y = game->mlx->height
		- game->hud.torch_textures[0]->height;
	animate_torch(game, true);
	if (mlx_image_to_window(game->mlx, game->hud.image, 0, 0) == -1)
		game_fail(game, CUB_MLXFAIL, "Failed to render hud");
	mlx_set_instance_depth(game->hud.image->instances, 2);
}
