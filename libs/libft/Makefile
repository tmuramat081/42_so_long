# Compile variables
NAME = libft.a
CC = gcc

VPATH = ${CHR_DIR}:${STR_DIR}:${MEM_DIR}:${MTH_DIR}:${CNV_DIR}:${PUT_DIR}:${LST_DIR}:${GNL_DIR}:${PRF_DIR}:${SPRF_DIR}

CHR_SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_isspace.c
STR_SRCS = ft_strlen.c ft_split.c ft_strchr.c ft_strcspn.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
	ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtol_d.c ft_substr.c ft_strtoupper.c
MEM_SRCS = ft_bzero.c ft_calloc.c ft_free_matrix.c ft_matrixdup.c ft_matrixlen.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c
MTH_SRCS = ft_abs.c ft_vector_add.c ft_vector_cmp.c ft_vector_lerp.c ft_vector_mul.c ft_vector_sub.c \
	ft_diff_timespec.c
CNV_SRCS = ft_atoi.c ft_itoa.c ft_tolower.c ft_toupper.c
PUT_SRCS = ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c
LST_SRCS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
GNL_SRCS = get_next_line.c
PRF_SRCS = ft_printf.c doprintf.c composer.c parser.c converter.c utils.c printer.c
SPRF_SRCS = ft_snprintf.c sconverter.c sutils.c

CHR_DIR = srcs/character_func/
STR_DIR = srcs/string_func/
MEM_DIR = srcs/memory_func/
MTH_DIR = srcs/math_func/
CNV_DIR = srcs/convert_func/
PUT_DIR = srcs/output_func/
LST_DIR = srcs/list_func/
GNL_DIR = srcs/get_next_line/
PRF_DIR = srcs/printf/
SPRF_DIR = srcs/snprintf/

ALL_SRCS = ${addprefix ${CHR_DIR},${CHR_SRCS}} ${addprefix ${STR_DIR},${STR_SRCS}} ${addprefix ${MEM_DIR},${MEM_SRCS}} ${addprefix ${MTH_DIR},${MTH_SRCS}} \
	${addprefix ${CNV_DIR},${CNV_SRCS}} ${addprefix ${PUT_DIR},${PUT_SRCS}} ${addprefix ${LST_DIR},${LST_SRCS}} ${addprefix ${GNL_DIR},${GNL_SRCS}} ${addprefix ${PRF_DIR},${PRF_SRCS}} \
	${addprefix ${SPRF_DIR},${SPRF_SRCS}}

ALL_OBJS = ${addprefix ${OBJ_DIR},${CHR_SRCS:.c=.o} ${STR_SRCS:.c=.o} ${MEM_SRCS:.c=.o} ${MTH_SRCS:.c=.o} ${CNV_SRCS:.c=.o} ${LST_SRCS:.c=.o} \
	${PUT_SRCS:.c=.o} ${GNL_SRCS:.c=.o} ${PRF_SRCS:.c=.o} ${SPRF_SRCS:.c=.o}}

OBJ_DIR = objs/
INCS = -I./incs
CFLAGS = -Wall -Wextra -Werror
AR = ar rc

# Print variables
PRINTF = printf
DEFAULT = \033[0;39m
BLUE = \033[0;94m
GREEN = \033[0;92m
RED = \033[0;91m
DEL := \033[0K\033[1K
CR := \033[1G

# Progress variables
SRC_TOT := ${shell expr ${words ${ALL_SRCS}} - ${shell ls -l ${OBJ_DIR} | grep .o$ | wc -l} + 1}
ifndef SRC_TOT
	SRC_TOT := ${words ${ALL_SRCS}}
endif
SRC_CNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_CNT) / $(SRC_TOT))
PROGRESS = $(eval SRC_CNT = $(shell expr ${SRC_CNT} + 1)) \
	${PRINTF} "${DEL}${GREEN}[ %d/%d (%d%%) ] ${CC} ${CFLAGS} $< ...${DEFAULT}${CR}" $(SRC_CNT) $(SRC_TOT) $(SRC_PCT)

# Command
${NAME}: ${ALL_OBJS}
	@${AR} ${NAME} ${ALL_OBJS}
	@echo "\n${BLUE}--- ${NAME} is up to date! ---${DEFAULT}"

${OBJ_DIR}%.o: %.c
	@${PROGRESS}
	@${CC} ${CFLAGS} ${INCS} -c $< -o $@

all: ${NAME}

clean:
	${RM} ${ALL_OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean
	@${MAKE} -s all

git:
	git add .
	git commit
	git push

.PHONY: all bonus clean fclean re git