/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:52:04 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/01/24 13:54:15 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_lines(int fd)
{
	int			i;
	static char	buf[1];

	i = 0;
	while (read(fd, buf, 1) > 0)
	{
		if (*buf == '\n')
			i++;
	}
	i++;
	return (i);
}

char	**map(char *ber_file)
{
	int		i;
	int		j;
	int		fd;
	char	**map;

	j = 0;
	fd = open(ber_file, O_RDONLY);
	i = map_lines(fd);
	map = malloc(sizeof(char *) * (i + 1));
	fd = open(ber_file, O_RDONLY);
	while (j <= i)
	{
		map[j] = get_next_line(fd);
		j++;
	}
	return (map);
}

int	check_rect_wall(char **map)
{
	int	x;
	int	y;
	int	line;
	int	col;

	x = 0;
	y = 0;
	while (map[0][x] == '1')
		x++;
	while (map[y] && map[y][0] == '1')
		y++;
	line = x;
	col = y;
	x = 0;
	y = 0;
	while (map[col - 1][x] == '1')
		x++;
	while (map[y] && map[y][line - 1] == '1')
		y++;
	if (x != line || y != col)
	{
		printf("Error\nMap not rectangular or not surrounded by walls\n");
		return (-1);
	}
	return (0);
}
