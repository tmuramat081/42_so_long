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
MAPS = ./map/M00_basic1.ber ./map/M01_basic2.ber ./map/M02_smallest.ber ./map/M03_largest.ber
ERROR_MAPS = ./map/E00_empty.ber ./map/E01_not_closed.ber ./map/E02_not_closed2.ber ./map/E03_no_collectible.ber \
	./map/E05_no_spawn.ber ./map/E06_multi_spawn.ber ./map/E07_not_rectangle.ber ./map/E08_void_line.ber \
	./map/E09_too_large.ber ./map/E10_unplayable.ber ./map/.ber
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

play: all 
	@for map in ${MAPS} ; \
	do ./${NAME} $$map ; \
	done

test: all
	@for emap in ${ERROR_MAPS} ; \
	do echo "----$$emap-----" \
	&& cat $$emap && echo "\n" \
	&& ./${NAME} $$emap && echo "\n" ; \
	done

git:
	git add .
	git commit 
	git push

.PHONY: all bonus clean fclean re kill