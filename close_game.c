#include "so_long.h"

int close_game(t_game *game)
{
	mlx_destroy_image(game->mlx,game->image.sea_img);
	mlx_destroy_image(game->mlx,game->image.land_img);
	mlx_destroy_image(game->mlx,game->image.collect1_img);
	mlx_destroy_image(game->mlx,game->image.collect2_img);
	mlx_destroy_image(game->mlx,game->image.collect3_img);
	mlx_destroy_image(game->mlx,game->image.collect4_img);
	mlx_destroy_image(game->mlx,game->image.collect5_img);
	mlx_destroy_image(game->mlx,game->image.player_img);
	mlx_destroy_image(game->mlx,game->image.exit1_img);
	mlx_destroy_image(game->mlx,game->image.exit2_img);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	ft_free(game, game->tile_map);
	free(game->mlx);
	exit(0);
	return(0);
}