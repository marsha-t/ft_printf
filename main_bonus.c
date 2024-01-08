/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:04:47 by mateo             #+#    #+#             */
/*   Updated: 2024/01/05 18:04:47 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char *ptr = "abc";
	
	// printf("%d\n", printf(".%#x.\n", 0));
	printf("%d\n", ft_printf(".%#x.\n", 0));

	// printf("%d\n", printf("%04d\n", -14)); 
	// printf("%d\n", ft_printf("%04d\n", -14)); 

	// printf("%d\n", printf(".%-3u.\n", 1)); /////
	// printf("%d\n", ft_printf(".%-3u.\n", 1)); /////
	
	// printf("%d\n", ft_printf(".%-15u.\n", 9223372036854775807LL)); /////
	// printf("%d\n", printf(".%-15u.\n", 9223372036854775807LL)); /////

	
	// printf("%d\n", ft_printf(".%-4u.\n",-14)); /////
	// printf("%d\n", printf(".%-4u.\n", -14)); /////

	// printf("%d\n", printf("%-13d\n", UINT_MAX)); /////
	// printf("%d\n", ft_printf("%-13d\n", UINT_MAX)); /////
	// printf("\n%d\n", ft_printf("%.%"));
	// printf("\n%d\n", ft_printf("%#%"));
	
	// printf("\n%d\n", ft_printf("%2.2c", 'a'));
	
	// printf("\n%d\n", ft_printf("%s", "abc"));
	// printf("\n%d\n", ft_printf("%.2s", "abc"));
	// printf("\n%d\n", ft_printf("%3.2s", "abc"));
	// printf("\n%d\n", ft_printf("%-3.2s.", "abc"));
	// printf("\n%d\n", ft_printf("%2.3s", "abc"));
	// printf("\n%d\n", ft_printf("%.5s", "abc"));
	
	// char *ptr = "abc";
	// printf("\n%d\n", ft_printf("%p", ptr));
	// printf("\n%d\n", printf("%p", ptr));
	// printf("\n%d\n", ft_printf("%.12p", ptr));
	// printf("\n%d\n", printf("%.12p", ptr));
	// printf("\n%d\n", ft_printf("%.13p", ptr));
	// printf("\n%d\n", printf("%.13p", ptr));
	// printf("\n%d\n", ft_printf("%.16p", ptr));
	// printf("\n%d\n", printf("%.16p", ptr));
	// printf("\n%d\n", ft_printf("%.18p", ptr));
	// printf("\n%d\n", printf("%.18p", ptr));
	// printf("\n%d\n", ft_printf("%20.18p", ptr));
	// printf("\n%d\n", printf("%20.18p", ptr));
	// printf("\n%d\n", ft_printf("%-20.18p", ptr));
	// printf("\n%d\n", printf("%-20.18p", ptr));
	// printf("\n%d\n", ft_printf("%#16.12p", ptr));
	// printf("\n%d\n", printf("%#16.12p", ptr));
	// printf("\n%d\n", ft_printf("%#16.15p", ptr));
	// printf("\n%d\n", printf("%#16.15p", ptr));
	// printf("\n%d\n", ft_printf("%#16p", ptr));
	// printf("\n%d\n", printf("%#16p", ptr));
	// printf("\n%d\n", ft_printf("%020p", ptr));
	// printf("\n%d\n", printf("%020p", ptr));
	// printf("\n%d\n", ft_printf("%-020p.", ptr));
	// printf("\n%d\n", printf("%-020p.", ptr));
	// printf("\n%d\n", ft_printf("%-20p.", ptr));
	// printf("\n%d\n", printf("%-20p.", ptr));

	// printf("\n%d\n", ft_printf("%03d", 42));
	// printf("\n%d\n", printf("%03d", 42));
	// printf("\n%d\n", ft_printf("%-03d", 42));
	// printf("\n%d\n", printf("%-03d", 42));
	// printf("\n%d\n", ft_printf("% d", 42));
	// printf("\n%d\n", printf("% d", 42));
	// printf("\n%d\n", ft_printf("% 3d", 42));
	// printf("\n%d\n", printf("% 3d", 42));
	// printf("\n%d\n", ft_printf("%d", -42));
	// printf("\n%d\n", printf("%d", -42));
	// printf("\n%d\n", ft_printf("% d", -42));
	// printf("\n%d\n", printf("% d", -42));
	// printf("\n%d\n", ft_printf("% -3d", 42));
	// printf("\n%d\n", printf("% -3d", 42));
	// printf("\n%d\n", ft_printf("%- 4d", 42));
	// printf("\n%d\n", printf("%- 4d", 42));
	// printf("\n%d\n", ft_printf("% 4d", 42));
	// printf("\n%d\n", printf("% 4d", 42));
	// printf("\n%d\n", ft_printf("%0 4d", 42));
	// printf("\n%d\n", printf("%0 4d", 42));
	// printf("\n%d\n", ft_printf("% 4.3d", 42));
	// printf("\n%d\n", printf("% 4.3d", 42));
	// printf("\n%d\n", ft_printf("%04d", 42));
	// printf("\n%d\n", printf("%04d", 42));
	// printf("\n%d\n", ft_printf("%-04d", 42));
	// printf("\n%d\n", printf("%-04d", 42));
	// printf("\n%d\n", ft_printf("%.0d", 0));
	// printf("\n%d\n", printf("%.0d", 0));
	// printf("\n%d\n", ft_printf("%+0d", 42));
	// printf("\n%d\n", printf("%+0d", 42));
	// printf("\n%d\n", ft_printf("%+ d", 42));
	// printf("\n%d\n", printf("%+ d", 42));
	// printf("\n%d\n", ft_printf("%+05d", 42));
	// printf("\n%d\n", printf("%+05d", 42));
	// printf("\n%d\n", ft_printf("%+ 5d", 42));
	// printf("\n%d\n", printf("%+ 5d", 42));
	// printf("\n%d\n", ft_printf("%-+05d", 42));
	// printf("\n%d\n", printf("%-+05d", 42));
	// printf("\n%d\n", ft_printf("%-+ 5d", 42));
	// printf("\n%d\n", printf("%-+ 5d", 42));
	// printf("\n%d\n", ft_printf("%-4d.", 42));
	// printf("\n%d\n", printf("%-4d.", 42));
	// printf("\n%d\n", ft_printf("%4d.", 42));
	// printf("\n%d\n", printf("%4d.", 42));
	// printf("\n%d\n", ft_printf("%5.4d.", 42));
	// printf("\n%d\n", printf("%5.4d.", 42));
	// printf("\n%d\n", ft_printf("%05.4d.", 42));
	// printf("\n%d\n", printf("%05.4d.", 42));
	// printf("\n%d\n", ft_printf("%05.7d.", 42));
	// printf("\n%d\n", printf("%05.7d.", 42));
	// printf("\n%d\n", ft_printf("%d.", INT_MIN));
	// printf("\n%d\n", printf("%0d.", INT_MIN));
	// printf("\n%d\n", ft_printf("%d.", INT_MAX));
	// printf("\n%d\n", printf("%0d.", INT_MAX));
	
	// printf("\n%d\n", ft_printf("%u.", UINT_MAX));
	// printf("\n%d\n", printf("%u.", UINT_MAX));
	// printf("\n%d\n", ft_printf("%03u", 42));
	// printf("\n%d\n", printf("%03u", 42));
	// printf("\n%d\n", ft_printf("%-03u", 42));
	// printf("\n%d\n", printf("%-03u", 42));
	// printf("\n%d\n", ft_printf("% u", 42));
	// printf("\n%d\n", printf("% u", 42));
	// printf("\n%d\n", ft_printf("% 3u", 42));
	// printf("\n%d\n", printf("% 3u", 42));
	// printf("\n%d\n", ft_printf("%u", -42));
	// printf("\n%d\n", printf("%u", -42));
	// printf("\n%d\n", ft_printf("% u", -42));
	// printf("\n%d\n", printf("% u", -42));
	// printf("\n%d\n", ft_printf("% -3u", 42));
	// printf("\n%d\n", printf("% -3u", 42));
	// printf("\n%d\n", ft_printf("%- 4u", 42));
	// printf("\n%d\n", printf("%- 4u", 42));
	// printf("\n%d\n", ft_printf("% 4u", 42));
	// printf("\n%d\n", printf("% 4u", 42));
	// printf("\n%d\n", ft_printf("%0 4u", 42));
	// printf("\n%d\n", printf("%0 4u", 42));
	// printf("\n%d\n", ft_printf("% 4.3u", 42));
	// printf("\n%d\n", printf("% 4.3u", 42));
	// printf("\n%d\n", ft_printf("%04u", 42));
	// printf("\n%d\n", printf("%04u", 42));
	// printf("\n%d\n", ft_printf("%-04u", 42));
	// printf("\n%d\n", printf("%-04u", 42));
	// printf("\n%d\n", ft_printf("%.0u", 0));
	// printf("\n%d\n", printf("%.0u", 0));
	// printf("\n%d\n", ft_printf("%+0u", 42));
	// printf("\n%d\n", printf("%+0u", 42));
	// printf("\n%d\n", ft_printf("%+ u", 42)); // not the same becuase + doesn't work with %u
	// printf("\n%d\n", printf("%+ u", 42));
	// printf("\n%d\n", ft_printf("%+05u", 42));
	// printf("\n%d\n", printf("%+05u", 42));
	// printf("\n%d\n", ft_printf("%+ 5u", 42));
	// printf("\n%d\n", printf("%+ 5u", 42));
	// printf("\n%d\n", ft_printf("%-4u.", 42));
	// printf("\n%d\n", printf("%-4u.", 42));
	// printf("\n%d\n", ft_printf("%4u.", 42));
	// printf("\n%d\n", printf("%4u.", 42));
	// printf("\n%d\n", ft_printf("%5.4u.", 42));
	// printf("\n%d\n", printf("%5.4u.", 42));
	// printf("\n%d\n", ft_printf("%05.4u.", 42));
	// printf("\n%d\n", printf("%05.4u.", 42));
	// printf("\n%d\n", ft_printf("%05.7u.", 42));
	// printf("\n%d\n", printf("%05.7u.", 42));
}