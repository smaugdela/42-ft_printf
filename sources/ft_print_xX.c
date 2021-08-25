/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:21:31 by smagdela          #+#    #+#             */
/*   Updated: 2021/08/25 11:16:07 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*-#0.*/

#include "printf.h"

static unsigned int ft_hex_len(__uint64_t nb)
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

static void ft_printer(t_specifier spec, __uint64_t arg)
{
    if (arg != 0 && spec.sharp_flag)
        write(1, "0x", 2);
    ft_print_width(spec.precision, 1, ft_hex_len(arg));
    if (spec.converter == 'x')
        ft_putnbr_base_fd(arg, 1, "0123456789abcdef");
    else
        ft_putnbr_base_fd(arg, 1, "0123456789ABCDEF");
}

int		ft_print_xX(t_specifier spec, __uint64_t arg)
{
    int arg_len;
    
    arg_len = ft_max(ft_hex_len(arg), spec.precision);
    if (arg != 0 && spec.sharp_flag)
        arg_len += 2;
    if (spec.minus_flag)
	{
        ft_printer(spec, arg);
		ft_print_width(spec.width, spec.zero_flag, arg_len);
	}
	else
	{
		ft_print_width(spec.width, spec.zero_flag, arg_len);
        ft_printer(spec, arg);
	}
    return (0);
}
