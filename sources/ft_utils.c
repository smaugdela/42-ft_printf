/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 08:07:56 by smagdela          #+#    #+#             */
/*   Updated: 2021/08/30 14:02:05 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_is_in_charset(char c, char *charset)
{
	while (*charset)
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
	while (ft_is_in_charset(str[len], charset) == 0 && str[len])
		++len;
	return (len);
}

int	ft_print_width(int width, t_bool zero_flag, int arg_len)
{
	int		len;
	int		tmp_len;
	char	c;

	len = width - arg_len;
	tmp_len = len;
	if (zero_flag == 0)
		c = ' ';
	else
		c = '0';
	while (len-- > 0)
		write(1, &c, 1);
	return (ft_max(tmp_len, 0));
}

void    ft_put_unbr_base_fd(unsigned int n, int fd, char *base)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (n >= 0 && n < base_len)
		write(fd, &base[n], 1);
	else
	{
		ft_put_unbr_base_fd(n / base_len, fd, base);
		ft_put_unbr_base_fd(n % base_len, fd, base);
	}
}
