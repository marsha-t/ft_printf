/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:37:43 by mateo             #+#    #+#             */
/*   Updated: 2024/01/10 15:10:35 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putc_r(int c)
{
	return (write(1, &c, 1));
}

int	ft_puthex_r(unsigned long long c, char *base16)
{
	int	count;
	int	write_r;

	count = 0;
	if (c >= 16)
	{
		write_r = ft_puthex_r(c / 16, base16);
		if (write_r < 0)
			return (-1);
		count += write_r;
	}
	write_r = ft_putc_r(base16[c % 16]);
	if (write_r < 0)
		return (-1);
	count += write_r;
	return (count);
}

int	ft_putnbr_ret_neg(long long *x)
{
	if (x < 0)
	{
		*x *= -1;
		return (ft_putc_r('-'));
	}
	return (0);
}

int	ft_putnbr_ret(long n)
{
	char		c;
	long long	x;
	int			count;
	int			write_r;

	count = 0;
	x = n;
	write_r = ft_putnbr_ret_neg(&x);
	if (write_r < 0)
		return (-1);
	count += write_r;
	count += ft_dlen(x);
	if (x >= 10)
	{
		if (ft_putnbr_ret(x / 10) < 0)
			return (-1);
		count += write_r;
	}
	c = x % 10 + '0';
	if (ft_putc_r(c) < 0)
		return (-1);
	return (count);
}

// int	ft_putnbr_ret(long n)
// {
// 	char		c;
// 	long long	x;
// 	int			count;
// 	int			write_r;

// 	count = 0;
// 	x = n;
// 	write_r = ft_putnbr_ret_neg(&x);
// 	if (write_r < 0)
// 		return (-1);
// 	count += write_r;
// 	if (x >= 10)
// 	{
// 		write_r = ft_putnbr_ret(x / 10);
// 		if (write_r < 0)
// 			return (-1);
// 		count += write_r;
// 	}
// 	c = x % 10 + '0';
// 	write_r = ft_putc_r(c);
// 	if (write_r < 0)
// 		return (-1);
// 	count += write_r;
// 	return (count);
// }

// int	ft_putnbr_ret(long n)
// {
// 	char		c;
// 	long long	x;
// 	int			count;
// 	int			write_r;

// 	count = 0;
// 	x = n;
// 	if (x < 0)
// 	{
// 		write_r = ft_putc_r('-');
// 		if (write_r < 0)
// 			return (-1);
// 		count += write_r;
// 		x = -x;
// 	}
// 	if (x >= 10)
// 	{
// 		write_r = ft_putnbr_ret(x / 10);
// 		if (write_r < 0)
// 			return (-1);
// 		count += write_r;
// 	}
// 	c = x % 10 + '0';
// 	write_r = ft_putc_r(c);
// 	if (write_r < 0)
// 		return (-1);
// 	count += write_r;
// 	return (count);
// }

int	ft_putunbr_ret(unsigned int n)
{
	char	c;
	int		count;
	int		write_r;	

	count = 0;
	if (n >= 10)
	{
		write_r = ft_putunbr_ret(n / 10);
		if (write_r < 0)
			return (-1);
	}
	c = n % 10 + '0';
	write_r = ft_putc_r(c);
	if (write_r < 0)
		return (-1);
	return (count);
}
