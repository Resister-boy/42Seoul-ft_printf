/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:29:43 by jaehulee          #+#    #+#             */
/*   Updated: 2022/12/12 13:16:23 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(char chr, int *point);
int		ft_check_spec(va_list ap, char spec, int *point);
int		ft_check_is_spec(char *specs, char word);
int		ft_printf(const char *format, ...);
void	ft_char(va_list ap, int *point);
void	ft_string(va_list ap, int *point);
void	ft_signed_decimal(va_list ap, char spec, int *point);
void	ft_unsigned_decimal(va_list ap, char spec, int *point);
void	ft_print_decimal(int n, int *point, char spec, char *base);
void	ft_heximal(va_list ap, char spec, int *point);
void	ft_print_heximal(unsigned int n, int *point, char *base);
void	ft_pointer(va_list ap, int *point);
void	ft_print_pointer(size_t num, int *point, char *base);

#endif