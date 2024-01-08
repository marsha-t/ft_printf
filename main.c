/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:29:23 by mateo             #+#    #+#             */
/*   Updated: 2024/01/04 18:29:23 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	// printf("%d", printf("\x01\x02\a\v\b\f\r\n"));
	printf("%d\n", printf(".\001."));
	printf("%d\n", ft_printf(".\001."));

	// printf("%d", ft_printf("\n"));

	// printf("\n%d\n", ft_printf("%s", (char *)0));
	// printf("\n%d\n", printf("%s", (char *)0));

	// printf("\n%d\n", ft_printf("%p", (void *)-1));
	// printf("\n%d\n", printf("%p", (void *)-1));
	// printf("\n%d\n", ft_printf("%p", (void *)1));
	// printf("\n%d\n", printf("%p", (void *)1));
	// printf("\n%d\n", ft_printf("%p", (void *)0));
	// printf("\n%d\n", printf("%p", (void *)0));

	// printf("\n%d\n", ft_printf("%p", (void *)LONG_MAX + 423856));
	// printf("\n%d\n", printf("%p", (void *)LONG_MAX + 423856));

	// printf("\n%d\n", ft_printf("%p", (void *)INT_MAX));
	// printf("\n%d\n", printf("%p", (void *)INT_MAX));

	// char	*ptr;
	// ptr = "abc";
	// printf("\n%d\n", ft_printf("%p", ptr));
	// printf("\n%d\n", printf("%p", ptr));

	// printf("\n%d\n", ft_printf("%d", INT_MAX));
	// printf("\n%d\n", printf("%d", INT_MAX));
	// printf("\n%d\n", ft_printf("%d", INT_MIN));
	// printf("\n%d\n", printf("%d", INT_MIN));

	// printf("\n%d\n", ft_printf("%i", INT_MAX));
	// printf("\n%d\n", printf("%i", INT_MAX));
	// printf("\n%d\n", ft_printf("%i", INT_MIN));
	// printf("\n%d\n", printf("%i", INT_MIN));

	// printf("\n%d\n", ft_printf("%u", UINT_MAX));
	// printf("\n%d\n", printf("%u", UINT_MAX));
	
	// printf("\n%d\n", ft_printf("%x", UINT_MAX));
	// printf("\n%d\n", printf("%x", UINT_MAX));
	
	// printf("\n%d\n", ft_printf("%X", UINT_MAX));
	// printf("\n%d\n", printf("%X", UINT_MAX));
	
}