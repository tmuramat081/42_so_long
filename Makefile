NAME = so_long
SRCS = ./src/test.c
OBJS = ${SRCS:.c=.o}
MLXDIR = mlx
MLX = ${MLXDIR}/libmlx.dylib
LIBFTDIR = libft
LIBFT = ${LIBFTDIR}/libft.a
INCS = -I./includes -I${LIBFTDIR} -I${MLXDIR}
CC = gcc
CFLAGS = #-Wall -Wextra -Werror

all: ${NAME}

${LIBFT}:
	${MAKE} -C ${LIBFTDIR}

${MLX}:
	${MAKE} -C ${MLXDIR}

${NAME}: ${OBJS}
	${MAKE} ${LIBFT}
	${MAKE} ${MLX}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT} ${MLX} ${INCS} -o $@

.c.o:
	${CC} ${CFLAGS} -I ${INCS} -c $< -o $@

clean:
	rm -f ${OBJS}
	${MAKE} clean -C ${LIBFTDIR}
	${MAKE} clean -C ${MLXDIR}

fclean: clean
	rm -f ${NAME} 
	${MAKE} fclean -C ${LIBFTDIR}
	${MAKE} fclean -C ${MLXDIR}

re: fclean all

.PHONY: all bonus clean fclean re kill

