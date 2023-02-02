#include "so_long.h"

int	open_images(t_game *game)
{
	int size = tile_size;

	game->image.sea_img = mlx_xpm_file_to_image(game->mlx, path_sea, &size, &size);
	game->image.land_img = mlx_xpm_file_to_image(game->mlx, path_land, &size, &size);
	game->image.collect_img = mlx_xpm_file_to_image(game->mlx, path_collect, &size, &size);
	game->image.player_img = mlx_xpm_file_to_image(game->mlx, path_player, &size, &size);
	game->image.exit_img = mlx_xpm_file_to_image(game->mlx, path_exit, &size, &size);
	/* game->tile_img.land_img = mlx_xpm_file_to_image(game->mlx, path_enemy, &size, &size); */\
	return(0);
}