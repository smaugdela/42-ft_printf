/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 08:07:56 by smagdela          #+#    #+#             */
/*   Updated: 2021/08/16 09:44:19 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_is_in_charset(char c, char *charset)
{
	while(*charset)
	{
		if (c == *charset)
			return (1);
		++charset;
	}
	return (0);
}

int	ft_strlen_charset(const char *str, char *charset)
{
	int	len;

	len = 0;
	while(ft_is_in_charset(str[len], charset) == 0 && str[len])
		++len;
	return (len);
}

void	ft_print_width(int width, int bool_0flag, int arg_len)
{
	int		len;
	char	c;

	len = width - arg_len;
	if(bool_0flag == 0)
		c = ' ';
	else
		c = '0';
	while (len--)
		write(1, &c, 1);
}
