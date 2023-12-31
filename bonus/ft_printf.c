/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:12:48 by mateo             #+#    #+#             */
/*   Updated: 2023/12/31 20:05:38 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_print_conv(t_conv *conv)
{
	printf("left: %d\nsign: %d\nspace: %d\nhash: %d\nzero: %d\nwidth: %d\nwidth_num: %d\nprec: %d\nprec_num: %d\nspec: %d\n", \
	conv->left, conv->sign, conv->space, conv->hash, conv->zero, conv->width, conv->width_num, conv->prec, conv->prec_num, conv->spec);
}

int	ft_atoi(const char *str) //libft.a
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

size_t	ft_strlen(const char *s) // libft.a
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
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

void	ft_safefree(void *ptr)
{
	free(ptr);
	ptr = 0;
}


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
	if (*str == '.' && ft_charinstr(*(str + 1), PRECISION))
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
	return (str);
}

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
		if (conv->left == 1)
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

void	ft_conv_p_addr(unsigned long long arg)
{
	unsigned long long	temp;
	int					i;

	temp = addr;
	i = 1;
	while (temp / 16 != 0)
	{
		temp = temp / 16;
		i++;
	}
	while (i++ < 16)
		ft_conv_c('0');
	ft_conv_x(addr, BASE16_SMALL, 0);
	return (16);	
}

int	ft_conv_p(t_conv *conv, unsigned long long arg)
{
	int	count;
	
	count += ft_conv_p_addr(arg);
	return (count);
}

int	ft_conv_select(va_list va_ptr, t_conv *conv)
{
	int	count;
	
	if (conv->spec == '%')
		count = ft_conv_pct(conv);
	else if (conv->spec == 'c')
		count = ft_conv_c(conv, va_arg(va_ptr, int));
	else if (conv->spec == 's')
		count = ft_conv_s(conv, va_arg(va_ptr, char *));
	else if (conv->spec == 'p')
		count = ft_conv_p(conv, va_arg(va_ptr, unsigned long long));
	// else if (conv->spec == 'd' || conv->spec == 'i')
	// 	count = ft_conv_d(conv, va_arg(va_ptr, int));
	// else if (conv->spec == 'u')
	// 	count = ft_conv_u(conv, va_arg(va_ptr, unsigned int));
	// else if (conv->spec == 'x')
	// 	count = ft_conv_x(conv, va_arg(va_ptr, unsigned int), BASE16_SMALL, 0);
	// else if (conv->spec == 'X')
	// 	count = ft_conv_x(conv, va_arg(va_ptr, unsigned int), BASE16_LARGE, 0);
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

#include <stdio.h>
int	main(void)
{
	// printf("\n%d\n", ft_printf("%.%"));
	// printf("\n%d\n", ft_printf("%#%"));
	
	// printf("\n%d\n", ft_printf("%2.2c", 'a'));
	
	// printf("\n%d\n", ft_printf("%s", "abc"));
	// printf("\n%d\n", ft_printf("%.2s", "abc"));
	// printf("\n%d\n", ft_printf("%3.2s", "abc"));
	// printf("\n%d\n", ft_printf("%-3.2s.", "abc"));
	// printf("\n%d\n", ft_printf("%2.3s", "abc"));
	printf("\n%d\n", ft_printf("%.5s", "abc"));
	
	
	
}