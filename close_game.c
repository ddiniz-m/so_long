#include "so_long.h"

int close_game(int keycode, t_window *window)
{
	if (keycode == 65307)
		return(mlx_destroy_window(window->mlx, window->win));
	else
		return(0);
}