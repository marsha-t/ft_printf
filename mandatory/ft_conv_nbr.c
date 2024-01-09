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

static int	ft_conv2_d(long long *xp)
{
	int	temp;

	if (*xp < 0)
	{
		*xp *= -1;
		temp = ft_conv_c('-');
		return (temp);
	}
	return (0);
}

int	ft_conv_d(int n)
{
	long long	x;
	int			count;
	int			temp;

	x = n;
	count = ft_conv2_d(&x);
	if (count < 0)
		return (-1);
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
