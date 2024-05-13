/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:33:52 by aapadill          #+#    #+#             */
/*   Updated: 2024/05/13 20:06:16 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** @description
** see man printf
**
** @param
** format: string with format to print, includes many escape sequences, flags
** and format characters
** arguments: va_list with the elements of the format characters
**
** @return
** number of characters printed, negative if error
*/

#include "../include/ft_printf.h"

int	ft_printf_helper(const char *c, va_list args, int *count)
{
	if ((*c == 'c' && !ft_putchar(va_arg(args, int), count))
		|| (*c == 's' && !ft_putstr(va_arg(args, char *), count))
		|| (*c == 'p' && (!ft_putstr("0x", count) || !ft_putnbr_u(va_arg(args, unsigned long), "0123456789abcdef", count)))
		|| ((*c == 'd' || *c == 'i') && !ft_putnbr(va_arg(args, int), "0123456789", count))
		|| (*c == 'u' && !ft_putnbr(va_arg(args, unsigned int), "0123456789", count))
		|| (*c == 'x' && !ft_putnbr(va_arg(args, unsigned int), "0123456789abcdef", count))
		|| (*c == 'X' && !ft_putnbr(va_arg(args, unsigned int), "0123456789ABCDEF", count))
		|| (*c == '%' && !ft_putchar('%', count)))
		return (0);
	else
		return (1);
}

int	ft_printf(const char *format, ...)
{
	const char	*c;
	va_list		args;
	int			count;

	count = 0;
	c = format;
	va_start(args, format);
	while (*c)
	{
		if (*c == '%' && *(c + 1) && c++)
		{
			if (!ft_printf_helper(c, args, &count))
				break ;
		}
		else if (!ft_putchar(*c, &count))
			break ;
		c++;
	}
	va_end(args);
	return (count);
}
