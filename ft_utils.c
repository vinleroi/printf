/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:42:57 by aahadji           #+#    #+#             */
/*   Updated: 2024/11/11 11:49:35 by aahadji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(const char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putstr_fd(const char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr_fd("(null)", 1));
	while (s[i])
	{
		if (ft_putchar_fd(s[i], fd))
			i++;
		else
			return (-1);
	}
	return (i);
}

static void	write_nbr(long n, int fd, int *len)
{
	char	result;

	if (n < 10)
	{
		result = n + '0';
		ft_putchar_fd(result, 1);
		(*len)++;
	}
	else
	{
		write_nbr(n / 10, fd, len);
		write_nbr(n % 10, fd, len);
	}
}

int	ft_putnbr_fd(int n, int fd)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if (n < 0)
	{
		len += ft_putchar_fd('-', fd);
		n *= -1;
	}
	write_nbr(n, fd, &len);
	return (len);
}

int	ft_putnbr_u_fd( unsigned int n, int fd)
{
	int	len;

	if (n == 4294967295)
		return (ft_putstr_fd("4294967295", fd));
	len = 0;
	write_nbr(n, fd, &len);
	return (len);
}
