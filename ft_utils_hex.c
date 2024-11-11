/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:21:28 by aahadji           #+#    #+#             */
/*   Updated: 2024/11/09 17:23:32 by aahadji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_hex_recur(unsigned long long n, const char *base, int *len)
{
	if (n > 15)
	{
		ft_hex_recur(n / 16, base, len);
	}
	ft_putchar_fd(base[n % 16], 1);
	(*len)++;
}

int	ft_put_hex_fd(const unsigned long long n, int maj)
{
	char	*text;
	int		len;

	len = 0;
	if (maj == 1)
		text = "0123456789ABCDEF";
	else
		text = "0123456789abcdef";
	if (!n)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	ft_hex_recur(n, text, &len);
	return (len);
}

int	ft_put_address(const void *ptr)
{
	return (ft_putstr_fd("0x", 1) + ft_put_hex_fd((unsigned long long)ptr, 0));
}
