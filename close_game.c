#include "so_long.h"

int close_game(int keycode, t_game *game)
{
	if (keycode == 65307)
		return(mlx_destroy_window(game->mlx, game->win));
	else
		return(0);
}