/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_conv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:39:19 by mateo             #+#    #+#             */
/*   Updated: 2024/01/10 12:12:03 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initconv(t_conv *conv)
{
	conv->left = 0;
	conv->sign = 0;
	conv->space = 0;
	conv->hash = 0;
	conv->zero = 0;
	conv->width = 0;
	conv->width_n = 0;
	conv->prec = 0;
	conv->prec_n = 0;
	conv->spec = 0;
}

void	ft_tidyconv(t_conv *conv)
{
	if (conv->prec_n < 0)
	{
		conv->prec_n = 0;
		conv->prec = 0;
	}
	if ((conv->left) && (conv->zero))
		conv->zero = 0;
	if ((conv->prec) && (conv->zero) && (conv->spec != '%'))
		conv->zero = 0;
	if ((conv->sign) && (conv->space))
		conv->space = 0;
}

const char	*ft_extract_conv(const char *str, t_conv *conv)
{
	ft_initconv(conv);
	while (ft_strchr(FLAGS, *str))
	{
		if (*str == '-')
			conv->left = 1;
		if (*str == '+')
			conv->sign = 1;
		if (*str == ' ')
			conv->space = 1;
		if (*str == '#')
			conv->hash = 1;
		if (*str == '0')
			conv->zero = 1;
		str++;
	}
	if (ft_strchr(WIDTH, *str))
	{
		conv->width = 1;
		conv->width_n = ft_atoi(str);
	}
	while (ft_strchr(WIDTH, *str))
		str++;
	if (*str == '.')
	{
		conv->prec = 1;
		conv->prec_n = ft_atoi(++str);
	}
	while (ft_strchr(PRECISION, *str))
		str++;
	if (ft_strchr(CONVERSIONS, *str))
	{
		conv->spec = *str;
		str++;
	}
	else
		conv->spec = 0;
	ft_tidyconv(conv);
	return (str);
}
