# Compile variables
NAME = so_long
SRCS = main.c map.c image.c event.c render.c validate.c print.c utils.c
SRC_DIR = src/
OBJS = ${addprefix ${OBJ_DIR}, ${SRCS:.c=.o}}
OBJ_DIR = obj/
MLXDIR = libs/mlx_linux/
MLX = ${MLXDIR}/libmlx.a
LIBFTDIR = libs/libft/
LIBFT = ${LIBFTDIR}/libft.a
INCS = -I./incs -I./${LIBFTDIR} -I./${MLXDIR} -I./${LIBFTDIR}printf -I./${LIBFTDIR}get_next_line
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MFLAGS = -L/usr/lib -lmlx -lXext -lX11 -lm -lz
PLAY_MAP_SRCS = M00_basic1.ber M01_basic2.ber M02_smallest.ber M03_largest.ber
ERROR_MAP_SRCS = E00_empty.ber E01_not_closed.ber E02_not_closed2.ber E03_no_collectible.ber \
	E05_no_spawn.ber E06_multi_spawn.ber E07_not_rectangle.ber E08_void_line.ber \
	E09_too_large.ber E10_unplayable.ber E11_wrong_char.ber .ber
MAP_DIR = map/
PLAY_MAPS = ${addprefix ${MAP_DIR},${PLAY_MAP_SRCS:.c=.o}}
ERROR_MAPS = ${addprefix ${MAP_DIR},${ERROR_MAP_SRCS:.c=.o}}
MEM_CHECK = valgrind --leak-check=full

# Print variables
PRINTF = printf
DEFAULT = \033[0;39m
BLUE = \033[0;94m
GREEN = \033[0;92m
RED = \033[0;91m

# Progress variables
SRC_COUNT_TOT := ${shell expr ${words ${SRCS}} - ${shell ls -l ${OBJ_DIR} | grep .o$ | wc -l} + 1}
SRC_COUNT := 0
SRC_PCT = ${shell expr 100 \* ${SRC_COUNT} / ${SRC_COUNT_TOT}}
PROGRESS = ${eval SRC_COUNT = ${shell expr ${SRC_COUNT} + 1}} \
	@${PRINTF} "${GREEN}\r%100s\r[ %d/%d (%d%%) ] Compiling $< ...${DEFAULT}" "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)

# Commands
all: ${NAME}
	@echo "${BLUE}--- ${NAME} is up to date! ---${DEFAULT}"

${LIBFT}:
	@${MAKE} -C ${LIBFTDIR}

${MLX}:
	@${MAKE} -C ${MLXDIR}

${NAME}: ${OBJS} ${LIBFT} ${MLX}
	@${CC} ${CFLAGS} ${OBJS} ${LIBFT} ${MLX} ${MFLAGS} ${INCS} -o $@

${OBJ_DIR}%.o: ${SRC_DIR}%.c
	@mkdir -p ${OBJ_DIR}
	@${PROGRESS}
	@${CC} ${CFLAGS} -I/usr/include ${INCS} -O3 -c $< -o $@

clean:
	${MAKE} clean -C ${LIBFTDIR} --no-print-directory
	${MAKE} clean -C ${MLXDIR} --no-print-directory
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}
	${MAKE} fclean -C ${LIBFTDIR} --no-print-directory

re: fclean
	${MAKE} all

play: all
	for map in ${PLAY_MAPS} ; \
	do ${MEM_CHECK} ./${NAME} $$map ; done

test: all
	for emap in ${ERROR_MAPS} ; \
	do echo "----$$emap-----" ; \
	cat $$emap ; echo "\n" ; \
	${MEM_CHECK} ./${NAME} $$emap ; done ; \
	echo "----finish----"

git:
	git add .
	git commit 
	git push

.PHONY: all clean fclean re test play git