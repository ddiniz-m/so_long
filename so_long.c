/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:30:19 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/02/27 13:42:03 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (printf("Error\nIncorrect amount of arguments\n"));
	if (ft_strstr(av[1], ".ber") == 0)
		return (printf("Error\nArgument is not a .ber file\n"));
	if (errors(&game, av[1]) < 0)
		return (0);
	if (map_init(&game) < 0)
		return (0);
	game.collect = 0;
	game.win_size_y = game.map_y * TILE_SIZE;
	game.win_size_x = game.map_x * TILE_SIZE;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.win_size_x,
			game.win_size_y, "so_long");
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_hook(game.win, 2, 1L << 0, input, &game);
	open_images(&game);
	mlx_loop_hook(game.mlx, render_frames, &game);
	mlx_loop(game.mlx);
}
