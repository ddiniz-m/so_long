#include "so_long.h"

int close_game(t_game *game)
{
	mlx_destroy_image(game->mlx,game->image.sea_img);
	mlx_destroy_image(game->mlx,game->image.land_img);
	mlx_destroy_image(game->mlx,game->image.collect_img);
	mlx_destroy_image(game->mlx,game->image.player_img);
	mlx_destroy_image(game->mlx,game->image.exit_img);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->tile_map);
	free(game->mlx);
	exit(1);
	get_next_line(-1);
	return(0);
}