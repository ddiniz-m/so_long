#include "so_long.h"

int	main(int ac, char **av)
{
	t_game game;

	if (ac != 2)
		return(printf("Incorrect amount of arguments"));
	if (errors(&game, av[1]) < 0)
		return(0);
	
	game.win_size_x = game.map_y * TILE_SIZE;
	game.win_size_y = game.map_x * TILE_SIZE;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.win_size_x, game.win_size_y, "so_long");

	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_hook(game.win, 2, 1L << 0 ,input, &game);
	open_images(&game);
	mlx_loop_hook(game.mlx, render_frames, &game);

	mlx_loop(game.mlx);
}