/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:46:15 by jaehulee          #+#    #+#             */
/*   Updated: 2022/12/12 12:34:30 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char(va_list ap, int *point)
{
	int			value;

	value = va_arg(ap, int);
	if (ft_putchar(value, point) == -1)
		return ;
	(*point)++;
}

void	ft_string(va_list ap, int *point)
{
	char	*value;
	char	*err;

	value = va_arg(ap, char *);
	err = "(null)";
	if (!value)
	{
		while (*err)
		{
			if (ft_putchar(*err, point) == -1)
				return ;
			err++;
		}
		(*point) += 6;
		return ;
	}
	while (*value)
	{
		if (ft_putchar(*value, point) == -1)
			return ;
		value++;
		(*point)++;
	}
}

void	ft_signed_decimal(va_list ap, char spec, int *point)
{
	int		value;
	char	*base;

	value = va_arg(ap, int);
	base = "0123456789";
	ft_print_decimal(value, point, spec, base);
	if (*point == -1)
		return ;
}

void	ft_unsigned_decimal(va_list ap, char spec, int *point)
{
	unsigned int	value;
	char			*base;

	value = va_arg(ap, int);
	base = "0123456789";
	ft_print_decimal(value, point, spec, base);
}

void	ft_print_decimal(int n, int *point, char spec, char *base)
{
	long long	num;

	num = n;
	if (num < 0 && spec == 'u')
	{
		num *= -1;
		num = 4294967296 - num;
	}
	if (num < 0 && (spec == 'd' || spec == 'i'))
	{
		num *= -1;
		if (ft_putchar('-', point) == -1)
			return ;
		(*point)++;
	}
	if (num / 10 > 0)
		ft_print_decimal(num / 10, point, spec, base);
	if (*point == -1)
		return ;
	(*point)++;
	ft_putchar(base[num % 10], point);
}