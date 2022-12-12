/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:05:54 by jaehulee          #+#    #+#             */
/*   Updated: 2022/12/12 12:34:19 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_heximal(va_list ap, char spec, int *point)
{
	unsigned int	value;
	char			*base;

	base = NULL;
	value = va_arg(ap, int);
	if (spec == 'x')
		base = "0123456789abcdef";
	else if (spec == 'X')
		base = "0123456789ABCDEF";
	ft_print_heximal(value, point, base);
}

void	ft_print_heximal(unsigned int n, int *point, char *base)
{
	long long	num;

	num = n;
	if (num < 0)
	{
		num *= -1;
		num = 4294967296 - num;
	}
	if (num / 16 > 0)
		ft_print_heximal(num / 16, point, base);
	if (*point == -1)
		return ;
	(*point)++;
	ft_putchar(base[num % 16], point);
}

void	ft_pointer(va_list ap, int *point)
{
	size_t	value;
	char	*base;

	value = (size_t)va_arg(ap, char *);
	base = "0123456789abcdef";
	if (ft_putchar('0', point) == -1)
		return ;
	if (ft_putchar('x', point) == -1)
		return ;
	(*point) += 2;
	if (!value)
	{
		if (ft_putchar('0', point) == -1)
			return ;
		(*point)++;
	}
	else
		ft_print_pointer(value, point, base);
}

void	ft_print_pointer(size_t num, int *point, char *base)
{
	if (num < 0)
	{
		num *= -1;
		num = 4294967296 - num;
	}
	if (num / 16 > 0)
		ft_print_pointer(num / 16, point, base);
	(*point)++;
	if (*point == -1)
		return ;
	ft_putchar(base[num % 16], point);
}