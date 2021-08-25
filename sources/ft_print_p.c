/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:22:13 by smagdela          #+#    #+#             */
/*   Updated: 2021/08/25 11:28:14 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*-*/

#include "ft_printf.h"

int		ft_print_p(t_specifier spec, void* arg)
{
    __uint64_t    ptr;

    ptr = (__uint64_t)arg;
    spec.converter = 'x';
    spec.precision = -1;
    spec.sharp_flag = 1;
    spec.zero_flag = 0;
    ft_print_xX(spec, ptr);
    return (0);
}
