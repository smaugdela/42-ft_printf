/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:22:13 by smagdela          #+#    #+#             */
/*   Updated: 2021/08/30 13:42:11 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*-*/

#include "ft_printf.h"

static size_t ft_hex_len(uint64_t nb)
{
	size_t	len;

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

static void ft_printer(uint64_t arg)
{
    write(1, "0x", 2);
    ft_put_unbr_base_fd(arg, 1, "0123456789abcdef");
}

int		ft_print_p(t_specifier spec, void* arg)
{
    uint64_t    ptr;
	size_t		len;

    if (arg == NULL)
    {
        ft_putstr_fd(OSNUL, 1);
        return (ft_strlen(OSNUL));
    }
    ptr = (uint64_t)arg;
	len = ft_hex_len(ptr) + 2;
	if (spec.minus_flag)
	{
        ft_printer(ptr);
		len += ft_print_width(spec.width, 0, len);
	}
	else
	{
		len += ft_print_width(spec.width, 0, len);
        ft_printer(ptr);
	}
	return (len);
}
