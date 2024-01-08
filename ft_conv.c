/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:27:21 by mateo             #+#    #+#             */
/*   Updated: 2024/01/04 18:27:21 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_s(char *str)
{
	ssize_t	write_ret;

	if (str)
	{
		write_ret = write(1, str, ft_strlen(str));
		if (write_ret == -1)
			return (-1);
		return (ft_strlen(str));
	}
	else
		return (ft_conv_s("(null)"));
}

int	ft_conv_d(int n)
{
	long long	x;
	int			count;
	int			temp;

	count = 0;
	x = n;
	if (x < 0)
	{
		temp = ft_conv_c('-');
		if (temp < 0)
			return (-1);
		count += temp;
		x = -x;
	}
	if (x >= 10)
	{
		temp = ft_conv_d(x / 10);
		if (temp < 0)
			return (-1);
		count += temp;
	}
	temp = ft_conv_c(x % 10 + '0');
	if (temp < 0)
		return (-1);
	count += temp;
	return (count);
}

int	ft_conv_u(unsigned int n)
{
	char	c;
	int		count;
	int		temp;

	count = 0;
	if (n >= 10)
	{
		temp = ft_conv_u(n / 10);
		if (temp < 0)
			return (-1);
		count += temp;
	}
	c = n % 10 + '0';
	temp = ft_conv_c(c);
	if (temp < 0)
		return (-1);
	count += temp;
	return (count);
}

int	ft_conv_x(unsigned long long c, char *base16)
{
	int	count;
	int	temp;

	count = 0;
	if (c >= 16)
	{
		temp = ft_conv_x(c / 16, base16);
		if (temp < 0)
			return (-1);
		count += temp;
	}
	temp = ft_conv_c(base16[c % 16]);
	if (temp < 0)
		return (-1);
	count += temp;
	return (count);
}

int	ft_conv_p(unsigned long long addr)
{
	int	count;
	int	temp;

	count = 0;
	temp = ft_conv_s("0x");
	if (temp < 0)
		return (-1);
	count += temp;
	temp = ft_conv_x(addr, BASE16_SMALL);
	if (temp < 0)
		return (-1);
	count += temp;
	return (count);
}
