/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unbr_base_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 12:06:16 by smagdela          #+#    #+#             */
/*   Updated: 2021/08/27 12:11:35 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_base_is_invalid(char *base)
{
	int	i;
	int	j;
	int	base_len;

	base_len = ft_strlen(base);
	if (base_len == 0 || base_len == 1)
		return (1);
	i = -1;
	while (base[++i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (1);
		j = -1;
		while (base[++j])
		{
			if (j == i)
			{
			}
			else if (base[i] == base[j])
				return (1);
		}
	}
	return (0);
}

void    ft_put_unbr_base_fd(__uint64_t n, int fd, char *base)
{
	unsigned int	base_len;

	if (ft_base_is_invalid(base))
		return ;
	base_len = ft_strlen(base);
	if (n >= 0 && n < base_len)
		write(fd, &base[n], 1);
	else
	{
		ft_put_unbr_base_fd(n / base_len, fd, base);
		ft_put_unbr_base_fd(n % base_len, fd, base);
	}
}
