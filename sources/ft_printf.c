/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:43:53 by smagdela          #+#    #+#             */
/*   Updated: 2021/08/13 12:38:43 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	arguments;

	va_start(arguments, str);
	while (*str)
	{
		if (*str == 37)
		{
			/*serious business here...*/
		}
		else
		{
			write(1, str, 1);
			++str;
		}
	}
	va_end(arguments);
	return (0);
}
