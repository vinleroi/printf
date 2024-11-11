/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:13:14 by aahadji           #+#    #+#             */
/*   Updated: 2024/11/11 10:54:15 by aahadji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_fd(const char c, int fd);
int	ft_putstr_fd(const char *s, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_putnbr_u_fd( unsigned int n, int fd);
int	ft_put_hex_fd(unsigned long long n, int maj);
int	ft_put_address(const void *ptr);
#endif