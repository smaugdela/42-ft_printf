/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:21:28 by smagdela          #+#    #+#             */
/*   Updated: 2021/08/26 11:19:21 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

/* /!\ ATTENTION Supprimer cet include ATTENTION /!\ */

void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_base_fd(long long int n, int fd, const char *base);
int			ft_strlen(char *str);
void		ft_putnbr_fd(long long int n, int fd);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
char		*ft_strrchr(const char *s, int c);
char		*ft_strdup(const char *str);

typedef uint8_t	t_bool;

typedef struct s_specifier
{
	char	*spec;
	t_bool	minus_flag;
	t_bool	plus_flag;
	t_bool	sharp_flag;
	t_bool	zero_flag;
	t_bool	space_flag;
	int		width;
	int		precision;
	char	converter;
}	t_specifier;

int			ft_printf(const char *str, ...);
int			ft_print_cpercent(t_specifier spec, char arg);
int			ft_print_s(t_specifier spec, char *arg);
int			ft_print_di(t_specifier spec, int arg);
int			ft_print_u(t_specifier spec, unsigned int arg);
int			ft_print_xX(t_specifier spec, __uint64_t arg);
int			ft_print_p(t_specifier spec, void *arg);
int			ft_is_in_charset(char c, char *charset);
int			ft_strlen_charset(const char *str, char *charset);
int			ft_print_width(int width, t_bool bool_0flag, int arg_len);
t_specifier	ft_scan_structspec(char *spec);
int			ft_max(int a, int b);

#endif
