/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:48:39 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/02/23 17:01:05 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*get_next_line(int fd)
{
	char	res;
	char	*line;

	if (read(fd, NULL, 0) < 0)
	{
		res = 0;
		return (NULL);
	}
	line = NULL;
	res = 0;
	while (read(fd, &res, 1) > 0)
	{
		line = get_lines(line, res);
		if (res == '\n')
			break ;
	}
	return (line);
}

/* int	main(void)
{
	int fd;
	char *line;

	fd = open("gnl/test.txt", O_RDONLY);
	printf("%d\n", fd);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
	}
	close(fd);
	return (0);
} */