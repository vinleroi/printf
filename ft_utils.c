/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:42:57 by aahadji           #+#    #+#             */
/*   Updated: 2024/11/10 11:17:30 by aahadji          ###   ########.fr       */
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
	while (s[i])
	{
		if (ft_putchar_fd(s[i], fd))
			i++;
		else
			return (-1);
	}
	return (i);
}

static void	write_nbr(int n, int fd, int *len)
{
	char	result;

	if (n < 10)
	{
		result = n + '0';
		write(fd, &result, 1);
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
	int	*len;

	len = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	write_nbr(n, fd, len);
	return (*len);
}

int	ft_putnbr_u_fd(const unsigned int n, int fd)
{
	int	*len;

	len = 0;
	write_nbr(n, fd, len);
	return (*len);
}
