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

int	ft_conv_c(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_conv_s(char *str)
{
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int	ft_conv_d(int n)
{
	char		c;
	long long	x;
	int			count;

	count = 0;
	x = n;
	if (x < 0)
	{
		count += ft_conv_c('-');
		x = -x;
	}
	if (x >= 10)
		count += ft_conv_d(x / 10);
	c = x % 10 + '0';
	count += ft_conv_c(c);
	return (count);
}

int	ft_conv_u(unsigned int n)
{
	char				c;
	int				count;

	count = 0;
	if (n >= 10)
		count += ft_conv_u(n / 10);
	c = n % 10 + '0';
	count += ft_conv_c(c);
	return (count);
}

int	ft_conv_x(unsigned long long c, char *base16)
{
	int	count;

	count = 0;
	if (c >= 16)
		count +=ft_conv_x(c / 16, base16);
	write(1, &base16[c % 16], 1);
	count++;
	return (count);
}

int	ft_conv_p(unsigned long long addr)
{
	int	count;

	count = 0;
	
	if (!addr)
		count += ft_conv_s("(nil)");
	else
	{
		count += ft_conv_s("0x");
		count += ft_conv_x(addr, BASE16_SMALL);
	}
	return (count);
}
