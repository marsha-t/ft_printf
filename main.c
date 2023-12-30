/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:12:48 by mateo             #+#    #+#             */
/*   Updated: 2023/12/30 16:59:30 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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

int	ft_len_conv(const char *str, int i)
{
	int	len_conv;

	len_conv = 0;
	while (ft_charinstr(str[i], FLAGS))
	{
		len_conv++;
		i++;
	}
	while (ft_charinstr(str[i], WIDTH))
	{
		len_conv++;
		i++;
	}
	while (ft_charinstr(str[i], PRECISION))
	{
		len_conv++;
		i++;
	}
	if (ft_charinstr(str[i], CONVERSIONS))
		len_conv++;
	else
		return (-1);
	return (len_conv);
}

char	*ft_putword(const char *str, int i, char *word, int len)
{
	int	j;
	
	word = (char *)malloc(sizeof(char) * (len + 1)); 
	j = 0;
	while (len--)
	{
		word[j] = str[i + 1];
		j++;
		i++; 	
	}
	word[j] = '\0';
	return (word);
}

int ft_strlen(char *str)
{
	int	i;
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_conv_s(char *word, char *arg)
{
	(void)word;
	write(1, arg, ft_strlen(arg));
	return (ft_strlen(arg));
}

int	ft_print_conv(va_list va_ptr, char *word, int len)
{
	int	count;
	
	count = 0; //needed?
	if (word[len - 1] == 'c');
	else if (word[len - 1] == 's')
		count = ft_conv_s(word, va_arg(va_ptr, char *));
	else if (word[len - 1] == 'p');
	else if (word[len - 1] == 'd');
	else if (word[len - 1] == 'i');
	else if (word[len - 1] == 'u');
	else if (word[len - 1] == 'x');
	else if (word[len - 1] == 'X');
	else if (word[len - 1] == '%')
	{
		write(1, "%", 1);
		count = 1;
	}
	return (count);
}

void	ft_safefree(void *ptr)
{
	free(ptr);
	ptr = 0;
}

int	ft_printf(const char *str, ...) // no str in assignment prototype // 
{
	int	i;
	int	count;
	char	*word;
	int	len;
	va_list	va_ptr;

	va_start(va_ptr, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len = ft_len_conv(str, i + 1); // length excluding # but including flags and specifier // check order of flags, width, precision, specifier
			if (len < 0)
				return (-1);
			word = ft_putword(str, i, word, len); 
			if (!word)
				return (-1);			
			// printf("word: %s\n", word);
			count += ft_print_conv(va_ptr, word, len);
			ft_safefree(word);
			i += len + 1; 
		}
		else
		{
			write(1, &str[i], 1);
			count += 1;
			i++;
		}
	}
	return (count);
}

#include <stdio.h>
int	main(void)
{
	printf("\nreturn value: %d\n", ft_printf("ab %  sabc", "123"));
	// printf("\nreturn value: %d\n", ft_printf("ab %  zsabc", "123"));
	// printf("\nreturn value: %d\n", ft_printf("ab%", "123"));
}