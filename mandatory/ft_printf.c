/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 00:20:24 by mateo             #+#    #+#             */
/*   Updated: 2023/12/31 00:20:24 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0; 
	while (str[i])
		i++;
	return (i);
}

int	ft_conv_c(int c)
{
	write(1, &c, 1);
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

int	ft_conv_s(char *str)
{
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int	ft_conv_d(int n)
{
	char		c;
	long long	x;
	int			count;

	count = 0;
	x = n;
	if (x < 0)
	{
		count += ft_conv_c('-');
		x = -x;
	}
	if (x >= 10)
		count += ft_conv_d(x / 10);
	c = x % 10 + '0';
	count += ft_conv_c(c);
	return (count);
}

int	ft_conv_u(unsigned int n)
{
	char				c;
	int				count;

	count = 0;
	if (n >= 10)
		count += ft_conv_u(n / 10);
	c = n % 10 + '0';
	count += ft_conv_c(c);
	return (count);
}

int	ft_conv_x(unsigned long long c, char *base16, int recursion)
{
	int	count;

	count = 0;
	if (c < 16 && recursion == 0)
	{
		write(1, "0", 1);
		count++;
	}
	if (c >= 16)
		count +=ft_conv_x(c / 16, base16, 1);
	write(1, &base16[c % 16], 1);
	count++;
	return (count);
}

int	ft_conv_p(unsigned long long addr)
{
	unsigned long long	temp;
	int					count;
	int					i;

	temp = addr;
	count = 0;
	i = 1;
	while (temp / 16 != 0)
	{
		temp = temp / 16;
		i++;
	}
	while (i++ < 16)
		count += ft_conv_c('0');
	count += ft_conv_x(addr, BASE16_SMALL, 0);
	return (count);
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
		count = ft_conv_x(va_arg(va_ptr, unsigned int), BASE16_SMALL, 0);
	else if (*str == 'X')
		count = ft_conv_x(va_arg(va_ptr, unsigned int), BASE16_LARGE, 0);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
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
				count += ft_printconv(str, va_ptr);
				str++;
			}
			else
				return (-1);
		}
		else
		{
			count += ft_conv_c(*str);
			str++;
		}
	}
	va_end(va_ptr);
	return (count);
}

// #include <stdio.h>
// #include <limits.h>

// int	main(void)
// {
	

// 	// char	*ptr;
// 	// ptr = "abc";
// 	// printf("\n%d\n", ft_printf("%p", ptr));
// 	// printf("\n%d\n", printf("%p", ptr));

// 	// printf("\n%d\n", ft_printf("%d", INT_MAX));
// 	// printf("\n%d\n", printf("%d", INT_MAX));
// 	// printf("\n%d\n", ft_printf("%d", INT_MIN));
// 	// printf("\n%d\n", printf("%d", INT_MIN));

// 	// printf("\n%d\n", ft_printf("%i", INT_MAX));
// 	// printf("\n%d\n", printf("%i", INT_MAX));
// 	// printf("\n%d\n", ft_printf("%i", INT_MIN));
// 	// printf("\n%d\n", printf("%i", INT_MIN));

// 	// printf("\n%d\n", ft_printf("%u", UINT_MAX));
// 	// printf("\n%d\n", printf("%u", UINT_MAX));
	
// 	// printf("\n%d\n", ft_printf("%x", UINT_MAX));
// 	// printf("\n%d\n", printf("%x", UINT_MAX));
	
// 	// printf("\n%d\n", ft_printf("%X", UINT_MAX));
// 	// printf("\n%d\n", printf("%X", UINT_MAX));
	
// }