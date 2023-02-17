/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 19:05:12 by ddiniz-m          #+#    #+#             */
/*   Updated: 2022/11/16 13:02:17 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		if (nb == -2147483648)
			return (write(1, "-2147483648", 11));
		i += ft_putchar('-');
		i += ft_putnbr(-nb);
	}
	else
	{
		if (nb > 9)
			i += ft_putnbr(nb / 10);
		i += ft_putchar((nb % 10) + 48);
	}
	return (i);
}
