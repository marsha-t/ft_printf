/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:57:35 by mateo             #+#    #+#             */
/*   Updated: 2024/01/10 17:51:28 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dlen(int arg)
{
	int	i;

	i = 1;
	while (arg / 10)
	{
		arg /= 10;
		i++;
	}
	return (i);
}

long long	ft_abs(long arg)
{
	long long	temp;

	temp = arg;
	if (temp < 0)
		return (-temp);
	return (temp);
}

void	ft_tidyconv_d(t_conv*conv, int arg)
{
	conv->i = ft_dlen(arg);
	if (arg == 0 && (conv->prec) && !(conv->prec_n))
		conv->i = 0;
	if (arg < 0)
	{
		conv->space = 0;
		conv->sign = 1;
	}
	if (conv->prec_n < conv->i)
		conv->prec_n = conv->i;
	if ((!(conv->space) && !(conv->sign)) \
		&& (conv->width_n < conv->prec_n))
		conv->width_n = conv->prec_n;
	else if (((conv->space) || (conv->sign)) \
		&& (conv->width_n < (conv->prec_n + 1)))
		conv->width_n = conv->prec_n + 1;
	conv->pad = conv->width_n - conv->prec_n;
	if (conv->space || conv->sign)
		conv->pad -= 1;
}

int	ft_conv_d(t_conv *conv, int arg)
{
	ft_tidyconv_d(conv, arg);
	if (conv->space && ft_putc_r(' ') < 0)
		return (-1);
	while (!(conv->left) && !(conv->zero) && (conv->pad)--)
		if (ft_putc_r(' ') < 0)
			return (-1);
	if (conv->sign && arg >= 0 && ft_putc_r('+') < 0)
		return (-1);
	if (conv->sign && arg < 0 && ft_putc_r('-') < 0)
		return (-1);
	while (!(conv->left) && conv->zero && (conv->pad)--)
		if (ft_putc_r('0') < 0)
			return (-1);
	while ((conv->i)++ < conv->prec_n)
		if (ft_putc_r('0') < 0)
			return (-1);
	if (!(conv->prec && !(conv->prec_n) && !arg) && \
		ft_putnbr_ret(ft_abs(arg)) < 0)
		return (-1);
	while (conv->left && (conv->pad)--)
		if (ft_putc_r(' ') < 0)
			return (-1);
	return (conv->width_n);
}
