# Compile variables
NAME = libft.a
CC = gcc
LFT_SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c \
ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
ft_split.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c ft_isspace.c ft_lstnew.c ft_lstadd_front.c \
ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
ADD_SRCS = ft_isspace.c ft_strtol_d.c ft_strcspn.c ft_matrixlen.c ft_matrixdup.c ft_free_matrix.c
GNL_SRCS = get_next_line.c
PRF_SRCS = ft_printf.c doprintf.c composer.c parser.c converter.c utils.c printer.c
SRCS = ${LFT_SRCS} ${ADD_SRCS} ${addprefix ${GNL_DIR},${GNL_SRCS}} ${addprefix ${PRF_DIR},${PRF_SRCS}}
OBJS = ${addprefix ${OBJ_DIR},${LFT_SRCS:.c=.o} ${ADD_SRCS:.c=.o} ${GNL_SRCS:.c=.o} ${PRF_SRCS:.c=.o}}
OBJ_DIR = obj/
PRF_DIR = printf/
GNL_DIR = get_next_line/
INCS = -I. -I.${PRF_DIR} -I.${GNL_DIR}
CFLAG = -Wall -Wextra -Werror
AR = ar rc

# Print variables
PRINTF = printf
DEFAULT = \033[0;39m
BLUE = \033[0;94m
GREEN = \033[0;92m
RED = \033[0;91m

# Progress variables
SRC_COUNT_TOT := ${shell expr ${words ${SRCS}} - ${shell ls -l ${OBJ_DIR} | grep .o$ | wc -l}}
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))
PROGRESS = $(eval SRC_COUNT = $(shell expr ${SRC_COUNT} + 1)) \
	@${PRINTF} "${GREEN}\r%100s\r[ %d/%d (%d%%) ] Compiling $< ...${DEFAULT}" "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)

# Command
${NAME}: ${OBJS}
	@${AR} ${NAME} ${OBJS}

${OBJ_DIR}%.o: %.c
	@${PROGRESS}
	@${CC} ${CFLAG} ${INCS} -c $< -o $@

${OBJ_DIR}%.o: ${GNL_DIR}%.c
	@${PROGRESS}
	@${CC} ${CFLAG} ${INCS} -c $< -o $@

${OBJ_DIR}%.o: ${PRF_DIR}%.c
	@${PROGRESS}
	@${CC} ${CFLAG} ${INCS} -c $< -o $@

all: ${NAME}
	@echo "\n${BLUE}--- ${NAME} is up to date! ---${DEFAULT}"

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re