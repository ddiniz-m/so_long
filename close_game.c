#include "so_long.h"

int close_game(int keycode, t_game *game)
{
	if (keycode == 65307)
		mlx_destroy_window(game->mlx, game->win);
	return(0);
}