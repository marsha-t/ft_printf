/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:56:20 by mateo             #+#    #+#             */
/*   Updated: 2024/01/10 17:31:17 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_plen(unsigned long long arg)
{
	int	i;

	i = 1;
	while (arg / 16 != 0)
	{
		arg = arg / 16;
		i++;
	}
	return (i);
}

void	ft_tidyconv_p(t_conv *conv, unsigned long long arg)
{
	conv->i = ft_plen(arg);
	if (!arg && (conv->prec) && !(conv->prec_n))
		conv->i = 0;
	if (conv->prec_n < conv->i)
		conv->prec_n = conv->i;
	if (conv->width_n < conv->prec_n + 2)
		conv->width_n = conv->prec_n + 2;
	conv->pad = conv->width_n - conv->prec_n - 2;
}

int	ft_conv_p(t_conv *conv, unsigned long long arg)
{
	ft_tidyconv_p(conv, arg);
	while (!(conv->left) && (conv->pad)--)
		if (ft_putc_r(' ') < 0)
			return (-1);
	if (write(1, "0x", 2) < 0)
		return (-1);
	while ((conv->i)++ < conv->prec_n)
		if (ft_putc_r('0') < 0)
			return (-1);
	if (!(conv->prec && !(conv->prec_n) && !arg))
		if (ft_puthex_r(arg, BASE16_SMALL) < 0)
			return (-1);
	while (conv->left && (conv->pad)--)
		if (ft_putc_r(' ') < 0)
			return (-1);
	return (conv->width_n);
}
