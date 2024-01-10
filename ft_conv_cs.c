/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_cs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:56:20 by mateo             #+#    #+#             */
/*   Updated: 2024/01/10 17:24:05 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_c(t_conv *conv, int arg)
{
	if (!(conv->width))
		conv->width_n = 1;
	conv->pad = conv->width_n;
	if (conv->left && write(1, &arg, 1) < 0)
		return (-1);
	while (--(conv->pad))
		if (write(1, " ", 1) < 0)
			return (-1);
	if (!(conv->left) && write(1, &arg, 1) < 0)
		return (-1);
	return (conv->width_n);
}

int	ft_conv_s(t_conv *conv, char *arg)
{
	if (!arg)
		arg = NULLSTR;
	if (!(conv->prec) || (conv->prec && conv->prec_n > ft_strlen(arg)))
		conv->prec_n = ft_strlen(arg);
	if (conv->width_n < conv->prec_n)
		conv->width_n = conv->prec_n;
	conv->pad = conv->width_n - conv->prec_n;
	if (conv->left && write(1, arg, conv->prec_n) < 0)
		return (-1);
	while ((conv->pad)--)
		if (write(1, " ", 1) < 0)
			return (-1);
	if (!(conv->left) && write(1, arg, conv->prec_n) < 0)
		return (-1);
	return (conv->width_n);
}
