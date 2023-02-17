/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:00:03 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/01/16 14:21:14 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"

int		ft_printf(const char *str, ...);

int		ft_puthexa(unsigned long long nbr, unsigned long long base, int i);

int		ft_check(char str, va_list args);

int		ft_putstr(char *str);

int		ft_putchar(char c);

int		ft_putnbr(int nb);

int		ft_putptr(unsigned long nbr);

int		conv(unsigned long long nbr, unsigned long long base, char *base_str);

#endif //ends condition