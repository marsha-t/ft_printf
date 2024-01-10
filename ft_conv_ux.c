/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:40:39 by mateo             #+#    #+#             */
/*   Updated: 2024/01/10 16:22:19 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ulen(unsigned int arg, int base)
{
	int	i;

	i = 1;
	while (arg / base)
	{
		arg /= base;
		i++;
	}
	return (i);
}

int	ft_tidyconv_u(t_conv **conv, unsigned int arg)
{
	int	i;

	i = ft_ulen(arg, 10);
	if (arg == 0 && ((*conv)->prec) && !((*conv)->prec_n))
		i = 0;
	if ((*conv)->prec_n < i)
		(*conv)->prec_n = i;
	if ((!((*conv)->space)) && ((*conv)->width_n < (*conv)->prec_n))
		(*conv)->width_n = (*conv)->prec_n;
	else if (((*conv)->space) && ((*conv)->width_n < ((*conv)->prec_n + 1)))
		(*conv)->width_n = (*conv)->prec_n + 1;
	return (i);
}

int	ft_conv_u(t_conv *conv, unsigned int arg)
{
	int	pad;
	int	i;

	i = ft_tidyconv_u(&conv, arg);
	pad = conv->width_n - conv->prec_n;
	if (conv->space)
		pad -= 1;
	if (conv->space && ft_putc_r(' ') < 0)
		return (-1);
	while (!(conv->left) && pad--)
	{
		if (!(conv->zero) && ft_putc_r(' ') < 0)
			return (-1);
		if (conv->zero && ft_putc_r('0') < 0)
			return (-1);
	}
	while (i++ < conv->prec_n)
	{
		if (ft_putc_r('0') < 0)
			return (-1);
	}
	if (!(conv->prec && !(conv->prec_n) && !arg) && ft_putunbr_ret(arg) < 0)
		return (-1);
	while (conv->left && pad--)
	{
		if (ft_putc_r(' ') < 0)
			return (-1);
	}
	return (conv->width_n);
}

int	ft_tidyconv_x(t_conv **conv, unsigned int arg)
{
	int	i;
	
	i = ft_ulen(arg, 16);;
	if (arg == 0 && ((*conv)->prec) && !((*conv)->prec_n))
		i = 0;
	if (arg == 0)
		(*conv)->hash = 0;
	if ((*conv)->prec_n < i)
		(*conv)->prec_n = i;
	if (!(*conv)->hash && (*conv)->width_n < (*conv)->prec_n)
		(*conv)->width_n = (*conv)->prec_n;
	if ((*conv)->hash && (*conv)->width_n < (*conv)->prec_n + 2)
		(*conv)->width_n = (*conv)->prec_n + 2;
	return (i);
}

int	ft_conv_x(t_conv *conv, unsigned int arg, char *base16)
{
	int				pad;
	int				i;

	i = ft_tidyconv_x(&conv, arg);
	pad = conv->width_n - conv->prec_n;
	if (conv->hash)
		pad -= 2;
	if (conv->left)
	{
		if (conv->hash)
		{
			if (ft_putc_r('0') < 0)
				return (-1);
			if (ft_putc_r(conv->spec) < 0)
				return (-1);
		}
		while (i++ < conv->prec_n)
			if (ft_putc_r('0') < 0)
				return (-1);
		if (!(conv->prec && !(conv->prec_n) && !arg) && ft_puthex_r(arg, base16) < 0)
			return (-1);
		while (pad--)
			if (ft_putc_r(' ') < 0)
				return (-1);
	}
	else
	{
		while (!(conv->zero) && pad--)
			if (ft_putc_r(' ') < 0)
				return (-1);
		if (conv->hash)
		{
			if (ft_putc_r('0') < 0)
				return (-1);
			if (ft_putc_r(conv->spec) < 0)
				return (-1);
		}
		while (conv->zero && pad--)
			if (ft_putc_r('0') < 0)
				return (-1);
		while (i++ < conv->prec_n)
			if (ft_putc_r('0') < 0)
				return (-1);
		if (!(conv->prec && !(conv->prec_n) && !arg) && ft_puthex_r(arg, base16) < 0)
			return (-1);
	}
	return (conv->width_n);
}
