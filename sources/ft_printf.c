/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:43:53 by smagdela          #+#    #+#             */
/*   Updated: 2021/08/15 16:40:52 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_is_in_charset(char c, char *charset)
{
	while(*charset)
	{
		if (c == *charset)
			return (1);
		++charset;
	}
	return (0);
}

static int	ft_strlen_charset(const char *str, char *charset)
{
	int	len;

	len = 0;
	while(ft_is_in_charset(str[len], charset) == 0 && str[len])
		++len;
	return (len);
}

static int	ft_dispatcher(const char *specifier, int spec_len, va_list arguments)
{
	if (ft_is_in_charset(specifier[spec_len - 1], "c%"))
		return (ft_print_cpercent(specifier, (char) va_arg(arguments, int)));
	else if (specifier[spec_len - 1] == 's')
		return (ft_print_s(specifier, va_arg(arguments, char*)));
	else if (ft_is_in_charset(specifier[spec_len - 1], "di"))
		return (ft_print_di(specifier, va_arg(arguments, int)));
	else if (specifier[spec_len - 1] == 'u')
		return (ft_print_u(specifier, va_arg(arguments, unsigned int)));
	else if (ft_is_in_charset(specifier[spec_len - 1], "xX"))
		return (ft_print_xX(specifier, va_arg(arguments, unsigned int)));
	else if (specifier[spec_len - 1] == 'p')
		return (ft_print_p(specifier, va_arg(arguments, void*)));
	else
		return (42);
}

int	ft_printf(const char *str, ...)
{
	va_list	arguments;
	char	*specifier;
	int		spec_len;

	va_start(arguments, str);
	while (*str)
	{
		if (*str == 37)
		{
			spec_len = ft_strlen_charset(++str, "cspdiuxX%");
			specifier = ft_substr(str, 0, spec_len);
			str += spec_len - 1;
			if (ft_dispatcher(specifier, spec_len, arguments) == 42)
			{
				free(specifier);
				return (42);
			}
			free(specifier);
		}
		else
			write(1, str, 1);
		++str;
	}
	va_end(arguments);
	return (0);
}
