/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:29:57 by mateo             #+#    #+#             */
/*   Updated: 2024/01/08 11:29:57 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define CONVERSIONS "cspdiuxX%"
# define FLAGS "-+ #0"
# define WIDTH "0123456789"
# define PRECISION "-0123456789"
# define BASE16_SMALL "0123456789abcdef"
# define BASE16_LARGE "0123456789ABCDEF"
# define NULLSTR "(null)"

typedef struct s_conv
{
	int		left;
	int		sign;
	int		space;
	int		hash;
	int		zero;
	int		width;
	int		width_n;
	int		prec;
	int		prec_n;
	int		i;
	int		pad;
	char	spec;
}				t_conv;

int			ft_strlen(const char *s);
int			ft_atoi(const char *str);
char		*ft_strchr(const char *s, int c);

int			ft_putc_r(int c);
int			ft_puthex_r(unsigned long long c, char *base16);
int			ft_putnbr_ret(long n);
int			ft_putunbr_ret(unsigned int n);

void		ft_initconv(t_conv *conv);
void		ft_tidyconv(t_conv *conv);
const char	*ft_extract_conv(const char *str, t_conv *conv);

int			ft_conv_c(t_conv *conv, int arg);
int			ft_conv_s(t_conv *conv, char *arg);

int			ft_dlen(int arg);
long long	ft_abs(long arg);
void		ft_tidyconv_d(t_conv*conv, int arg);
int			ft_conv_d(t_conv *conv, int arg);

int			ft_plen(unsigned long long arg);
void		ft_tidyconv_p(t_conv *conv, unsigned long long arg);
int			ft_conv_p(t_conv *conv, unsigned long long arg);

int			ft_ulen(unsigned int arg, int base);
void		ft_tidyconv_u(t_conv *conv, unsigned int arg);
int			ft_conv_u(t_conv *conv, unsigned int arg);

void		ft_tidyconv_x(t_conv *conv, unsigned int arg);
int			ft_conv_x(t_conv *conv, unsigned int arg, char *base16);

void		ft_safefree(void *ptr);
int			ft_conv_select(va_list va_ptr, t_conv *conv);
int			ft_printf(const char *str, ...);

#endif