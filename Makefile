NAME = so_long
SRCS = ./src/main.c \
	./src/init_game.c \
	./src/input_map.c \
	./src/input_image.c \
	./src/set_event.c \
	./src/render.c \
	./src/validate_map.c \
	./src/utils.c \
	./src/end_game.c
OBJS = ${SRCS:.c=.o}
MLXDIR = ./libs/mlx_linux
MLX = ${MLXDIR}/libmlx.a
LIBFTDIR = ./libs/libft
LIBFT = ${LIBFTDIR}/libft.a
INCS = -I./incs -I${LIBFTDIR} -I${MLXDIR} -I./libs/libft/printf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MFLAGS = -L/usr/lib -lmlx -lXext -lX11 -lm -lz

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
	${CC} ${CFLAGS} -I/usr/include -I./libs/mlx_linux ${INCS} -O3 -c $< -o $@

clean:
	rm -f ${OBJS} ${GNL_OBJS}
	${MAKE} clean -C ${LIBFTDIR}
	${MAKE} clean -C ${MLXDIR}

fclean: clean
	rm -f ${NAME} 
	${MAKE} fclean -C ${LIBFTDIR}

re: fclean all

.PHONY: all bonus clean fclean re kill