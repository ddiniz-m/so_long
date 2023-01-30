/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:03:34 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/01/30 17:44:44 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int input(int key, t_game *game)
{
	if (key == 65307)
		close_game(game);
	if (key == 100)
	{
		game->image.x += 1;
		printf("\nx = %i\n", game->image.x);
	}
	if (key == 97)
	{
		game->image.x -= 1;
		printf("A\n");
	}
	if (key == 115)
	{
		game->image.y += 1;
		printf("S\n");
	}
	if (key == 119)
	{
		game->image.y -= 1;
		printf("W\n");
	}
	return(0);
}