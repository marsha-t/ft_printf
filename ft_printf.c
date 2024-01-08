/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:25:11 by mateo             #+#    #+#             */
/*   Updated: 2024/01/04 18:25:11 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_c(int c)
{
	ssize_t	write_ret;

	write_ret = write(1, &c, 1);
	if (write_ret == -1)
		return (-1);
	return (1);
}

int	ft_charinstr(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_printconv(const char *str, va_list va_ptr)
{
	int	count;

	count = 0;
	if (*str == '%')
		count = ft_conv_c('%');
	else if (*str == 'c')
		count = ft_conv_c(va_arg(va_ptr, int));
	else if (*str == 's')
		count = ft_conv_s(va_arg(va_ptr, char *));
	else if (*str == 'p')
		count = ft_conv_p(va_arg(va_ptr, unsigned long long));
	else if (*str == 'd' || *str == 'i')
		count = ft_conv_d(va_arg(va_ptr, int));
	else if (*str == 'u')
		count = ft_conv_u(va_arg(va_ptr, unsigned int));
	else if (*str == 'x')
		count = ft_conv_x(va_arg(va_ptr, unsigned int), BASE16_SMALL);
	else if (*str == 'X')
		count = ft_conv_x(va_arg(va_ptr, unsigned int), BASE16_LARGE);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		temp;
	va_list	va_ptr;

	count = 0;
	va_start(va_ptr, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (ft_charinstr(*str, CONVERSIONS))
			{
				temp = ft_printconv(str, va_ptr);
				if (temp < 0)
					return (-1);
				count += temp;
				str++;
			}
			else
				return (-1);
		}
		else
		{
			temp = ft_conv_c(*str);
			if (temp < 0)
				return (-1);
			count += temp;
			str++;
		}
	}
	va_end(va_ptr);
	return (count);
}
