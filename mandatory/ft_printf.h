/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:30:05 by mateo             #+#    #+#             */
/*   Updated: 2024/01/08 11:30:05 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define CONVERSIONS "cspdiuxX%"
# define FLAGS "-+ #0"
# define WIDTH "0123456789"
# define PRECISION "-0123456789"
# define BASE16_SMALL "0123456789abcdef"
# define BASE16_LARGE "0123456789ABCDEF"

int	ft_strlen(char *str); // replaced by libft version?
int	ft_conv_c(int c);
int	ft_charinstr(char c, char *str);
int	ft_conv_s(char *str);
int	ft_conv_d(int n);
int	ft_conv_u(unsigned int n);
int	ft_conv_x(unsigned long long c, char *base16);
int	ft_conv_p(unsigned long long addr);
int	ft_conv_select(const char *str, va_list va_ptr);
int	ft_printconv(const char **str, va_list va_ptr);
int	ft_printf(const char *str, ...);

#endif