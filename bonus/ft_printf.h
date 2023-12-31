/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:53:27 by mateo             #+#    #+#             */
/*   Updated: 2023/12/18 15:53:27 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define CONVERSIONS "cspdiuxX%"
# define FLAGS "-+ #0"
# define WIDTH "0123456789"
# define PRECISION "-0123456789"

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

#endif