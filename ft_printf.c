/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:12:48 by mateo             #+#    #+#             */
/*   Updated: 2024/01/10 16:29:18 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

<<<<<<< HEAD
=======
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

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

/* Misc utility functions*/

>>>>>>> fd2c38754f565a448e34baec3cbc763e215f6ae9
void	ft_safefree(void *ptr)
{
	free(ptr);
	ptr = 0;
}
<<<<<<< HEAD

=======
/*Printing functions*/

int	ft_putchar_ret(int c)
{
	return (write(1, &c, 1));
}

int	ft_puthex_ret(unsigned long long c, char *base16)
{
	int	count;
	int	write_r;

	count = 0;
	if (c >= 16)
	{
		write_r = ft_puthex_ret(c / 16, base16);
		if (write_r < 0)
			return (-1);
		count += write_r;
	}
	write_r = ft_putchar_ret(base16[c % 16]);
	if (write_r < 0)
		return (-1);
	count += write_r;
	return (count);
}

int ft_putnbr_ret_neg(long long *x)
{
	if (x < 0)
	{
		*x *= -1;
		return (ft_putchar_ret('-'));
	}
	return (0);
}

int	ft_putnbr_ret(long n)
{
	char		c;
	long long	x;
	int			count;
	int			write_r;

	count = 0;
	x = n;
	write_r = ft_putnbr_ret_neg(&x);
	if (write_r < 0)
		return (-1);
	count += write_r;
	if (x >= 10)
	{
		write_r = ft_putnbr_ret(x / 10);
		if (write_r < 0)
			return (-1);
		count += write_r;
	}
	c = x % 10 + '0';
	write_r = ft_putchar_ret(c);
	if (write_r < 0)
		return (-1);
	count += write_r;
	return (count);
}

// int	ft_putnbr_ret(long n)
// {
// 	char		c;
// 	long long	x;
// 	int			count;
// 	int			write_r;

// 	count = 0;
// 	x = n;
// 	if (x < 0)
// 	{
// 		write_r = ft_putchar_ret('-');
// 		if (write_r < 0)
// 			return (-1);
// 		count += write_r;
// 		x = -x;
// 	}
// 	if (x >= 10)
// 	{
// 		write_r = ft_putnbr_ret(x / 10);
// 		if (write_r < 0)
// 			return (-1);
// 		count += write_r;
// 	}
// 	c = x % 10 + '0';
// 	write_r = ft_putchar_ret(c);
// 	if (write_r < 0)
// 		return (-1);
// 	count += write_r;
// 	return (count);
// }

int	ft_putunbr_ret(unsigned int n)
{
	char	c;
	int		count;
	int		write_r;	

	count = 0;
	if (n >= 10)
	{
		write_r = ft_putunbr_ret(n / 10);
		if (write_r < 0)
			return (-1);
	}
	c = n % 10 + '0';
	write_r = ft_putchar_ret(c);
	if (write_r < 0)
		return (-1);
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
		conv->width_num = ft_atoi(str);
	}
	while (ft_strchr(WIDTH, *str))
		str++;
	if (*str == '.')
	{
		conv->prec = 1;
		conv->prec_num = ft_atoi(++str);
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

/*Individual functions for specifiers*/
int	ft_conv_pct(t_conv *conv)
{
	int	pad;
	int	write_r;

	if (conv->width == 0)
		conv->width_num = 1;
	pad = conv->width_num;
	// ft_print_conv(conv);
	if (conv->left)
	{
		write_r = write(1, "%", 1);
		if (write_r < 0)
			return (-1);
	}
	while (--pad)
	{
		if (conv->zero)
		{
			write_r = write(1, "0", 1);
			if (write_r < 0)
				return (-1);
		}
		else
		{
			write_r = write(1, " ", 1);
			if (write_r < 0)
				return (-1);
		}			
	}
	if (conv->left == 0)
	{
		write_r = write(1, "%", 1);
		if (write_r < 0)
			return (-1);
	}
	return (conv->width_num);
}

int	ft_conv_c(t_conv *conv, int arg)
{
	int	pad;
	int	write_r;

	if (conv->width == 0)
		conv->width_num = 1;
	pad = conv->width_num;	
	if (conv->left == 1)
	{
		write_r = write(1, &arg, 1);
		if (write_r < 0)
			return (-1);
	}
	while (--pad)
	{
		write_r = write(1, " ", 1);
		if (write_r < 0)
			return (-1);
	}
	if (conv->left == 0)
	{
		write_r = write(1, &arg, 1);
		if (write_r < 0)
			return (-1);
	}
	return (conv->width_num);
}

int	ft_conv_s(t_conv *conv, char *arg)
{
	int pad;
	int	write_r;

	if (arg && ((conv->prec == 0) || (conv->prec == 1 && conv->prec_num > ft_strlen(arg))))
		conv->prec_num = ft_strlen(arg);
	if (!arg && ((conv->prec == 0) || (conv->prec == 1 && conv->prec_num > 6)))
		conv->prec_num = 6;
	if (conv->width_num < conv->prec_num)
		conv->width_num = conv->prec_num;
	pad = conv->width_num - conv->prec_num;

	if (conv->left && arg)
	{
		write_r = write(1, arg, conv->prec_num);
		if (write_r < 0)
			return (-1);
	}
	if (conv->left && !arg)
	{
		write_r = write(1, "(null)", conv->prec_num);
		if (write_r < 0)
			return (-1);
	}
	while (pad--)
	{
		write_r = write(1, " ", 1);
		if (write_r < 0)
			return (-1);
	}
	if (!(conv->left) && arg)
	{
		write_r = write(1, arg, conv->prec_num);
		if (write_r < 0)
			return (-1);
	}
	if (!(conv->left) && !arg)
	{
		write_r = write(1, "(null)", conv->prec_num);
		if (write_r < 0)
			return (-1);
	}
	return (conv->width_num);
}

int	ft_conv_p(t_conv *conv, unsigned long long arg)
{
	unsigned long long	temp;
	int					i;
	int					pad;
	int					write_r;
	
	temp = arg;
	i = 3;
	while (temp / 16 != 0)
	{
		temp = temp / 16;
		i++;
	}
	if (conv->width_num < i)
		conv->width_num = i;
	pad = conv->width_num - i;
	if (!(conv->left))
	{
		while (pad--)
		{	
			write_r = ft_putchar_ret(' ');
			if (write_r < 0)
				return (-1);
		}
	}
	if (write(1, "0x", 2) < 0)
		return (-1);
	write_r = ft_puthex_ret(arg, BASE16_SMALL);
	if (write_r < 0)
		return (-1);
	if (conv->left)
	{
		while (pad--)
		{
			write_r = ft_putchar_ret(' ');
			if (write_r < 0)
				return (-1);
		}
	}
	return (conv->width_num);
}

int ft_conv_d(t_conv *conv, int arg)
{
	int			pad;
	long long	temp;
	int			i;
	int			write_r;

	temp = arg;
	i = 1;
	while (temp / 10)
	{
		temp /= 10;
		i++;	
	}
	if (arg == 0 && (conv->prec) && !(conv->prec_num))
		i = 0;
	temp = arg;
	if (arg < 0)
	{
		temp *= -1;
		conv->space = 0;
		conv->sign = 1;
	}
	if (conv->prec_num < i)
		conv->prec_num = i;
	if ((!(conv->space) && !(conv->sign)) && (conv->width_num < conv->prec_num))
		conv->width_num = conv->prec_num;
	else if (((conv->space) || (conv->sign)) && (conv->width_num < (conv->prec_num + 1)))
		conv->width_num = conv->prec_num + 1;
	pad = conv->width_num - conv->prec_num;
	if (conv->space || conv->sign)
		pad -= 1;
	if (conv->left)
	{
		if (conv->space)
		{
			write_r = ft_putchar_ret(' ');
			if (write_r < 0)
				return (-1);
		}
		if (conv->sign && arg >= 0)
		{
			write_r = ft_putchar_ret('+');
			if (write_r < 0)
				return (-1);
		}	
		if (conv->sign && arg < 0)
		{
			write_r = ft_putchar_ret('-');
			if (write_r < 0)
				return (-1);
		}
		while (i++ < conv->prec_num)
		{
			write_r = ft_putchar_ret('0');
			if (write_r < 0)
				return (-1);
		}	
		if (!(conv->prec && !(conv->prec_num) && !arg))
		{
			write_r = ft_putnbr_ret(temp);
			if (write_r < 0)
				return (-1);
		}	
		while (pad--)
		{
			write_r = ft_putchar_ret(' ');
			if (write_r < 0)
				return (-1);
		}
	}
	else
	{
		if (conv->space)
		{
			write_r = ft_putchar_ret(' ');
			if (write_r < 0)
				return (-1);
		}
		if (!(conv->zero))
		{
			while (pad--)
			{
				write_r = ft_putchar_ret(' ');
				if (write_r < 0)
					return (-1);
			}
		}
		if (conv->sign && arg >= 0)
		{
			write_r = ft_putchar_ret('+');
			if (write_r < 0)
				return (-1);
		}
		if (conv->sign && arg < 0)
		{
			write_r = ft_putchar_ret('-');
			if (write_r < 0)
				return (-1);
		}
		if (conv->zero)
		{
			while (pad--)
			{
				write_r = ft_putchar_ret('0');
				if (write_r < 0)
					return (-1);
			}
		}
		while (i++ < conv->prec_num)
		{
			write_r = ft_putchar_ret('0');
			if (write_r < 0)
				return (-1);
		}
		if (!(conv->prec && !(conv->prec_num) && !arg))
		{
			write_r = ft_putnbr_ret(temp);
			if (write_r < 0)
				return (-1);
		}
	}
	return (conv->width_num);
}


int	ft_conv_u(t_conv *conv, unsigned int arg)
{
	int	pad;
	unsigned int	temp;
	int	i;
	int	write_r;
	
	temp = arg;
	i = 1;
	while (temp / 10)
	{
		temp /= 10;
		i++;
	}
	if (arg == 0 && (conv->prec) && !(conv->prec_num))
		i = 0;
	if (conv->prec_num < i)
		conv->prec_num = i;
	if ((!(conv->space)) && (conv->width_num < conv->prec_num))
		conv->width_num = conv->prec_num;
	else if ((conv->space) && (conv->width_num < (conv->prec_num + 1)))
		conv->width_num = conv->prec_num + 1;
	pad = conv->width_num - conv->prec_num;
	if (conv->space)
		pad -= 1;
	if (conv->left)
	{
		if (conv->space)
		{
			write_r = ft_putchar_ret(' ');
			if (write_r < 0)
				return (-1);
		}
		while (i++ < conv->prec_num)
		{
			write_r = ft_putchar_ret('0');
			if (write_r < 0)
				return (-1);
		}
		if (!(conv->prec && !(conv->prec_num) && !arg))
		{
			write_r = ft_putunbr_ret(arg);
			if (write_r < 0)
				return (-1);
		}
		while (pad--)
		{
			write_r = ft_putchar_ret(' ');
			if (write_r < 0)
				return (-1);
		}
	}
	else
	{
		if (conv->space)
		{
			 write_r = ft_putchar_ret(' ');
			 if (write_r < 0)
				return (-1);
		}
		if (!(conv->zero))
		{
			while (pad--)
			{
				write_r = ft_putchar_ret(' ');
				if (write_r < 0)
					return (-1);
			}
		}
		if (conv->zero)
		{
			while (pad--)		
			{
				write_r = ft_putchar_ret('0');
				if (write_r < 0)
					return (-1);
			}
		}
		while (i++ < conv->prec_num)
		{
			write_r = ft_putchar_ret('0');
			if (write_r < 0)
				return (-1);
		}
		if (!(conv->prec && !(conv->prec_num) && !arg))
		{
			write_r = ft_putunbr_ret(arg);
			if (write_r < 0)
				return (-1);
		}
	}
	return (conv->width_num);
}

int	ft_conv_x(t_conv *conv, unsigned int arg, char *base16)
{
	int	pad;
	unsigned int	temp;
	int	i;
	int	write_r;

	temp = arg;
	i = 1;
	while (temp / 16)
	{
		temp /= 16;
		i++;
	}
	if (arg == 0 && (conv->prec) && !(conv->prec_num))
		i = 0;
	if (arg == 0)
		conv->hash = 0;
	if (conv->prec_num < i)
		conv->prec_num = i;
	if (!conv->hash && conv->width_num < conv->prec_num)
		conv->width_num = conv->prec_num;
	if (conv->hash && conv->width_num < conv->prec_num + 2)
		conv->width_num = conv->prec_num + 2;
	pad = conv->width_num - conv->prec_num;
	if (conv->hash)
		pad -= 2;
	if (conv->left)
	{
		if (conv->hash)
		{
			write_r = ft_putchar_ret('0');
			if (write_r < 0)
				return (-1);
			write_r = ft_putchar_ret(conv->spec);
			if (write_r < 0)
				return (-1);
		}
		while (i++ < conv->prec_num)
		{
			write_r = ft_putchar_ret('0');
			if (write_r < 0)
				return (-1);
		}
		if (!(conv->prec && !(conv->prec_num) && !arg))
		{
			write_r = ft_puthex_ret(arg, base16);
			if (write_r < 0)
				return (-1);
		}
		while (pad--)
		{
			write_r = ft_putchar_ret(' ');
			if (write_r < 0)
				return (-1);
		}
	}
	else
	{
		while (!(conv->zero) && pad--)
		{
			write_r = ft_putchar_ret(' ');
			if (write_r < 0)
				return (-1);
		}
		if (conv->hash)
		{
			write_r = ft_putchar_ret('0');
			if (write_r < 0)
				return (-1);
			write_r = ft_putchar_ret(conv->spec);
			if (write_r < 0)
				return (-1);
		}
		while (conv->zero && pad--)
		{
			write_r = ft_putchar_ret('0');
			if (write_r < 0)
				return (-1);
		}
		while (i++ < conv->prec_num)
		{
			write_r = ft_putchar_ret('0');
			if (write_r < 0)
				return (-1);
		}
		if (!(conv->prec && !(conv->prec_num) && !arg))
		{
			write_r = ft_puthex_ret(arg, base16);
			if (write_r < 0)
				return (-1);
		}
	}
	return (conv->width_num);
}

/*Function to redirect to indiv functions for specifier*/
>>>>>>> fd2c38754f565a448e34baec3cbc763e215f6ae9
int	ft_conv_select(va_list va_ptr, t_conv *conv)
{
	int	count;

	count = 0;
	if (conv->spec == '%')
		count = ft_conv_c(conv, '%');
		// count = ft_conv_pct(conv);
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

int	ft_printf(const char *str, ...) // no str in assignment prototype // 
{
	va_list	va_ptr;
	t_conv	*conv;
	int		count;
	int		write_r;

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
			if (conv->spec == 0)
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
			count += write_r;
			ft_safefree(conv);
		}
		else
		{
			write_r = write(1, str, 1);
			if (write_r < 0)
				return (-1);
			count += write_r;
			str++;
		}
	}
	va_end(va_ptr);
	return (count);
}
