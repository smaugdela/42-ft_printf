/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:32:45 by smagdela          #+#    #+#             */
/*   Updated: 2021/08/19 20:55:01 by smagdela         ###   ########.fr       */
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

int ft_print_di(t_specifier spec, int arg)
{
    int nb_len;

    nb_len = ft_nblen(arg);
    if (arg >= 0)
        nb_len += spec.plus_flag + spec.space_flag;
    if (spec.minus_flag == 1)
        ft_printer(spec, arg);
    if (spec.precision != -1)
    {
        
    }
}
