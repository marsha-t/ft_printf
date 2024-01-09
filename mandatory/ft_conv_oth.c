/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_oth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:25:11 by mateo             #+#    #+#             */
/*   Updated: 2024/01/08 17:31:53 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_c(int c)
{
	return (write(1, &c, 1));
}

int	ft_conv_s(char *str)
{
	if (str)
		return (write(1, str, ft_strlen(str)));
	else
		return (write(1, "(null)", 6));
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
