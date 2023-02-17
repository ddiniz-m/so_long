/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:52:04 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/02/17 18:30:27 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// line counter and component checker
// returns -1 if components are not the correct amount
// returns number of lines (map_y)
// defines number of collectibles (collect_og)
int	map_lines(int fd, t_game *game)
{
	int		j;
	char	buf;

	j = 0;
	game->map_y = 1;
	game->collect_og = 0;
	while (read(fd, &buf, 1) > 0)
	{
		if (buf == '\n')
			game->map_y++;
		if (buf == 'C')
			game->collect_og++;
		if (buf == 'P' || buf == 'E')
			j++;
		if (buf != '0' && buf != '1' && buf != 'P' && buf != 'C'
			&& buf != 'E' && buf != '\n')
			return (-1);
	}
	if (j != 2 || game->collect_og <= 0)
		return (-1);
	return (game->map_y);
}

// .ber to **char converter
// returns 1 if map_lines return -1
// returns 2 if malloc fails
int	map(t_game *game, char *ber_file)
{
	int		j;
	int		i;
	int		fd;

	j = 0;
	fd = open(ber_file, O_RDONLY);
	i = map_lines(fd, game);
	if (i < 0)
		return (1);
	game->tile_map = malloc(sizeof(char *) * (i + 1));
	close(fd);
	fd = open(ber_file, O_RDONLY);
	while (j < i)
	{
		game->tile_map[j] = get_next_line(fd);
		j++;
	}
	close(fd);
	return (0);
}

int	check_rect_wall(t_game *game)
{
	int	line;
	int	col;

	game->map_y = 0;
	game->map_x = 0;
	while (game->tile_map[0][game->map_y] == '1')
		game->map_y++;
	while (game->tile_map[game->map_x] && game->tile_map[game->map_x][0] == '1')
		game->map_x++;
	line = game->map_y;
	col = game->map_x;
	game->map_y = 0;
	game->map_x = 0;
	while (game->tile_map[col - 1][game->map_y] == '1')
		game->map_y++;
	while (game->tile_map[game->map_x] && game->tile_map[game->map_x][line - 1] == '1')
		game->map_x++;
	if (game->map_y != line || game->map_x != col)
		return (-1);
	return (1);
}

void	player_pos(t_game *game, char **map, int y, int x)
{
	while (map[y] && y < game->map_y && x < game->map_x)
	{
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				game->player.y = y * 64;
				game->player.x = x * 64;
				return;
			}
			x++;
		}
		y++;
		x = 0;
	}
}

int	path_check(t_game *game, char **map, int y, int x)
{
	while (map[y] && y < game->map_y && x < game->map_x)
	{
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
			{
				printf("Error\nNo path available to exit or collectible\n");
				return(-1);
			}
			x++;
		}
		y++;
		x = 0;
	}
	return(0);
}


void	flood_fill(t_game *game, int x, int y)
{
	if (game->map_buff[y][x] == '1' || y < 0 || y >= game->map_x || x < 0
		|| game->tile.x >= game->map_y)
		return ;
	if (game->map_buff[y][x] == '0' || game->map_buff[y][x] == 'C'
		|| game->map_buff[y][x] == 'P' || game->map_buff[y][x] == 'E')
	{
		if (game->map_buff[y][x] == '0')
			game->map_buff[y][x] = 'o';
		if (game->map_buff[y][x] == 'C')
			game->map_buff[y][x] = 'c';
		if (game->map_buff[y][x] == 'E')
			game->map_buff[y][x] = 'e';
		if (game->map_buff[y][x] == 'P')
			game->map_buff[y][x] = 'p';
		flood_fill(game, x + 1, y);
		flood_fill(game, x - 1, y);
		flood_fill(game, x, y + 1);
		flood_fill(game, x, y - 1);
	}
}

void	map_init(t_game *game)
{
	int		i;

	i = 0;
	player_pos(game, game->tile_map, 0, 0);
	game->map_buff = malloc(sizeof(char *) * (game->map_x + 1));
	while (i < game->map_x)
	{
		game->map_buff[i] = malloc(sizeof(char) * (strlen(game->tile_map[i]) + 1));
		strcpy(game->map_buff[i], game->tile_map[i]);
		i++;
	}
	flood_fill(game, game->player.x / 64, game->player.y / 64);
	/* i = 0;
	while (1)
	{
		if (game->tile_map[i] == NULL)
			break ;
		printf("tile_map %i = %s", i, game->tile_map[i]);
		i++;
	}
	i = 0;
	printf("\n\n");
	while (1)
	{
		if (game->map_buff[i] == NULL)
			break ;
		printf("map_buff %i = %s", i, game->map_buff[i]);
		i++;
	} */
}

int	errors(t_game *game, char *ber_file)
{
	int	i;

	i = map(game, ber_file);
	if (i == 1)
	{
		printf("Error\nMap doesn't contain the correct components\n");
		return (-1);
	}
	if (i == -1)
	{
		printf("Error\nMap memory allocation error\n");
		return (-1);
	}
	if (check_rect_wall(game) < 0)
	{
		printf("Error\nMap not rectangular or not surrounded by walls\n");
		return (-1);
	}
	return (0);
}
