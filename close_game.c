#include "so_long.h"

int close_game(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(game->mlx,game->tile_img.sea_img);
		mlx_destroy_image(game->mlx,game->tile_img.land_img);
		mlx_destroy_image(game->mlx,game->tile_img.collect_img);
		mlx_destroy_image(game->mlx,game->tile_img.player_img);
		mlx_destroy_image(game->mlx,game->tile_img.exit_img);
		mlx_clear_window(game->mlx, game->win);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(1);
	}
	return(0);
}