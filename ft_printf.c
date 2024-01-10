/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:12:48 by mateo             #+#    #+#             */
/*   Updated: 2024/01/10 18:03:07 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_safefree(void *ptr)
{
	free(ptr);
	ptr = 0;
}

int	ft_conv_select(va_list va_ptr, t_conv *conv)
{
	int	count;

	count = 0;
	if (conv->spec == '%')
		count = ft_conv_c(conv, '%');
	else if (conv->spec == 'c')
		count = ft_conv_c(conv, va_arg(va_ptr, int));
	else if (conv->spec == 's')
		count = ft_conv_s(conv, va_arg(va_ptr, char *));
	else if (conv->spec == 'p')
		count = ft_conv_p(conv, va_arg(va_ptr, unsigned long long));
	else if (conv->spec == 'd' || conv->spec == 'i')
		count = ft_conv_d(conv, va_arg(va_ptr, int));
	else if (conv->spec == 'u')
		count = ft_conv_u(conv, va_arg(va_ptr, unsigned int));
	else if (conv->spec == 'x')
		count = ft_conv_x(conv, va_arg(va_ptr, unsigned int), BASE16_SMALL);
	else if (conv->spec == 'X')
		count = ft_conv_x(conv, va_arg(va_ptr, unsigned int), BASE16_LARGE);
	return (count);
}

int	ft_printf_conv(const char **format_p, va_list va_ptr, int *count)
{
	t_conv	*conv;
	int		write_r;

	(*format_p)++;
	conv = malloc(sizeof(t_conv));
	if (!conv)
		return (-1);
	(*format_p) = ft_extract_conv((*format_p), conv);
	if (!(conv->spec))
	{
		ft_safefree(conv);
		return (-1);
	}
	write_r = ft_conv_select(va_ptr, conv);
	if (write_r < 0)
	{
		ft_safefree(conv);
		return (-1);
	}
	*count += write_r;
	ft_safefree(conv);
	return (write_r);
}

int	ft_printf(const char *format, ...)
{
	va_list	va_ptr;
	int		count;
	int		write_r;

	va_start(va_ptr, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			write_r = ft_printf_conv(&format, va_ptr, &count);
			if (write_r < 0)
				return (-1);
		}
		else
		{
			write_r = write(1, format, 1);
			if (write_r < 0)
				return (-1);
			count += write_r;
			format++;
		}
	}
	va_end(va_ptr);
	return (count);
}
