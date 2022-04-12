# Compile variables
NAME = so_long
SRCS =	main.c \
		map_input.c \
		map_check.c \
		load_image.c \
		load_animation.c \
		render_image.c \
		render_animation.c \
		game.c \
		game_key.c \
		game_collision.c \
		game_enemy.c \
		game_end.c \
		utils_wrapper.c \
		utils_list.c \
		utils_print.c
SRC_DIR = srcs/
OBJS = ${addprefix ${OBJ_DIR}, ${SRCS:.c=.o}}
OBJ_DIR = objs/
DEPS = ${addprefix ${OBJ_DIR}, ${SRCS:.c=.d}}

MLXDIR = libs/mlx_linux/
MLX = ${MLXDIR}/libmlx.a

LIBFTDIR = libs/libft/
LIBFT = ${LIBFTDIR}/libft.a

INCS = -I./incs -I./${LIBFTDIR}/incs/ -I./${MLXDIR}
CC = gcc -g -MMD -MP
CFLAGS = -Wall -Wextra -Werror
MFLAGS = -L/usr/lib -lXext -lX11 -lm -lz

# Map files
TEST_MAP_SRCS = T00_basic1.ber \
				T01_basic2.ber \
				T02_smallest.ber \
				T03_largest.ber
ERROR_MAP_SRCS = E00_empty.ber \
				E01_not_closed.ber \
				E02_not_closed2.ber \
				E03_no_collectible.ber \
				E05_no_spawn.ber \
				E06_multi_spawn.ber \
				E07_not_rectangle.ber \
				E08_void_line.ber \
				E09_too_large.ber \
				E10_unplayable.ber \
				E11_wrong_char.ber \
				.ber
BONUS_MAP_SRCS = B00_enemy.ber \
				B01_multi_player.ber \
				B02_multi_enemy.ber \
				B03_multi_char.ber
PLAY_MAP_SRCS = M00_maze.ber \
				M01_puzzle.ber \
				M02_action.ber

MAP_DIR = maps/
TEST_MAPS = ${addprefix ${MAP_DIR},${TEST_MAP_SRCS:.c=.o}}
ERROR_MAPS = ${addprefix ${MAP_DIR},${ERROR_MAP_SRCS:.c=.o}}
BONUS_MAPS = ${addprefix ${MAP_DIR},${BONUS_MAP_SRCS:.c=.o}}
PLAY_MAPS = ${addprefix ${MAP_DIR},${PLAY_MAP_SRCS:.c=.o}}

# Debug option
MEM_CHECK = valgrind --leak-check=full

# Print variables
PRINTF = printf
DEFAULT = \033[0;39m
BLUE = \033[0;94m
GREEN = \033[0;92m
RED = \033[0;91m

# Progress variables
SRC_COUNT_TOT := ${shell expr ${words ${SRCS}} - ${shell ls -l ${OBJ_DIR} | grep .o$ | wc -l} + 1}
ifndef ${SRC_COUNT_TOT}
	SRC_COUNT_TOT := ${words ${SRCS}}
endif
SRC_COUNT := 0
SRC_PCT = ${shell expr 100 \* ${SRC_COUNT} / ${SRC_COUNT_TOT}}
PROGRESS = ${eval SRC_COUNT = ${shell expr ${SRC_COUNT} + 1}} \
	${PRINTF} "${GREEN}\r%100s\r[ %d/%d (%d%%) ] Compiling $< ...${DEFAULT}" "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)

# Commands
all: ${NAME}

${LIBFT}:
	@${MAKE} -C ${LIBFTDIR}

${MLX}:
	@${MAKE} -C ${MLXDIR}

${NAME}: ${OBJS} ${LIBFT} ${MLX}
	@${CC} ${CFLAGS} ${OBJS} ${LIBFT} ${MLX} ${MFLAGS} ${INCS} -o $@
	@echo "${BLUE}--- ${NAME} is up to date! ---${DEFAULT}"

${OBJ_DIR}%.o: ${SRC_DIR}%.c
	@mkdir -p ${OBJ_DIR}
	@${PROGRESS}
	@${CC} ${CFLAGS} -I/usr/include ${INCS} -O3 -c $< -o $@

clean:
	${MAKE} clean -C ${LIBFTDIR}
	${MAKE} clean -C ${MLXDIR}
	${RM} ${OBJS} ${DEPS}

fclean: clean
	${RM} ${NAME}
	${MAKE} fclean -C ${LIBFTDIR}

re: fclean
	${MAKE} -s all

play_test: all
	@for map in ${TEST_MAPS} ; \
	do ${MEM_CHECK} ./${NAME} $$map ; done
	@echo "${GREEN}----finish----${DEFAULT}"

error_test: all
	@for emap in ${ERROR_MAPS} ; \
	do echo "${GREEN}----$$emap-----${DEFAULT}" ; \
	cat $$emap ; echo "\n" ; \
	${MEM_CHECK} ./${NAME} $$emap ; done ; \
	@echo "${GREEN}----finish----${DEFAULT}"

play: all
	@for emap in ${PLAY_MAPS} ; \
	do ./${NAME} $$emap ; done
	@echo "${GREEN}----finish----${DEFAULT}"

-include ${DEPS}

git:
	git add .
	git commit 
	git push

norm:
	norminette ${SRC_DIR} ${LIBFTDIR}
	echo $?

.PHONY: all clean fclean re error_test play_test git