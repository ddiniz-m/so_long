/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:52:04 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/02/27 13:32:20 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_pos(t_game *game, char **map, int y, int x)
{
	while (y < game->map_y && x < game->map_x)
	{
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				game->player.y = y * 64;
				game->player.x = x * 64;
				return ;
			}
			x++;
		}
		y++;
		x = 0;
	}
}

void	flood_fill(t_game *game, char **map, int x, int y)
{
	if (map[y][x] == '1' || y < 0 || y >= game->map_y || x < 0
		|| x >= game->map_x)
		return ;
	if (map[y][x] == '0' || map[y][x] == 'C'
		|| map[y][x] == 'P' || map[y][x] == 'E')
	{
		if (map[y][x] == '0')
			map[y][x] = 'o';
		if (map[y][x] == 'C')
			map[y][x] = 'c';
		if (map[y][x] == 'E')
			map[y][x] = 'e';
		if (map[y][x] == 'P')
			map[y][x] = 'p';
		flood_fill(game, map, x + 1, y);
		flood_fill(game, map, x - 1, y);
		flood_fill(game, map, x, y + 1);
		flood_fill(game, map, x, y - 1);
	}
}

int	path_check(t_game *game, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->map_y && x < game->map_x)
	{
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
			{
				ft_printf("Error\nNo path available to exit or collectible\n");
				return (-1);
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (0);
}

int	map_init(t_game *game)
{
	int		i;

	i = 0;
	player_pos(game, game->tile_map, 0, 0);
	game->map_buff = NULL;
	game->map_buff = malloc(sizeof(char *) * (game->map_y + 1));
	if (!game->map_buff)
		return (0);
	while (i < game->map_y)
	{
		game->map_buff[i] = malloc(sizeof(char) * (
					ft_strlen(game->tile_map[i]) + 1));
		ft_strcpy(game->map_buff[i], game->tile_map[i]);
		i++;
	}
	flood_fill(game, game->map_buff, game->player.x / 64, game->player.y / 64);
	if (path_check(game, game->map_buff) < 0)
	{
		ft_free(game, game->map_buff);
		return (-1);
	}
	ft_free(game, game->map_buff);
	return (0);
}
