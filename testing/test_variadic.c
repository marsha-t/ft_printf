/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_variadic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:24:23 by mateo             #+#    #+#             */
/*   Updated: 2023/12/27 12:24:23 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	ft_select_ft(int c, unsigned long long argval)
{
	if (c == 'd')
		ft_putnbr((int)argval);
	else if (c == 'p')
		ft_display_addr(argval);
}

void	ft_display(int c, ...)
{
	unsigned long long argval;
	va_list	ptr;
	
	va_start(ptr, c);

	if (c == 's')
	{
		ft_putstr(va_arg(ptr, char *));
	}
	else if (c == 'd' || c == 'p')
	{
		argval = va_arg(ptr, unsigned long long);
		ft_select_ft(c, argval);
		// ft_putnbr(va_arg(ptr, int));
	}
	// else if (c == 'p')
	// {
	// 	argval = va_arg(ptr, unsigned long long);
	// 	// ft_display_addr((unsigned long long)va_arg(ptr, char *));
	// }
	va_end(ptr);
}

int	main(void)
{
	ft_display('d', 1);
	write(1, "\n", 1);
	ft_display('s', "abc");
	write(1, "\n", 1);
	ft_display('p', "abc");
	write(1, "\n", 1);
}