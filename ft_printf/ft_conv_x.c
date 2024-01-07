
int	ft_conv_x(t_conv *conv, unsigned int arg, char *base16)
{
	int	count;
	unsigned int	temp;
	int	i;

	temp = arg;
	count = 0; 
	i = 1;
	while (temp / 10)
	{
		temp /= 10;
		i++;
	}

	if (conv->width_num < i)
		conv->width_num = i;
	conv->width_num -= i;

	if (conv->left)
	{
		if (conv->hash)
		{
			count += ft_putchar_ret('0');
			count += ft_putchar_ret('x');
		}
		count += ft_puthex_ret(arg, BASE16_SMALL);
		while (conv->width_num--)
			count += ft_putchar_ret(' ');
	}
	else
	{
		while (conv->width_num--)
			count += ft_putchar_ret(' ');
		if (conv->hash)
		{
			count += ft_putchar_ret('0');
			count += ft_putchar_ret('x');
		}
		count += ft_puthex_ret(arg, BASE16_SMALL);
	}
	return (count);
}