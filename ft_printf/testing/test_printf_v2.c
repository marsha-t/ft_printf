/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf_v2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:20:56 by mateo             #+#    #+#             */
/*   Updated: 2024/01/05 18:39:36 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

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

	// NOPE
	// printf(".% 3c.\n", -191); // space nope
	// printf(".%#3c.\n", -191); // # nope
	// printf(".%+3c.\n", -191); // + nope
	// printf(".%03c.\n", -191); // 0 nope
	// printf(".%-.5c.\n", 65); // . nope
	
	//////////////////////////////////////////////////////////////////////////////////////////////
	// Test flags for %s
	//////////////////////////////////////////////////////////////////////////////////////////////
	// printf("%s\n", "abc"); // base case

	// BONUS
	// printf("%.2s\n", "abc"); // max 2 characters printed
	// printf("%3.2s\n", "abc"); // max 2 characters printed but field is 3 therefore pad with space
	// printf("%-3.2s\n", "abc"); // max 2 characters printed but field is 3; left aligned
	// printf("%3.3s\n", "abc"); // max 3 characters printed with field 3
	// printf("%2.3s\n", "abc"); // max 3 characters printed with field 2
	// printf("%.5s\n", "abc"); // precision > strlen

	// NOPE
	// printf("%#s\n", "abc"); // # useless
	// printf("%0s\n", "abc"); // 0 useless
	// printf("%+s\n", "abc"); // + useless
	// printf(".%+s.\n", "abc"); // sp useless

	//////////////////////////////////////////////////////////////////////////////////////////////
	// Test flags for %p
	//////////////////////////////////////////////////////////////////////////////////////////////
	// char *ptr = "abc";
	// MANDATORY
	// printf("%d\n", printf("%p\n", ptr)); // default 14 characters; 9 characters in school // 0x100a42fa2
	// printf("%p\n", (void *)-1); //0xffffffffffffffff
	// printf("%p\n", (void *)1); // 0x1
	// printf("%p\n", (void *)15); // 0xf
	// printf("%p\n", (void *)16); // 0x10
	// printf("%p\n", (void *)17); // 0x11
	// printf("%p %p\n", (void *)LONG_MIN, (void *)LONG_MAX); // 0x8000000000000000 0x7fffffffffffffff
	// printf("%p %p\n", (void *)INT_MIN, (void *)INT_MAX); // 0xffffffff80000000 0x7fffffff
	// printf("%p %p\n", (void *)ULONG_MAX, (void *)-ULONG_MAX); // 0xffffffffffffffff 0x1
	// printf("%p %p\n", (void *)0, (void *)0); // 0x0 0x0

	// BONUS
	// printf("%d\n", printf(".%15p.\n", ptr)); //  .    0x10dd02f96.
	// printf("%d\n", printf(".%-15p.\n", ptr)); // .0x10dd02f96    .

	// NOPE
	// printf("%#p\n", ptr); // # useless
	// printf("%0p\n", ptr); // # 0 useless
	// printf("%+p\n", ptr); // + useless
	// printf("% p\n", ptr); // sp useless
	// printf("%.11p\n", ptr); // precision useless
	
	//////////////////////////////////////////////////////////////////////////////////////////////
	// Test flags for %d
	//////////////////////////////////////////////////////////////////////////////////////////////
	// BONUS
	// printf("%0d.\n", 42); // 0 useless on its own
	// printf("%03d.\n", 42); // 0 needs width
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
	
	// printf("a b %.0d c\n", 0); // number not printed if 0 printed with 0 precision
	
	// printf("%+0d\n", 42); // 0 is ignored with sign
	// printf("%+05d\n", 42); // sign is placed before the 0's
	// printf("%+5d\n", 42); // sign is placed after the spaces
	// printf("%-+5d\n", 42); // sign is placed after the spaces
	
	// printf("%-4d.\n", 42); // sp padded on right
	// printf("%.4d.\n", 42); // sp padded on left
	// printf("%5.4d.\n", 42); // padded with 0 and sp
	// printf("%05.4d.\n", 42); // padded with 0 and sp 
	// printf("%05.7d.\n", 42); // padded with 0 due to precision

	// NOPE
	// printf("%#d\n", 42); // # useless
	// printf("%-04d.\n", 42); // 0 ignored when - present
	// printf("%-03d.\n", 42); // 0 ignored when - present
	// printf("%-+05d\n", 42); // 0 ignored when - present
	// printf("%+ d\n", 42); // sp is ignored when + present 

	//////////////////////////////////////////////////////////////////////////////////////////////
	// Test %u
	//////////////////////////////////////////////////////////////////////////////////////////////
	// BONUS
	// printf(".%.0u.\n", 0); // 0 with 0 precision = nothing 
	// printf("%03u.\n", 42); // 0 needs width
	// printf("%.u\n", 42); // precision too small = ignored
	// printf("%.0u\n", 42); // precision too small = ignored
	// printf("%.1u\n", 42); // precision too small = ignored
	// printf("%.2u\n", 42); // precision too small = ignored
	// printf("%04u.\n", 42); // padded with 0 is precision is too big
	
	// printf("a b %.0u c\n", 0); // number not printed if 0 printed with 0 precision
	
	// printf("%-4u.\n", 42); // sp padded on right
	// printf("%.4u.\n", 42); // sp padded on left
	// printf("%5.4u.\n", 42); // padded with 0 and sp
	// printf("%05.4u.\n", 42); // padded with 0 and sp 
	// printf("%05.7u.\n", 42); // padded with 0 due to precision

	// NOPE
	// printf("%+u\n", 42); // + useless
	// printf("% u\n", 42); // sp useless
	// printf("%#u\n", 42); // # useless

	//////////////////////////////////////////////////////////////////////////////////////////////
	// Test %x
	//////////////////////////////////////////////////////////////////////////////////////////////
	// MANDATORY
	// printf("%d\n",printf("%x\n", 42));
	// printf("%d\n",printf("%x\n", UINT_MAX));

	// BONUS
	// printf("%d\n",printf("%#x\n", 42)); // # added 0x
	// printf("%d\n",printf("%.5x\n", 42)); // 
	// printf("%d\n",printf("%.3x\n", UINT_MAX)); // 
	// printf("%d\n",printf("%#.3x\n", UINT_MAX)); // 
	// printf("%d\n",printf("%.5x\n", UINT_MAX)); // 
	// printf("%d\n",printf("%#.5x\n", UINT_MAX)); // 
	// printf("%d\n",printf("%.16x\n", UINT_MAX)); // 
	// printf("%d\n",printf("%#.16x\n", UINT_MAX)); // 
	// printf("%d\n",printf("%5.5x\n", 42)); // 
	// printf("%d\n",printf("%#5.5x\n", 42)); // 
	// printf("%d\n",printf(".%#10.5x.\n", 42)); // 
	// printf("%d\n",printf(".%#-10.5x.\n", 42)); // 

	// printf("%d\n",printf(".%5x.\n", 42));
	// printf("%d\n",printf(".%-5x.\n", 42));
	// printf("%d\n",printf(".%05x.\n", 42));

	// NOPE
	// printf("%+x\n", 42); // + useless
	// printf("% x\n", 42); // sp useless
	// printf("%d\n",printf(".%-05x.\n", 42)); // 0 ignored when - present

	//////////////////////////////////////////////////////////////////////////////////////////////
	// Test %X
	//////////////////////////////////////////////////////////////////////////////////////////////
	// MANDATORY
	// printf("%d\n",printf("%X\n", 42));
	// printf("%d\n",printf("%X\n", UINT_MAX));

	// BONUS
	// printf("%d\n",printf("%#X\n", 42)); // # added 0x
	// printf("%d\n",printf("%.5X\n", 42)); // 
	// printf("%d\n",printf("%.3X\n", UINT_MAX)); // 
	// printf("%d\n",printf("%#.3X\n", UINT_MAX)); // 
	// printf("%d\n",printf("%.5X\n", UINT_MAX)); // 
	// printf("%d\n",printf("%#.5X\n", UINT_MAX)); // 
	// printf("%d\n",printf("%.16X\n", UINT_MAX)); // 
	// printf("%d\n",printf("%#.16X\n", UINT_MAX)); // 
	// printf("%d\n",printf("%5.5X\n", 42)); // 
	// printf("%d\n",printf("%#5.5X\n", 42)); // 
	// printf("%d\n",printf(".%#10.5X.\n", 42)); // 
	// printf("%d\n",printf(".%#-10.5X.\n", 42)); // 

	// printf("%d\n",printf(".%5X.\n", 42));
	// printf("%d\n",printf(".%-5X.\n", 42));
	// printf("%d\n",printf(".%05X.\n", 42));

	// NOPE
	// printf("%+X\n", 42); // + useless
	// printf("% X\n", 42); // sp useless
	// printf("%d\n",printf(".%-05X.\n", 42)); // 0 ignored when - present
	//////////////////////////////////////////////////////////////////////////////////////////////
	// Test %
	//////////////////////////////////////////////////////////////////////////////////////////////

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
