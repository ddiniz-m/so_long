#include "so_long.h"

void	open_images(t_game *game)
{
	int size = tile_size;

	game->tile_img.sea_img = mlx_xpm_file_to_image(game->mlx, path_sea, &size, &size);
	game->tile_img.land_img = mlx_xpm_file_to_image(game->mlx, path_land, &size, &size);
	game->tile_img.collect_img = mlx_xpm_file_to_image(game->mlx, path_collect, &size, &size);
	game->tile_img.player_img = mlx_xpm_file_to_image(game->mlx, path_player, &size, &size);
	game->tile_img.exit_img = mlx_xpm_file_to_image(game->mlx, path_exit, &size, &size);
	/* game->tile_img.land_img = mlx_xpm_file_to_image(game->mlx, path_enemy, &size, &size); */
}