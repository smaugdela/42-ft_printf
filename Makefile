# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/10 14:45:50 by smagdela          #+#    #+#              #
#    Updated: 2021/09/03 14:34:16 by smagdela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCD	=	sources/
SRCS	=	ft_printf.c \
			ft_print_cpercent.c \
			ft_utils.c \
			ft_init_structspec.c \
			ft_print_s.c \
			ft_print_di.c \
			ft_print_u.c \
			ft_print_x.c \
			ft_print_p.c \
			ft_putstr_fd.c \
			ft_putnbr_fd.c \
			ft_strlen.c \
			ft_substr.c \
			ft_atoi.c \
			ft_isdigit.c \
			ft_strchr.c \
			ft_strdup.c \

OBJD	=	objects/
OBJS	:=	${addprefix ${OBJD}, ${SRCS:.c=.o}}

MKDIR	=	mkdir -pv
COMPILER	=	clang -c -o
CFLAGS	=	-Wall -Wextra -Werror
LINKER	=	ar rc
LFLAGS	=	

${NAME}: ${OBJS}
	${LINKER} $@ ${LFLAGS} ${OBJS}
	ranlib ${NAME}

${OBJD}%.o: ${SRCD}%.c ${OBJD}
	${COMPILER} $@ ${CFLAGS} $<

${OBJD}:
	${MKDIR} ${OBJD}

all: ${NAME}

bonus:	${NAME}

clean:
	rm -rf ${OBJD} ${BONUSD}

fclean:	clean
	rm -rf ${NAME}

re:		fclean all

.PHONY: re all clean fclean bonus
