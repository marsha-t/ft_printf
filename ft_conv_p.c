/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:56:20 by mateo             #+#    #+#             */
/*   Updated: 2024/01/10 15:12:54 by mateo            ###   ########.fr       */
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

int	ft_tidyconv_p(t_conv **convp, unsigned long long arg)
{
	int	i;

	i = ft_plen(arg);
	if (!arg && ((*convp)->prec) && !((*convp)->prec_n))
		i = 0;
	if ((*convp)->prec_n < i)
		(*convp)->prec_n = i;
	if ((*convp)->width_n < (*convp)->prec_n + 2)
		(*convp)->width_n = (*convp)->prec_n + 2;
	return (i);
}

int	ft_conv_p_stub(t_conv *conv, unsigned long long arg, int i)
{
	if (write(1, "0x", 2) < 0)
		return (-1);
	while (i++ < conv->prec_n)
	{
		if (ft_putc_r('0') < 0)
			return (-1);
	}
	if (!(conv->prec && !(conv->prec_n) && !arg))
	{
		if (ft_puthex_r(arg, BASE16_SMALL) < 0)
			return (-1);
	}
	return (0);
}

int	ft_conv_p(t_conv *conv, unsigned long long arg)
{
	int					i;
	int					pad;

	i = ft_tidyconv_p(&conv, arg);
	pad = conv->width_n - conv->prec_n - 2;
	while (!(conv->left) && pad--)
	{
		if (ft_putc_r(' ') < 0)
			return (-1);
	}
	if (ft_conv_p_stub(conv, arg, i) < 0)
		return (-1);
	while (conv->left && pad--)
	{
		if (ft_putc_r(' ') < 0)
			return (-1);
	}
	return (conv->width_n);
}
