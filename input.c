/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:03:34 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/01/31 17:17:31 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int input(int key, t_game *game)
{
	if (key == 65307)
		close_game(game);
	if (key == 100)
		game->player.x += 1;
	if (key == 97)
		game->player.x -= 1;
	if (key == 115)
		game->player.y += 1;
	if (key == 119)
		game->player.y -= 1;
	
	return(0);
}