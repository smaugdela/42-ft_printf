/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:21:31 by smagdela          #+#    #+#             */
/*   Updated: 2021/08/30 13:19:29 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*-#0.*/

#include "ft_printf.h"

static int ft_hex_len(unsigned int nb)
{
	int    len;

	if (nb == 0)
		return (1);
	len = 0;
	while (nb)
	{
		++len;
		nb = nb / 16;
	}
	return (len);
}

static void ft_printer(t_specifier spec, unsigned int arg)
{
    if (arg != 0 && spec.sharp_flag)
	{
		if (spec.converter == 'x')
        	write(1, "0x", 2);
		else
			write(1, "0X", 2);
	}
	ft_print_width(spec.precision, 1, ft_hex_len(arg));
    if (spec.converter == 'x')
        ft_put_unbr_base_fd(arg, 1, "0123456789abcdef");
    else
        ft_put_unbr_base_fd(arg, 1, "0123456789ABCDEF");
}

int		ft_print_xX(t_specifier spec, unsigned int arg)
{
    int arg_len;
	int	len;
    
    arg_len = ft_max(ft_hex_len(arg), spec.precision);
    if (arg != 0 && spec.sharp_flag)
        arg_len += 2;
	len = arg_len;
    if (spec.minus_flag)
	{
        ft_printer(spec, arg);
		len += ft_print_width(spec.width, 0, arg_len);
	}
	else
	{
		len += ft_print_width(spec.width, spec.zero_flag, arg_len);
        ft_printer(spec, arg);
	}
    return (len);
}
