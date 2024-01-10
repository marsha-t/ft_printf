/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_pct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:41:57 by mateo             #+#    #+#             */
/*   Updated: 2024/01/10 16:28:13 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_pct(t_conv *conv)
{
	int	pad;

	if (!(conv->width))
		conv->width_n = 1;
	pad = conv->width_n;
	if (conv->left && write(1, "%", 1) < 0)
		return (-1);
	while (--pad)
	{
		if (conv->zero && write(1, "0", 1) < 0)
			return (-1);
		if (!(conv->zero) && write(1, " ", 1) < 0)
			return (-1);
	}
	if (!(conv->left) && write(1, "%", 1) < 0)
		return (-1);
	return (conv->width_n);
}

