/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:15:16 by aahadji           #+#    #+#             */
/*   Updated: 2024/11/10 20:50:51 by aahadji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

static int	add_number(char temp, va_list *args)
{
	int	lenght;

	lenght = 0;
	if (temp == 'd' || temp == 'i')
		lenght += ft_putnbr_fd((int)va_arg(*args, int), 1);
	else if (temp == 'u')
		lenght += ft_putnbr_u_fd((unsigned int)va_arg(*args, unsigned int), 1);
	else if (temp == 'X')
		lenght += ft_put_hex_fd((unsigned int)va_arg(*args, unsigned int), 1);
	else if (temp == 'x')
		lenght += ft_put_hex_fd((unsigned int)va_arg(*args, unsigned int), 0);
	else
		return (0);
	return (lenght);
}

static int	add_char(char temp, va_list *args)
{
	int		lenght;
	char	ch;

	lenght = 0;
	if (temp == 0)
		return (-1);
	if (temp == 'c')
	{
		ch = (char)va_arg(*args, int);
		lenght += ft_putchar_fd(ch, 1);
	}
	else if (temp == 's')
		lenght += ft_putstr_fd((char *)va_arg(*args, char *), 1);
	else if (temp == 'p')
		lenght += ft_put_address((void *)va_arg(*args, void *));
	else if (temp == '%')
		lenght += ft_putchar_fd('%', 1);
	else
		lenght += add_number(temp, args);
	return (lenght);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		lenght;

	va_start(args, format);
	lenght = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			printf("HAAAAAAAA test AAAAAAAAH");
			i++;
			lenght += add_char(format[i], &args);
		}
		else
		{
			if (ft_putchar_fd(format[i], 1) > 0)
				lenght++;
			else
				return (-1);
		}
		i++;
	}
	va_end(args);
	return (lenght);
}

int	main(void)
{
	int	num;

	// Test for %u (unsigned integer)
	printf("Standard printf:\n");
	printf("Unsigned integer test: %u\n", 12345);
	ft_printf("Custom ft_printf:\n");
	ft_printf("Unsigned integer test: %u\n", 12345);
	/// Test for %x (hexadecimal, lowercase)
	printf("Standard printf:\n");
	printf("Hexadecimal (lowercase) test: %x\n", 255);
	ft_printf("Custom ft_printf:\n");
	ft_printf("Hexadecimal (lowercase) test: %x\n", 255);
	// Test for %X (hexadecimal, uppercase)
	printf("Standard printf:\n");
	printf("Hexadecimal (uppercase) test: %X\n", 255);
	ft_printf("Custom ft_printf:\n");
	ft_printf("Hexadecimal (uppercase) test: %X\n", 255);
	// Test for %p (pointer address)
	num = 42;
	printf("Standard printf:\n");
	printf("Pointer test: %p\n", &num);
	ft_printf("Custom ft_printf:\n");
	ft_printf("Pointer test: %p\n", &num);
	// Test for %% (percent sign)
	printf("Standard printf:\n");
	printf("Percent test: %%\n");
	ft_printf("Custom ft_printf:\n");
	ft_printf("Percent test: %%\n");
	// Test for %d and %i (signed integers)
	printf("Standard printf:\n");
	printf("Signed integer test (d): %d\n", -12345);
	printf("Signed integer test (i): %i\n", 12345);
	ft_printf("Custom ft_printf:\n");
	ft_printf("Signed integer test (d): %d \n", -12345);
	ft_printf("Signed integer test (i): %i \n", 12345);
	// Additional boundary tests
	printf("Boundary Tests:\n");
	printf("INT_MAX: %d, INT_MIN: %d\n", INT_MAX, INT_MIN);
	ft_printf("INT_MAX: %d, INT_MIN: %d\n", INT_MAX, INT_MIN);
	printf("UINT_MAX: %u\n", UINT_MAX);
	ft_printf("UINT_MAX: %u\n", UINT_MAX);
	return (0);
}
