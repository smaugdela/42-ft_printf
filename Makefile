# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/10 14:45:50 by smagdela          #+#    #+#              #
#    Updated: 2021/08/10 18:08:02 by smagdela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

LIBFT	=	libft.a
LIBFTPATH	=	libft/
LIBMAKE		=	make -C ${LIBFTPATH}

SRCD	=	sources/
SRCS	=	ft_printf.c
#SRCS	:=	${addprefix ${SRCD}, ${SRCS}}
OBJD	=	objects/
OBJS	=	${SRCS:.c=.o}
OBJS	:=	${addprefix ${OBJD}, ${OBJS}}
BONUSD	=	bonus/
BONUS	=
BONUSO	=	${BONUS:.c=.o}

MKDIR	=	mkdir -pv
COMPILER	=	gcc -c -o
CFLAGS	=	-Wall -Wextra -Werror
LINKER	=	ar rcs
LFLAGS	=	

${NAME}: ${LIBFT} ${OBJS}
	${LINKER} $@ ${LFLAGS} ${OBJS}

${LIBFT}:
	${LIBMAKE} bonus

${OBJD}%.o: ${SRCD}%.c
	${MKDIR} ${OBJD}
	${COMPILER} $@ ${CFLAGS}${LIBFTPATH}${LIBFT} $<

all: ${NAME}

bonus:	${NAME}

clean:
	rm -rf ${OBJD} ${BONUSD}
	${LIBMAKE} clean

fclean:	clean
	rm -rf ${NAME}
	${LIBMAKE} fclean

re:		fclean all
	${LIBMAKE} re

.PHONY: re all clean fclean
