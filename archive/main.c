/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:12:48 by mateo             #+#    #+#             */
/*   Updated: 2023/12/30 23:34:33 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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

int	ft_len_conv(const char *str, int i)
{
	int	len_conv;

	len_conv = 0;	
	while (ft_charinstr(str[i], FLAGS))
	{
		len_conv++;
		i++;
	}
	while (ft_charinstr(str[i], WIDTH))
	{
		len_conv++;
		i++;
	}
	while (ft_charinstr(str[i], PRECISION))
	{
		len_conv++;
		i++;
	}
	if (ft_charinstr(str[i], CONVERSIONS))
		len_conv++;
	else
		return (-1);
	return (len_conv);
}

char	*ft_putword(const char *str, int i, char *word, int len)
{
	int	j;
	
	word = (char *)malloc(sizeof(char) * (len + 1)); 
	j = 0;
	while (len--)
	{
		word[j] = str[i + 1];
		j++;
		i++; 	
	}
	word[j] = '\0';
	return (word);
}

int ft_strlen(char *str)
{
	int	i;
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi_width(char *str) // does not cater for negative int
{
	long long	r;

	r = 0;
	while (ft_charinstr(*str, FLAGS))
		str++;
	while ((*str >= '0') && (*str <= '9'))
	{
		r = r * 10 + (*str - '0');
		str++;
	}
	return (r);
}

int	ft_atoi_precision(char *str) // does not cater for negative int
{
	long long	r;

	r = 0;
	while (ft_charinstr(*str, FLAGS))
		str++;
	while ((*str >= '0') && (*str <= '9'))
		str++;
	if (*str == '.')
	{
		str++;
		while ((*str >= '0') && (*str <= '9'))
		{
			r = r * 10 + (*str - '0');
		str++;
		}
	}
	return (r);
}

int ft_conv_c(char *word, int arg)
{
	int	left;
	int	width;
	int	count;
	
	left = 0;
	while (ft_charinstr(*word, FLAGS))
	{
		if (*word == '-')
			left = 1;
		word++;
	}
	width = ft_atoi_width(word);
	if (width < 1)
		width = 1;
	count = width;
	if (left == 1)
	{
		write(1, &arg, 1);
		while (--width)
			write(1, " ", 1);
	}
	else
	{
		while (--width)
			write(1, " ", 1);
		write(1, &arg, 1);
	}
	return (count);
}

int ft_conv_s(char *word, char *arg)
{
	int	left;
	int	width;
	int	precision;
	int	count;
	left = 0;
	width = ft_atoi_width(word);
	while (ft_charinstr(*word, FLAGS) || ft_charinstr(*word, "0123456789"))
	{
		if (*word == '-')
			left = 1;
		word++;
	}
	if (*word == '.')
		precision = ft_atoi_precision(word);
	else
		precision = ft_strlen(arg);
	if (precision > ft_strlen(arg))
		precision = ft_strlen(arg);
	if (width > precision)
	{
		count = width;
		if (left == 1)
		{
			write(1, arg, precision);
			width -= precision;
			while (width--)
				write(1, " ", 1);
		}
		else
		{
			width -= precision;
			while (width--)
				write(1, " ", 1);
			write(1, arg, precision);
		}
	}
	else
	{
		count = precision;
		write(1, arg, precision);
	}
	return (count);
}

int	ft_print_conv(va_list va_ptr, char *word, int len)
{
	int	count;
	
	if (word[len - 1] == 'c')
		count = ft_conv_c(word, va_arg(va_ptr, int));
	else if (word[len - 1] == 's')
		count = ft_conv_s(word, va_arg(va_ptr, char *));
	else if (word[len - 1] == 'p')
	{
		// count = ft_conv_p(word, va_arg(va_ptr, void *));
	}
	else if (word[len - 1] == 'd' || word[len - 1] == 'i')
	{	// count = ft_conv_d(word, va_arg(va_ptr, int));
	}
	else if (word[len - 1] == 'u')
	{	// count = ft_conv_u(word, va_arg(va_ptr, unsigned int));
	}
	else if (word[len - 1] == 'x')
	{	// count = ft_conv_x(word, va_arg(va_ptr, unsigned int));
	}
	else if (word[len - 1] == 'X')
	{	// count = ft_conv_X(word, va_arg(va_ptr, unsigned int));
	}
	return (count);
}

void	ft_safefree(void *ptr)
{
	free(ptr);
	ptr = 0;
}

int	ft_printf(const char *str, ...) // no str in assignment prototype // 
{
	int	i;
	int	count;
	char	*word;
	int	len;
	va_list	va_ptr;

	va_start(va_ptr, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
			{
				write(1, "%", 1);
				count += 1;
				i += 2;
			}
			else
			{
				len = ft_len_conv(str, i + 1); // length excluding # but including flags and specifier // check order of flags, width, precision, specifier
				if (len < 0)
					return (-1);
				word = ft_putword(str, i, word, len); 
				if (!word)
					return (-1);			
				// printf("word: %s\n", word);
				count += ft_print_conv(va_ptr, word, len);
				ft_safefree(word);
				i += len + 1; 
			}
		}
		else
		{
			write(1, &str[i], 1);
			count += 1;
			i++;
		}
	}
	return (count);
}

#include <stdio.h>

void	ft_putnbr(int n)
{
	char		c;
	long long	x;

	x = n;
	if (x < 0)
	{
		write(1, "-", 1);
		x = -x;
	}
	if (x >= 10)
		ft_putnbr(x / 10);
	c = x % 10 + '0';
	write(1, &c, 1);
}

int	main(void)
{
	int	r;
	
	// // Testing %c
	r = ft_printf("a %c.", 'm');
	write(1, "\nreturn value: ", 15);
	ft_putnbr(r);
	write(1, "\n", 1);
	r = ft_printf("a %0c.", 'm');
	write(1, "\nreturn value: ", 15);
	ft_putnbr(r);
	write(1, "\n", 1);
	r = ft_printf("a %05c.", 'm');
	write(1, "\nreturn value: ", 15);
	ft_putnbr(r);
	write(1, "\n", 1);
	r = ft_printf("a %-05c.", 'm');
	write(1, "\nreturn value: ", 15);
	ft_putnbr(r);
	write(1, "\n", 1);
	
	// Testing %s
	r = ft_printf("a %s.", "abc");
	write(1, "\nreturn value: ", 15);
	ft_putnbr(r);
	write(1, "\n", 1);
	r = ft_printf("a %.2s.", "abc");
	write(1, "\nreturn value: ", 15);
	ft_putnbr(r);
	write(1, "\n", 1);
	r = ft_printf("a %3.2s.", "abc");
	write(1, "\nreturn value: ", 15);
	ft_putnbr(r);
	write(1, "\n", 1);
	r = ft_printf("a %-3.2s.", "abc");
	write(1, "\nreturn value: ", 15);
	ft_putnbr(r);
	write(1, "\n", 1);
	r = ft_printf("a %3.3s.", "abc");
	write(1, "\nreturn value: ", 15);
	ft_putnbr(r);
	write(1, "\n", 1);
	r = ft_printf("a %2.3s.", "abc");
	write(1, "\nreturn value: ", 15);
	ft_putnbr(r);
	write(1, "\n", 1);
	r = ft_printf("a %.5s.", "abc");
	write(1, "\nreturn value: ", 15);
	ft_putnbr(r);
	write(1, "\n", 1);
	
	// printf("\nreturn value: %d\n", ft_printf("ab %  sabc", "123"));
	// printf("\nreturn value: %d\n", ft_printf("ab %  zsabc", "123"));
	// printf("\nreturn value: %d\n", ft_printf("ab%", "123"));
}