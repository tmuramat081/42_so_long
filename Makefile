NAME = so_long
SRCS = ./src/main.c \
	./src/init_game.c \
	./src/input_map.c \
	./src/input_image.c \
	./src/set_hook.c \
	./src/render.c \
	./src/utils.c
OBJS = ${SRCS:.c=.o}
MLXDIR = mlx
MLX = ${MLXDIR}/libmlx.a
LIBFTDIR = libft
LIBFT = ${LIBFTDIR}/libft.a
INCS = -I./include -I${LIBFTDIR} -I${MLXDIR}
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MFLAGS = -Lmlx -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all: ${NAME}

${LIBFT}:
	${MAKE} -C ${LIBFTDIR}

${MLX}:
	${MAKE} -C ${MLXDIR}

${NAME}: ${OBJS}
	${MAKE} ${LIBFT}
	${MAKE} ${MLX}
	${CC} ${CFLAGS} ${OBJS} ${MFLAGS} ${LIBFT} ${MLX} ${INCS} -o $@

.c.o:
	${CC} ${CFLAGS} ${INCS} -Imlx_linux -O3 -c $< -o $@

clean:
	rm -f ${OBJS}
	${MAKE} clean -C ${LIBFTDIR}
	${MAKE} clean -C ${MLXDIR}

fclean: clean
	rm -f ${NAME} 
	${MAKE} fclean -C ${LIBFTDIR}

re: fclean all

.PHONY: all bonus clean fclean re kill