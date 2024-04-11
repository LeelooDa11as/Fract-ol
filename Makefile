# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/31 20:52:37 by kkoval            #+#    #+#              #
#    Updated: 2024/04/11 14:47:00 by kkoval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = start_fractol.c render.c color.c mandelbrot.c julia.c utils.c 

OBJS = ${SRCS:.c=.o}
DEPS = ${SRCS:.c=.d}

HEADER = fractol.h
INCS = -I./Libft -I./minilibx
LIBS = -LLibft -lft -Lminilibx -lmlx

NAME = fractol
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g -O3 -MMD #-fsanitize=address
MNLXFLAGS = -framework OpenGL -framework AppKit 

all: lib ${NAME}


lib:
		make -C ./Libft
		make -C ./minilibx 2> /dev/null

%.o: %.c	 
	${CC} ${CFLAGS} ${INCS} -c $< -o $@

${NAME}:	${OBJS} ./Libft/libft.a
	${CC} ${LIBS} ${OBJS} ${MNLXFLAGS} -o ${NAME}

clean:
			${RM} ${OBJS}
			make -C ./Libft clean

fclean:     clean
			${RM} ${NAME}
			make -C ./Libft fclean
			make -C ./minilibx clean

re:         fclean all

-include $(DEPS)

.PHONY: all clean fclean re #./Libft/libft.a #./minilibx/libmlx.a
