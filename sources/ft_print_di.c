/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:32:45 by smagdela          #+#    #+#             */
/*   Updated: 2021/08/25 10:20:08 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*-0+ .*/

#include "printf.h"

static int	ft_nblen(int nb)
{
	unsigned int	len;
	unsigned int	tmp_nb;

	if (nb == 0)
		return (1);
	len = 0;
	if (nb < 0)
	{
		++len;
		tmp_nb = -nb;
	}
	else
		tmp_nb = nb;
	while (tmp_nb)
	{
		++len;
		tmp_nb = tmp_nb / 10;
	}
	return (len);
}

static unsigned int	ft_absol(int nb)
{
	if (nb >= 0)
		return ((unsigned int)nb);
	return ((unsigned int)(-1 * nb));
}

static void	ft_printer(t_specifier spec, int arg)
{
	if (arg >= 0)
	{
		if (spec.plus_flag)
			write(1, "+", 1);
		else if (spec.space_flag)
			write(1, " ", 1);
	}
	else
	{
		write(1, "-", 1);
		arg = ft_absol(arg);
	}
	ft_print_width(spec.precision , 1, ft_nblen(arg));
	ft_putnbr_fd(arg, 1);
}

int ft_print_di(t_specifier spec, int arg)
{
    int arg_len;

	arg_len = ft_max(ft_nblen(arg), spec.precision);
    if (arg >= 0)
        arg_len += spec.plus_flag + spec.space_flag;
	else
		++arg_len;
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
