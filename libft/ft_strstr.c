/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:07:47 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/02/23 19:39:21 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (to_find[j] != '\0' && str[i] == to_find[j])
		{
			i++;
			j++;
		}
		i++;
		if (to_find[j] == '\0')
		{
			return (str + (i - j - 1));
		}
	}
	if (to_find[0] == '\0')
	{
		return (str - 1);
	}
	return (0);
}
