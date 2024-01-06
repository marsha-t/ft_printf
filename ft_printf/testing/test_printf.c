/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:20:56 by mateo             #+#    #+#             */
/*   Updated: 2024/01/02 11:12:02 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	//////////////////////////////////////////////////////////////////////////////////////////////
	// Test flags for %c
	//////////////////////////////////////////////////////////////////////////////////////////////
	// printf(".%c.\n", 'm'); // base
	// printf(".%-c.\n", 'm'); // redundant - flag
	// printf(".%-2c.\n", 'm'); // left aligned
	// printf(".%2c.\n", 'm'); // right aligned; default
	// printf(".%3c.\n", -191); //	
	// printf(".% 3c.\n", -191); // space flag has no effect
	// printf(".%#3c.\n", -191); // # has no effect
	// printf(".%+3c.\n", -191); // + has no effect
	// printf(".%03c.\n", -191); // 0 has no effect
	// printf(".%-.5c.\n", 65); // . has no effect
	// printf(".%0c.\n", 'm'); // 0 width has no effect
	
	//////////////////////////////////////////////////////////////////////////////////////////////
	// Test flags for %s
	//////////////////////////////////////////////////////////////////////////////////////////////
	// printf("%s\n", "abc"); // base case
	// printf("%.2s\n", "abc"); // max 2 characters printed
	// printf("%3.2s\n", "abc"); // max 2 characters printed but field is 3 therefore pad with space
	// printf("%-3.2s\n", "abc"); // max 2 characters printed but field is 3; left aligned
	// printf("%3.3s\n", "abc"); // max 3 characters printed with field 3
	// printf("%2.3s\n", "abc"); // max 3 characters printed with field 2
	// printf("%.5s\n", "abc"); // precision > strlen

	// printf("%#s\n", "abc"); // # useless
	// printf("%0s\n", "abc"); // 0 useless
	// printf("%+s\n", "abc"); // + useless
	// printf(".%+s.\n", "abc"); // sp useless

	//////////////////////////////////////////////////////////////////////////////////////////////
	// Test flags for %p
	//////////////////////////////////////////////////////////////////////////////////////////////
	// char *ptr = "abc";
	// printf("%p\n", ptr); // default 16 characters
	// printf("%.11p\n", ptr); // min 12 (on own pc at least)
	// printf("%.12p\n", ptr); 
	// printf("%.13p\n", ptr); // pad with 0
	// printf("%.14p\n", ptr);
	// printf("%.15p\n", ptr);
	// printf("%.16p\n", ptr);
	// printf("%.18p\n", ptr);
	// printf("%20.18p\n", ptr); // pad with space if width > prec
	// printf("%-20.18p.\n", ptr); // left align if there's padding
	// printf("%#p\n", ptr); // # shortens default to 12 characters instead of 16
	// printf("%0p\n", ptr); // 0 useless if no width
	// printf("%020p\n", ptr); // pad with 0 instead of space if width
	// printf("%-020p\n", ptr); // 0 useless when there's left alignment; default is 12 characters
	// printf("%-20p\n", ptr); // 0 useless when there's left alignment; default is 12 characters
	// printf("%-020.16p\n", ptr); // 0 useless when there's left alignment; default is 12 characters
	// printf("%+p\n", ptr); // + useless
	// printf("% p\n", ptr); // sp useless
	// printf("%#16.11p\n", ptr); // 
	// printf("%#16.12p\n", ptr); // default of 12 characters + 0x even if precision is too small
	// printf("%#16.13p\n", ptr); // pad 0 as precision increases 
	// printf("%#16.14p\n", ptr); // 
	// printf("%#16p\n", ptr); // 

	//////////////////////////////////////////////////////////////////////////////////////////////
	// Test flags for %d
	//////////////////////////////////////////////////////////////////////////////////////////////
	// printf("%0d.\n", 42); // 0 useless on its own
	// printf("%03d.\n", 42); // 0 needs width
	// printf("%-03d.\n", 42); // 0 ignored if left
	
	// printf("% d.\n", 42); // sp added space 
	// printf("% 3d.\n", 42); // sp counted in width
	// printf("% d.\n", -42); // sp didnt have an effect since value is neg
	// printf("%- 3d.\n", 42); // sp is always in front even with left
	// printf("%- 4d.\n", 42); // sp is always in front even with left and additional padding is to the end
	// printf("% 4d.\n", 42); // sp is always in front, together with additional padding
	// printf("% 04d.\n", 42); // sp is always in front, together with additional padding
	// printf("% 4.3d.\n", 42); // sp is always in front, together with additional padding
	// printf("%.d\n", 42); // precision too small = ignored
	// printf("%.0d\n", 42); // precision too small = ignored
	// printf("%.1d\n", 42); // precision too small = ignored
	// printf("%.2d\n", 42); // precision too small = ignored
	// printf("%04d.\n", 42); // padded with 0 is precision is too big
	// printf("%-04d.\n", 42); // 0 ignored if left
	// printf("%#d\n", 42); // # useless
	// printf("a b %.0d c\n", 0); // number not printed if 0 printed with 0 precision
	
	// printf("%+0d\n", 42); // 0 is ignored with sign
	// printf("%+ d\n", 42); // sp is ignored with sign 
	// printf("%+05d\n", 42); // sign is placed before the 0's
	// printf("%+5d\n", 42); // sign is placed after the spaces
	// printf("%-+05d\n", 42); // sign is placed before the 0's
	// printf("%-+5d\n", 42); // sign is placed after the spaces
	
	// printf("%-4d.\n", 42); // sp padded on right
	// printf("%.4d.\n", 42); // sp padded on left
	// printf("%5.4d.\n", 42); // padded with 0 and sp
	// printf("%05.4d.\n", 42); // padded with 0 and sp 
	// printf("%05.7d.\n", 42); // padded with 0 due to precision

	//////////////////////////////////////////////////////////////////////////////////////////////
	// Test %u
	//////////////////////////////////////////////////////////////////////////////////////////////
	// printf(".%.0u.\n", 0); // 0 with 0 precision = nothing 
	// printf("%+u\n", 42); // sign doesnt work 
	// printf("% u\n", 42); // adds space work 
	printf("%#u\n", 42); // # doesn't work 

	// Test %
	// printf(".%%.\n");
	// printf(".%    %.\n");
	// printf(".%bb%.\n");

	// invalid flags
	// printf(".%bd.\n");
	// Single %
	// printf("abc%zzzz");	

	// Return value
	// printf("\nreturn value: %d", printf("abc"));
	// printf("\nreturn value: %d", printf("ab%dc", 1000));
	
	// Number of arguments
	// printf("%d, %d, %d", 1, 2, 3, 4);

	return (0);
}
