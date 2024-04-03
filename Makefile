# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkoval <kkoval@student.42barcelon>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/31 20:52:37 by kkoval            #+#    #+#              #
#    Updated: 2024/03/31 23:15:56 by kkoval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = main.c

OBJS = ${SRCS:.c=.o}

HEADER = fractol.h
INCS = -I ./Libft -I ./minilibx
LIBS = -LLibft -lft -Lminilibx -lmlx

#LIBS = -L./ -lft -L./ -lmlx
NAME = fractol
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
MNLXFLAGS = -framework OpenGL -framework AppKit

all:        ${NAME}

./Libft/libft.a :
			make -C ./Libft
./minilibx/libmlx.a : 
			make -C ./minilibx 2> /dev/null
#main.o: main.c	Makefile ${HEADER} ./Libft/libft.a ./minilibx/libmlx.a 
#	${CC} ${CFLAGS} ${INCS} -c $< -o $@ #${<:.c=.o}
%.o: %.c	Makefile ${HEADER} ./Libft/libft.a ./minilibx/libmlx.a 
	echo OBJECTS
	${CC} ${INCS} -c $< -o $@ #${<:.c=.o}


${NAME}:	${OBJS}
	echo NAME
	${CC}  ${LIBS} ${OBJS} ${MNLXFLAGS} -o ${NAME}
clean:
			${RM} ${OBJS}
			make -C ./Libft clean

fclean:     clean
			${RM} ${NAME}
			make -C ./Libft fclean
			make -C ./minilibx clean

re:         fclean all

.PHONY: all clean fclean re ./Libft/libft.a ./minilibx/libmlx.a
