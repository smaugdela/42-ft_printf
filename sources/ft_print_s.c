/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:20:45 by smagdela          #+#    #+#             */
/*   Updated: 2021/08/19 20:20:40 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*-.*/

#include "printf.h"

int ft_print_s(t_specifier spec, char *arg)
{
    if (spec.precision != -1)
        arg = ft_substr(arg, 0, spec.precision);
    else
        arg = ft_strdup(arg);
    if (spec.minus_flag == 1)
    {
        ft_putstr_fd(arg, 1);
        ft_print_width(spec.width, 0, ft_strlen(arg));
    }
    else
    {
        ft_print_width(spec.width, 0, ft_strlen(arg));
        ft_putstr_fd(arg, 1);
    }
    free (arg);
    return (0);
}
