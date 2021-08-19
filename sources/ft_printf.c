/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:43:53 by smagdela          #+#    #+#             */
/*   Updated: 2021/08/19 20:55:02 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*https://www.ibisc.univ-evry.fr/~petit/Enseignement/Modelisation-en-C/printf-conversions-format.pdf*/

#include "printf.h"

static int	ft_dispatcher(t_specifier spec, va_list arguments)
{
	if (spec.converter == 'c')
		return (ft_print_cpercent(spec, (char) va_arg(arguments, int)));
	else if (spec.converter == '%')
		return (ft_print_cpercent(spec, '%'));
	else if (spec.converter == 's')
		return (ft_print_s(spec, va_arg(arguments, char*)));
	else if (ft_is_in_charset(spec.converter, "di"))
		return (ft_print_di(spec, va_arg(arguments, int)));
/*	else if (spec.converter == 'u')
		return (ft_print_u(spec, va_arg(arguments, unsigned int)));
	else if (ft_is_in_charset(spec.converter, "xX"))
		return (ft_print_xX(spec, va_arg(arguments, unsigned int)));
	else if (spec.converter == 'p')
		return (ft_print_p(spec, va_arg(arguments, void*)));*/
	else
		return (42);
}

int	ft_printf(const char *str, ...)
{
	va_list		arguments;
	t_specifier	spec;
	char		*specifier;
	int			spec_len;

	va_start(arguments, str);
	while (*str)
	{
		if (*str == '%')
		{
			spec_len = ft_strlen_charset(++str, "cspdiuxX%") + 1;
			specifier = ft_substr(str, 0, spec_len);
			spec = ft_scan_structspec(specifier);
			free(specifier);
			str += spec_len - 1;
			if (ft_dispatcher(spec, arguments) != 0)
				return (42);
		}
		else
			write(1, str, 1);
		++str;
	}
	va_end(arguments);
	return (0);
}
