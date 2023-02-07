#include "so_long.h"

int	open_images(t_game *game)
{
	int size = tile_size;

	game->image.sea_img = mlx_xpm_file_to_image(game->mlx, path_sea, &size, &size);
	game->image.land_img = mlx_xpm_file_to_image(game->mlx, path_land, &size, &size);
	game->image.collect1_img = mlx_xpm_file_to_image(game->mlx, path_collect1, &size, &size);
	game->image.collect2_img = mlx_xpm_file_to_image(game->mlx, path_collect2, &size, &size);
	game->image.collect3_img = mlx_xpm_file_to_image(game->mlx, path_collect3, &size, &size);
	game->image.collect4_img = mlx_xpm_file_to_image(game->mlx, path_collect4, &size, &size);
	game->image.collect5_img = mlx_xpm_file_to_image(game->mlx, path_collect5, &size, &size);
	game->image.player_img = mlx_xpm_file_to_image(game->mlx, path_player, &size, &size);
	game->image.exit_img = mlx_xpm_file_to_image(game->mlx, path_exit, &size, &size);
	/* game->tile_img.land_img = mlx_xpm_file_to_image(game->mlx, path_enemy, &size, &size); */\
	return(0);
}