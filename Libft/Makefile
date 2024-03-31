# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkoval <kkoval@student.42barcelon>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 17:33:00 by kkoval            #+#    #+#              #
#    Updated: 2023/03/10 16:03:12 by kkoval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_isalpha.c ft_toupper.c ft_isdigit.c ft_tolower.c ft_isalnum.c \
	   ft_isascii.c ft_isprint.c ft_strchr.c ft_strlen.c ft_memset.c \
	   ft_memmove.c ft_strrchr.c ft_bzero.c ft_strncmp.c  ft_memcpy.c \
	   ft_memcmp.c ft_strlcpy.c ft_calloc.c ft_atoi.c ft_memchr.c ft_strnstr.c \
	   ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	   ft_strmapi.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	   ft_putnbr_fd.c ft_striteri.c ft_strlcat.c

OBJS = ${SRCS:.c=.o}

HEADER = libft.h
NAME = libft.a
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

%.o: %.c	Makefile ${HEADER} 
	${CC} ${CFLAGS} -c $< -o $@ #${<:.c=.o}

all:        ${NAME}

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}
			ranlib ${NAME}

clean:
			${RM} ${OBJS}
			${RM}

fclean:     clean
			${RM} ${NAME}

re:         fclean all

.PHONY: all clean fclean re
