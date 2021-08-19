/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_structspec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 11:42:10 by smagdela          #+#    #+#             */
/*   Updated: 2021/08/17 12:15:27 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static t_specifier ft_init_structspec(t_specifier spec)
{
	spec.minus_flag = 0;
	spec.plus_flag = 0;
	spec.zero_flag = 0;
	spec.space_flag = 0;
	spec.sharp_flag = 0;
	spec.precision = -1;
	spec.width = -1;
	return (spec);
}

t_specifier	ft_scan_structspec(char *spec)
{
	t_specifier	output;
	int			i;
	char		*width_ptr;

	width_ptr = spec;
	while (ft_is_in_charset(spec, "-+ 0#"))
		++width_ptr;
	output = ft_init_structspec(output);
	output.spec = spec;
	if (ft_strrchr(spec, '-') != NULL)
		output.minus_flag = 1;
	else if (ft_strrchr(spec, '0') != NULL && ft_strrchr(spec, '0') < width_ptr)
		output.zero_flag = 1;
	if (ft_strrchr(spec, '+') != NULL)
		output.plus_flag = 1;
	else if (ft_strrchr(spec, ' ') != NULL)
		output.space_flag = 1;
	if (ft_strrchr(spec, '#') != NULL)
		output.sharp_flag = 1;
	if (ft_atoi(width_ptr) > 0)
		output.width = ft_atoi(width_ptr);
	if (ft_strrchr(spec, '.') != NULL)
		output.precision = ft_atoi(ft_strrchr(spec, '.') + 1);
	output.converter = spec[ft_strlen_charset(spec, "cspdiuxX%") - 1];
	return (output);
}
