/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:43:53 by smagdela          #+#    #+#             */
/*   Updated: 2021/08/30 13:18:31 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*https://www.ibisc.univ-evry.fr/~petit/Enseignement/Modelisation-en-C/printf-conversions-format.pdf*/

#include "ft_printf.h"

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
	else if (spec.converter == 'u')
		return (ft_print_u(spec, va_arg(arguments, unsigned int)));
	else if (ft_is_in_charset(spec.converter, "xX"))
		return (ft_print_xX(spec, va_arg(arguments, unsigned int)));
	else if (spec.converter == 'p')
		return (ft_print_p(spec, va_arg(arguments, void*)));
	else
		return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list		arguments;
	t_specifier	spec;
	char		*specifier;
	int			tmp_len;
	int			len;

	va_start(arguments, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			tmp_len = ft_strlen_charset(++str, "cspdiuxX%") + 1;
			specifier = ft_substr(str, 0, tmp_len);
			spec = ft_scan_structspec(specifier);
			free(specifier);
			str += tmp_len - 1;
			tmp_len = ft_dispatcher(spec, arguments);
			if (tmp_len == -1)
				return (len);
			else
				len += tmp_len;
		}
		else
		{
			write(1, str, 1);
			++len;
		}
		++str;
	}
	va_end(arguments);
	return (len);
}
