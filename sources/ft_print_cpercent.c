/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cpercent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:20:23 by smagdela          #+#    #+#             */
/*   Updated: 2021/08/17 11:41:35 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*-*/

#include "printf.h"


int		ft_print_cpercent(const char *specifier, char arg)
{
	int	bool_0flag;
	int	curseur;

	if (ft_strlen((char*) specifier) < 2)
		write(1, &arg, 1);
	else
	{
		bool_0flag = 0;
		curseur = 0;
		if (specifier[0] == '-')
		{
			write(1, &arg, 1);
			++curseur;
		}
		else if (specifier[0] == '0')
		{
			bool_0flag = 1;
			++curseur;
		}
		if (specifier[curseur] >= '0' && specifier[curseur] <= '9')
		{
			ft_print_width(ft_atoi(specifier + curseur), bool_0flag, 1);
			while(specifier[curseur] >= '0' && specifier[curseur] <= '9')
				++curseur;
		}
		if (specifier[0] != '-')
			write(1, &arg, 1);
	}
	return (0);
}
