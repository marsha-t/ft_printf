/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:12:48 by mateo             #+#    #+#             */
/*   Updated: 2024/01/05 18:08:55 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>

/* Temporary function to print conversion to make debugging easier*/
void	ft_print_conv(t_conv *conv)
{
	printf("left: %d\nsign: %d\nspace: %d\nhash: %d\nzero: %d\nwidth: %d\nwidth_num: %d\nprec: %d\nprec_num: %d\nspec: %d\n", \
	conv->left, conv->sign, conv->space, conv->hash, conv->zero, conv->width, conv->width_num, conv->prec, conv->prec_num, conv->spec);
}

/* amended libft.a functions*/
int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/* libft.a functions*/
int	ft_atoi(const char *str) 
{
	long long	r;
	long long	x;
	int			s;

	s = 1;
	r = 0;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			s = -1;
		str++;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		x = r;
		r = r * 10 + (*str - '0') * s;
		str++;
		if ((r > x) && (s < 0))
			return (0);
		if ((r < x) && (s > 0))
			return (-1);
	}
	return (r);
}

/* Misc utility functions*/
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

void	ft_safefree(void *ptr)
{
	free(ptr);
	ptr = 0;
}
/*Printing functions*/
int	ft_putchar_ret(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_puthex_ret(unsigned long long c, char *base16)
{
	int	count;

	count = 0;
	if (c >= 16)
		count +=ft_puthex_ret(c / 16, base16);
	write(1, &base16[c % 16], 1);
	count++;
	return (count);
}

int	ft_putnbr_ret(int n)
{
	char		c;
	long long	x;
	int			count;
	
	count = 0;
	x = n;
	if (x < 0)
	{
		count += ft_putchar_ret('-');
		x = -x;
	}
	if (x >= 10)
		count += ft_putnbr_ret(x / 10);
	c = x % 10 + '0';
	count += ft_putchar_ret(c);
	return (count);
}

int	ft_putunbr_ret(unsigned int n)
{
	char				c;
	int					count;
	
	count = 0;
	if (n >= 10)
		count += ft_putunbr_ret(n / 10);
	c = n % 10 + '0';
	count += ft_putchar_ret(c);
	return (count);
}

/*Conv structure creation*/

void	ft_initconv(t_conv *conv)
{
	conv->left = 0;
	conv->sign = 0;
	conv->space = 0;
	conv->hash = 0;
	conv->zero = 0;
	conv->width = 0;
	conv->width_num = 0;
	conv->prec = 0;
	conv->prec_num = 0;
	conv->spec = 0;
}

void	ft_tidyconv(t_conv *conv)
{
	if (conv->prec_num < 0)
	{
		conv->prec_num = 0;
		conv->prec = 0;
	}
	if ((conv->left) && (conv->zero))
		conv->zero = 0;
	if ((conv->prec) && (conv->zero))
		conv->zero = 0;
	if ((conv->sign) && (conv->space))
		conv->space = 0;
}

const char	*ft_extract_conv(const char *str, t_conv *conv)
{
	ft_initconv(conv);
	while (ft_charinstr(*str, FLAGS))
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
	if (ft_charinstr(*str, WIDTH))
	{
		conv->width = 1;
		conv->width_num = ft_atoi(str);
	}
	while (ft_charinstr(*str, WIDTH))
		str++;
	if (*str == '.')
	{
		conv->prec = 1;
		conv->prec_num = ft_atoi(++str);
	}
	while (ft_charinstr(*(str), PRECISION))
		str++;	
	if (ft_charinstr(*str, CONVERSIONS))
	{
		conv->spec = *str;
		str++;
	}
	else
		conv->spec = 0;
	ft_tidyconv(conv);
	return (str);
}

/*Individual functions for specifiers*/
int	ft_conv_pct(t_conv *conv)
{
	(void)conv;
	write(1, "%", 1);
	return (1);	
}

int	ft_conv_c(t_conv *conv, int arg)
{
	int	temp;
	
	if (conv->width == 0)
		conv->width_num =1; 
	temp = conv->width_num;	
	if (conv->left == 1)
		write(1, &arg, 1);
	while (--temp)
		write(1, " ", 1);
	if (conv->left == 0)
		write(1, &arg, 1);
	return (conv->width_num);
}

int	ft_conv_s(t_conv *conv, char *arg)
{
	int	count;
	
	if ((conv->prec_num == 0) || (conv->prec == 1 && conv->prec_num > ft_strlen(arg)))
		conv->prec_num = ft_strlen(arg);
	if (conv->width_num > conv->prec_num)
	{
		count = conv->width_num;
		if (conv->left)
			write(1, arg, conv->prec_num);
		conv->width_num -=conv->prec_num;
		while (conv->width_num--)
			write(1, " ", 1);
		if (conv->left == 0)
			write(1, arg, conv->prec_num);
	}
	else
	{
		count = conv->prec_num;
		write(1, arg, conv->prec_num);
	}
	return (count);
}

int	ft_conv_p(t_conv *conv, unsigned long long arg)
{
	unsigned long long	temp;
	int					i;
	int					count;

	temp = arg;
	count = 0;
	i = 3;
	while (temp / 16 != 0)
	{
		temp = temp / 16;
		i++;
	}
	if (conv->width_num < i)
		conv->width_num = i;
	conv->width_num -= i;
	if (!(conv->left))
	{
		while (conv->width_num--)
			count += ft_putchar_ret(' ');
	}
	count += ft_putchar_ret('0');
	count += ft_putchar_ret('x');
	count += ft_puthex_ret(arg, BASE16_SMALL);
	if (conv->left)
	{
		while (conv->width_num--)
			count += ft_putchar_ret(' ');
	}
	return (count);
}

int ft_conv_d(t_conv *conv, int arg)
{
	int	count;
	int	temp;
	int	i;
	
	if (arg == 0 && !(conv->prec_num))
		return (0);
	temp = arg;
	count = 0;
	i = 1;
	while (temp / 10)
	{
		temp /= 10;
		i++;
	}
	if (arg < 0)
	{
		i++;
		conv->space = 0;
		conv->sign = 0;
	}
	if ((!(conv->prec)) || ((conv->prec) && (conv->prec_num < i)))
		conv->prec_num = i;
	if ((!(conv->space) && !(conv->sign)) && (conv->width_num < conv->prec_num))
		conv->width_num = conv->prec_num;
	else if (((conv->space) || (conv->sign)) && (conv->width_num < (conv->prec_num + 1)))
		conv->width_num = conv->prec_num + 1;
	conv->width_num -= conv->prec_num;
	if (conv->space || conv->sign)
		conv->width_num -= 1;
	
	if (conv->left)
	{
		if (conv->space)
			count += ft_putchar_ret(' ');
		if (conv->sign)
			count += ft_putchar_ret('+');
		while (i++ < conv->prec_num)
			count += ft_putchar_ret('0');
		count += ft_putnbr_ret(arg);
		while (conv->width_num--)
			count += ft_putchar_ret(' ');
	}
	else
	{
		if (conv->space)
			count += ft_putchar_ret(' ');
		if (!(conv->zero))
		{
			while (conv->width_num--)
				count += ft_putchar_ret(' ');
		}
		if (conv->sign)
			count += ft_putchar_ret('+');
		if (conv->zero)
		{
			while (conv->width_num--)		
				count += ft_putchar_ret('0');
		}
		while (i++ < conv->prec_num)
			count += ft_putchar_ret('0');
		count += ft_putnbr_ret(arg);
	}
	return (count);
}

int	ft_conv_u(t_conv *conv, unsigned int arg)
{
	int	count;
	int	temp;
	int	i;
	
	if (arg == 0 && !(conv->prec_num))
		return (0);
	temp = arg;
	count = 0;
	i = 1;
	while (temp / 10)
	{
		temp /= 10;
		i++;
	}
	if ((!(conv->prec)) || ((conv->prec) && (conv->prec_num < i)))
		conv->prec_num = i;
	if ((!(conv->space)) && (conv->width_num < conv->prec_num))
		conv->width_num = conv->prec_num;
	else if ((conv->space) && (conv->width_num < (conv->prec_num + 1)))
		conv->width_num = conv->prec_num + 1;
	conv->width_num -= conv->prec_num;
	if (conv->space)
		conv->width_num -= 1;
	
	if (conv->left)
	{
		if (conv->space)
			count += ft_putchar_ret(' ');
		while (i++ < conv->prec_num)
			count += ft_putchar_ret('0');
		count += ft_putunbr_ret(arg);
		while (conv->width_num--)
			count += ft_putchar_ret(' ');
	}
	else
	{
		if (conv->space)
			count += ft_putchar_ret(' ');
		if (!(conv->zero))
		{
			while (conv->width_num--)
				count += ft_putchar_ret(' ');
		}
		if (conv->zero)
		{
			while (conv->width_num--)		
				count += ft_putchar_ret('0');
		}
		while (i++ < conv->prec_num)
			count += ft_putchar_ret('0');
		count += ft_putunbr_ret(arg);
	}
	return (count);
}


/*Function to redirect to indiv functions for specifier*/
int	ft_conv_select(va_list va_ptr, t_conv *conv)
{
	int	count;
	
	count = 0;
	if (conv->spec == '%')
		count = ft_conv_pct(conv);
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
	// else if (conv->spec == 'x')
	// 	count = ft_conv_x(conv, va_arg(va_ptr, unsigned int), BASE16_SMALL);
	// else if (conv->spec == 'X')
	// 	count = ft_conv_x(conv, va_arg(va_ptr, unsigned int), BASE16_LARGE);
	return (count);
}

int	ft_printf(const char *str, ...) // no str in assignment prototype // 
{
	int	count;
	va_list	va_ptr;
	t_conv	*conv;

	va_start(va_ptr, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			conv = (t_conv *)malloc(sizeof(t_conv));
			if (!conv)
				return (-1);
			str = ft_extract_conv(str, conv);
			// ft_print_conv(conv);
			if (conv->spec == 0)
				return (-1);
			count += ft_conv_select(va_ptr, conv);
			ft_safefree(conv);
		}
		else
		{
			write(1, str, 1);
			count++;
			str++;
		}
	}
	va_end(va_ptr);
	return (count);
}

