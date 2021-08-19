/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cpercent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:20:23 by smagdela          #+#    #+#             */
/*   Updated: 2021/08/19 12:31:37 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* - et -0 pour le %*/

#include "printf.h"

int	ft_print_cpercent(t_specifier spec, char arg)
{
	if (spec.minus_flag == 1)
	{
		write(1, &arg, 1);
		ft_print_width(spec.width, 0, 1);
	}
	else if (spec.zero_flag == 1 && arg == '%')
	{
		ft_print_width(spec.width, 1, 1);
		write(1, &arg, 1);
	}
	else
	{
		ft_print_width(spec.width, 0, 1);
		write(1, &arg, 1);
	}
	return (0);
}
