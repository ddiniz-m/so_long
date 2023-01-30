#include "so_long.h"

int close_game(t_game *game)
{
	mlx_destroy_image(game->mlx,game->tileimg.sea_img);
	mlx_destroy_image(game->mlx,game->tileimg.land_img);
	mlx_destroy_image(game->mlx,game->tileimg.collect_img);
	mlx_destroy_image(game->mlx,game->tileimg.player_img);
	mlx_destroy_image(game->mlx,game->tileimg.exit_img);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(1);
	return(0);
}