/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:03:34 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/02/03 14:50:32 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// keybinds and restriction of movement when adjacent tiles are '0'
int	input(int key, t_game *game)
{
	if (key == 65307)
		close_game(game);
	if (key == 100 && game->tile_map[game->player.y / 64][(game->player.x + 64)
		/ 64] != '1')
		game->player.x += 64;
	if (key == 97 && game->tile_map[game->player.y / 64][(game->player.x - 64)
		/ 64] != '1')
		game->player.x -= 64;
	if (key == 115 && game->tile_map[(game->player.y + 64) / 64][game->player.x
		/ 64] != '1')
		game->player.y += 64;
	if (key == 119 && game->tile_map[(game->player.y - 64) / 64][game->player.x
		/ 64] != '1')
		game->player.y -= 64;
	return (0);
}