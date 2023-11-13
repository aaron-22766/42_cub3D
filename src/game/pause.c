#include "../../include/cub3D.h"

static void	render_no_blur(t_game *game)
{
	uint32_t	x;
	uint32_t	y;

	y = 0;
	while (y < game->pause_screen->height)
	{
		x = 0;
		while (x < game->pause_screen->width)
			mlx_put_pixel(game->pause_screen, x++, y, PAUSE_NO_BLUR);
		y++;
	}
}

static void	put_pause_texture(t_game *game)
{
	t_pixel		p;
	uint32_t	x_offset;
	uint32_t	y_offset;

	x_offset = game->mlx->width / 2 - game->pause_texture->width / 2;
	y_offset = game->mlx->height / 2 - game->pause_texture->height / 2;
	p.y = 0;
	while (p.y < game->pause_texture->height)
	{
		p.x = 0;
		while (p.x < game->pause_texture->width)
		{
			p.color = get_pixel_txt(game->pause_texture, p.x, p.y);
			if (p.color & 0xFF)
				mlx_put_pixel(game->pause_screen, x_offset + p.x,
					y_offset + p.y, p.color);
			p.x++;
		}
		p.y++;
	}
}

void	render_pause_screen(t_game *game)
{
	if (!game->paused)
	{
		game->pause_screen->enabled = false;
		return ;
	}
	if (!render_blur(game))
		render_no_blur(game);
	put_pause_texture(game);
	game->pause_screen->enabled = true;
}

void	toggle_pause(t_game *game)
{
	int32_t	temp_mouse_y;

	game->paused = !game->paused;
	if (game->paused)
	{
		mlx_set_cursor_mode(game->mlx, MLX_MOUSE_NORMAL);
		if (PRINT)
			printf("Game paused\n\033[A\033[K\r");
	}
	else
	{
		mlx_set_cursor_mode(game->mlx, MLX_MOUSE_DISABLED);
		mlx_get_mouse_pos(game->mlx, &game->mouse_x, &temp_mouse_y);
	}
	render_pause_screen(game);
}
