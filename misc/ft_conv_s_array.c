/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:27:23 by mateo             #+#    #+#             */
/*   Updated: 2024/01/10 12:18:13 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_conv_s(t_conv *conv, char *arg)
{
	int pad;
	int	i;
	char *str;
	int j;
	int write_r;
	
	if (arg && ((conv->prec == 0) || (conv->prec == 1 && conv->prec_num > ft_strlen(arg))))
		conv->prec_num = ft_strlen(arg);
	if (!arg && ((conv->prec == 0) || (conv->prec == 1 && conv->prec_num > 6)))
		conv->prec_num = 6;
	if (conv->width_num < conv->prec_num)
		conv->width_num = conv->prec_num;
	pad = conv->width_num - conv->prec_num;
	str = calloc(conv->width_num + 1, sizeof(char)); /// rmb to free and use ft_calloc
	if (!str)
		return (-1); 
	i = 0;
	j = 0;
	if (conv->left && arg)
	{
		while (conv->prec_num--)
			str[i++] = arg[j++];
	}
	if (conv->left && !arg)
	{
		while (conv->prec_num--)
			str[i++] = NULLSTR[j++];
	}
	while (pad--)
		str[i++] = ' ';
	if (!(conv->left) && arg)
	{
		while (conv->prec_num--)
			str[i++] = arg[j++];
	}
	if (!(conv->left) && !arg)
	{
		while (conv->prec_num--)
			str[i++] = NULLSTR[j++];
	}
	write_r = write(1, str, ft_strlen(str));
	if (write_r < 0)
		return (-1);
	ft_safefree(str);
	return (conv->width_num);
}