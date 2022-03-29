NAME = so_long
SRCS = ./src/main.c \
	./src/map.c \
	./src/image.c \
	./src/event.c \
	./src/render.c \
	./src/validate.c \
	./src/print.c \
	./src/utils.c
OBJS = ${SRCS:.c=.o}
MLXDIR = ./libs/mlx_linux
MLX = ${MLXDIR}/libmlx.a
LIBFTDIR = ./libs/libft
LIBFT = ${LIBFTDIR}/libft.a
INCS = -I./incs -I${LIBFTDIR} -I${MLXDIR} -I./libs/libft/printf -I./libs/libft/get_next_line
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MFLAGS = -L/usr/lib -lmlx -lXext -lX11 -lm -lz
PLAY_MAPS = M00_basic.ber M01_basic2.ber M02_smallest.ber M03_largest.ber

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

play:

test:

git:
	git add .
	git commit 
	git push

.PHONY: all bonus clean fclean re kill