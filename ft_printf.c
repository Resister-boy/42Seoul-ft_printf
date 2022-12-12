/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:18:29 by jaehulee          #+#    #+#             */
/*   Updated: 2022/12/12 12:28:44 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char chr, int *point)
{
	int	value;

	value = write(1, &chr, 1);
	if (value == -1)
	{
		(*point) = -1;
		return (-1);
	}
	return (1);
}

int	ft_check_is_spec(char *specs, char word)
{
	while (*specs)
	{
		if (*specs == word)
			return (1);
		specs++;
	}
	return (0);
}

int	ft_check_spec(va_list ap, char word, int *point)
{
	char	*specs;

	specs = "csdiuxXp%";
	if (word == '\0' || (!ft_check_is_spec(specs, word)))
		return (-1);
	if (word == specs[0])
		ft_char(ap, point);
	else if (word == specs[1])
		ft_string(ap, point);
	else if (word == specs[2] || word == specs[3])
		ft_signed_decimal(ap, word, point);
	else if (word == specs[4])
		ft_unsigned_decimal(ap, word, point);
	else if (word == specs[5] || word == specs[6])
		ft_heximal(ap, word, point);
	else if (word == specs[7])
		ft_pointer(ap, point);
	else if (word == specs[8])
	{
		if (ft_putchar('%', point) == -1)
			return (*point);
		(*point)++;
	}
	return (*point);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		point;
	char	word;

	point = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			word = *(format + 1);
			if (ft_check_spec(ap, word, &point) == -1)
				return (point);
			format++;
		}
		else
		{
			if (ft_putchar(*format, &point) == -1)
				return (point);
			point++;
		}
		format++;
	}
	va_end(ap);
	return (point);
}