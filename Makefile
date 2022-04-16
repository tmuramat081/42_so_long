# Compile variables
NAME := so_long
CC := gcc
CFLAGS := -Wall -Wextra -Werror -g -MMD -MP

ifdef WITH_BONUS
	SRCS := main_bonus.c \
			map_input_bonus.c \
			map_check_bonus.c \
			load_image_bonus.c \
			load_animation_bonus.c \
			render_image_bonus.c \
			render_animation_bonus.c \
			game_bonus.c \
			game_player_bonus.c \
			game_enemy_l_bonus.c \
			game_enemy_s_bonus.c \
			game_object_bonus.c \
			game_collision_bonus.c \
			game_state_bonus.c \
			game_end_bonus.c \
			utils_wrapper_bonus.c \
			utils_list_bonus.c \
			utils_print_bonus.c
	SRC_DIR := srcs_bonus/
	OBJ_DIR := objs_bonus/
else
	SRCS := main.c \
			map_input.c \
			map_check.c \
			load_image.c \
			render_image.c \
			game.c \
			game_player.c \
			game_object.c \
			game_collision.c \
			game_state.c \
			game_end.c \
			utils_wrapper.c \
			utils_list.c \
			utils_print.c
	SRC_DIR := srcs/
	OBJ_DIR := objs/
endif

OBJS := ${addprefix ${OBJ_DIR}, ${SRCS:.c=.o}}
DEPS := ${addprefix ${OBJ_DIR}, ${SRCS:.c=.d}}

ifeq (${shell uname}, Linux)
	MLXDIR := libs/mlx_linux/
	MLX := ${MLXDIR}/libmlx.a
	MFLAGS := -lXext -lX11 -lm
	KEY_MACRO := -D KEYCODE_LINUX
else
	MLXDIR := libs/mlx_mms/
	MLX := ${MLXDIR}/libmlx.dylib
	MFLAGS := -L -framework OpenGL -framework Appkit
	KEY_MACRO := -D KEYCODE_MAC
endif

LIBFTDIR := libs/libft/
LIBFT := ${LIBFTDIR}/libft.a
INCS := -I./incs -I./${LIBFTDIR}/incs/ -I./${MLXDIR}

# Map files
TEST_MAP_SRCS := T00_basic1.ber \
				T01_basic2.ber \
				T02_smallest.ber \
				T03_largest.ber \
				T04_multi_player.ber
ERROR_MAP_SRCS := E00_empty.ber \
				E01_not_closed.ber \
				E02_not_closed2.ber \
				E03_no_collectible.ber \
				E05_no_spawn.ber \
				E06_from_second_line.ber \
				E07_not_rectangle.ber \
				E08_void_line.ber \
				E09_too_large.ber \
				E10_unplayable.ber \
				E11_wrong_char.ber \
				.ber
BONUS_MAP_SRCS := B00_enemy.ber \
				B01_multi_player.ber \
				B02_multi_enemy.ber \
				B03_multi_char.ber
PLAY_MAP_SRCS := M00_maze.ber \
				M01_puzzle.ber \
				M02_action.ber
MAP_DIR := maps/
TEST_MAPS := ${addprefix ${MAP_DIR},${TEST_MAP_SRCS:.c=.o}}
ERROR_MAPS := ${addprefix ${MAP_DIR},${ERROR_MAP_SRCS:.c=.o}}
BONUS_MAPS := ${addprefix ${MAP_DIR},${BONUS_MAP_SRCS:.c=.o}}
PLAY_MAPS := ${addprefix ${MAP_DIR},${PLAY_MAP_SRCS:.c=.o}}

# Debug option
MEM_CHECK := valgrind --leak-check=full

# Print variables
PRINTF := printf
DEFAULT := \033[0;39m
BLUE := \033[0;94m
GREEN := \033[0;92m
RED := \033[0;91m
DEL := \033[2K
MOVE := \033[1F
CR := \033[1G

# Progress variables
SRC_TOT := ${shell expr ${words ${SRCS}} - ${shell ls -l ${OBJ_DIR} | grep .o$ | wc -l} + 1}
ifndef ${SRC_TOT}
	SRC_TOT := ${words ${SRCS}}
endif
SRC_CNT := 0
SRC_PCT = ${shell expr 100 \* ${SRC_CNT} / ${SRC_TOT}}
PROGRESS = ${eval SRC_CNT = ${shell expr ${SRC_CNT} + 1}} \
	${PRINTF} "${DEL}${GREEN}$[ %d/%d (%d%%) ] ${CC} ${CFLAGS} $< ...${DEFAULT}${CR}" \
	$(SRC_CNT) $(SRC_TOT) $(SRC_PCT)

# Main commands
${NAME}: ${OBJS} ${LIBFT} ${MLX}
	@${CC} ${CFLAGS} ${INCS} ${OBJS} ${LIBFT} ${MLX} ${MFLAGS} -o $@
	@echo "${BLUE}--- ${NAME} is up to date! ---${DEFAULT}"

all: ${NAME} ${OBJ_DIR}

${LIBFT}:
	@${MAKE} -C ${LIBFTDIR}

${MLX}:
	@${MAKE} -C ${MLXDIR}

${OBJ_DIR}%.o: ${SRC_DIR}%.c
	@${PROGRESS}
	@${CC} ${CFLAGS} ${INCS} -O3 -c $< ${KEY_MACRO} -o $@

bonus:
	@${MAKE} WITH_BONUS=1 --no-print-directory
	@echo "${BLUE}--- ${NAME} bonus is up to date! ---${DEFAULT}"

clean:
	${RM} ${OBJS} ${DEPS}
ifndef WITH_BONUS
	@${MAKE} clean -C ${LIBFTDIR} --no-print-directory
	@${MAKE} clean -C ${MLXDIR} --no-print-directory
	@${MAKE} WITH_BONUS=1 clean --no-print-directory
	@echo "${RED}--- Object files have been deleted. ---${DEFAULT}"
endif
 
fclean: clean
	${RM} ${NAME}
	${MAKE} fclean -C ${LIBFTDIR}
	@echo "${RED}--- Executable file has been deleted. ---${DEFAULT}"

re: fclean
	@${MAKE} -s all

# Debug commands
play_test: all
	@for map in ${TEST_MAPS} ; \
	do ${MEM_CHECK} ./${NAME} $$map ; done
	@echo "${GREEN}----finish----${DEFAULT}"

error_test: all
	@for emap in ${ERROR_MAPS} ; \
	do echo "${GREEN}----$$emap-----${DEFAULT}" ; \
	cat $$emap ; echo "\n" ; \
	${MEM_CHECK} ./${NAME} $$emap ; done
	@echo "${GREEN}----finish----${DEFAULT}"

play: bonus
	@for emap in ${PLAY_MAPS} ; \
	do ./${NAME} $$emap ; done
	@echo "${GREEN}----finish----${DEFAULT}"

git:
	git add .
	git commit 
	git push

norm:
	norminette ${SRC_DIR}
ifndef WITH_BONUS
	norminette ${LIBFTDIR} ./incs
	@${MAKE} WITH_BONUS=1 norm --no-print-directory
endif

-include ${DEPS}

nm: $(NAME)
	nm -u $(NAME) | grep -v -e 'mlx_' -e 'ft_' -e ' __' -e ' X' | \
	grep -v -e open -e close -e read -e write -e malloc -e free -e perror -e strerror -e exit

.PHONY: all bonus clean fclean re error_test play_test play git norm