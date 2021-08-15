/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:21:28 by smagdela          #+#    #+#             */
/*   Updated: 2021/08/15 16:39:50 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_base_fd(int n, int fd, const char *base);
int		ft_strlen(char *str);
void	ft_putnbr_fd(int n, int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_print_cpercent(const char *specifier, char arg);
int		ft_print_s(const char *specifier, char* arg);
int		ft_print_di(const char *specifier, int arg);
int		ft_print_u(const char *specifier, unsigned int arg);
int		ft_print_xX(const char *specifier, unsigned int arg);
int		ft_print_p(const char *specifier, void* arg);

#endif
