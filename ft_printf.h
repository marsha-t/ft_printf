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

#ifndef FT_PRINTF_BONUS_H

# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define CONVERSIONS "cspdiuxX%"
# define FLAGS "-+ #0"
# define WIDTH "0123456789"
# define PRECISION "-0123456789"
# define BASE16_SMALL "0123456789abcdef"
# define BASE16_LARGE "0123456789ABCDEF"

typedef struct s_conv
{
	int		left;
	int		sign;
	int		space;
	int		hash;
	int		zero;
	int		width;
	int		width_num;
	int		prec;
	int		prec_num;
	char	spec;
}				t_conv;

int	ft_printf(const char *str, ...);

#endif