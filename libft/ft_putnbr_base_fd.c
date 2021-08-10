/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:24:07 by smagdela          #+#    #+#             */
/*   Updated: 2021/08/10 14:29:56 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_base_is_invalid(const char *base)
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

void	ft_putnbr_base_fd(int n, int fd, const char *base)
{
	unsigned int	nbr;
	unsigned int	base_len;

	if (ft_base_is_invalid(base))
		return ;
	if (n < 0)
	{
		write(fd, "-", 1);
		nbr = (unsigned int)(-1 * n);
	}
	else
		nbr = (unsigned int)n;
	base_len = ft_strlen(base);
	if (nbr >= 0 && nbr < base_len)
		write(fd, &base[nbr], 1);
	else
	{
		ft_putnbr_base_fd(nbr / base_len, fd, base);
		ft_putnbr_base_fd(nbr % base_len, fd, base);
	}
}
